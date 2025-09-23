#include "i2c-lcd-baremetal-f4.h"

// Hàm delay đơn giản (chỉ mang tính tương đối)
void delay_ms_f4(uint32_t ms) {
    volatile uint32_t i;
    // Vòng lặp này được điều chỉnh cho F401RE chạy ở clock cao hơn
    for (i = 0; i < (ms * 4000); i++);
}

// ---- CÁC HÀM I2C MỨC THẤP CHO STM32F4 ----

void i2c_init(void) {
    // 1. Cấp clock cho GPIOB và I2C1
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // Cấp clock cho GPIOB trên bus AHB1
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN; // Cấp clock cho I2C1 trên bus APB1

    // 2. Cấu hình chân PB8 (SCL) và PB9 (SDA)
    // Đặt PB8, PB9 vào chế độ Alternate Function (10)
    GPIOB->MODER &= ~((3U << (8*2)) | (3U << (9*2))); // Xóa cấu hình cũ của PB8, PB9
    GPIOB->MODER |=  ((2U << (8*2)) | (2U << (9*2))); // Đặt chế độ AF

    // Đặt kiểu Output là Open-drain
    GPIOB->OTYPER |= (1U << 8) | (1U << 9);

    // Đặt tốc độ chân là High speed
    GPIOB->OSPEEDR |= (3U << (8*2)) | (3U << (9*2));

    // Cấu hình Alternate Function cho PB8 và PB9 là I2C1 (AF4)
    // AFR[1] dùng cho các chân từ 8 đến 15
    GPIOB->AFR[1] &= ~((0xFU << (0*4)) | (0xFU << (1*4))); // Xóa cấu hình AF cũ cho PB8, PB9
    GPIOB->AFR[1] |=  ((4U << (0*4)) | (4U << (1*4)));    // Đặt AF4 cho PB8, PB9

    // 3. Cấu hình ngoại vi I2C1
    I2C1->CR1 |= I2C_CR1_SWRST;   // Reset I2C
    I2C1->CR1 &= ~I2C_CR1_SWRST;  // Thoát reset

    // Tần số bus APB1 (mặc định cho F401RE là 42MHz)
    I2C1->CR2 = 42;

    // Cài đặt tốc độ SCL 100KHz (Standard Mode)
    I2C1->CCR = 210;

    // Cấu hình thời gian rise tối đa
    I2C1->TRISE = 43;

    I2C1->CR1 |= I2C_CR1_PE; // Bật ngoại vi I2C1
}

void i2c_start(void) {
    I2C1->CR1 |= I2C_CR1_ACK;
    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB));
}

void i2c_stop(void) {
    I2C1->CR1 |= I2C_CR1_STOP;
    while (I2C1->SR2 & I2C_SR2_MSL);
}

void i2c_write(uint8_t data) {
    while (!(I2C1->SR1 & I2C_SR1_TXE));
    I2C1->DR = data;
    while (!(I2C1->SR1 & I2C_SR1_BTF));
}

void i2c_send_address(uint8_t address) {
    I2C1->DR = address;
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    // Xóa cờ ADDR bằng cách đọc SR1 và SR2, đây là yêu cầu của phần cứng
    volatile uint32_t temp = I2C1->SR2;
    (void)temp; // Dòng này để tránh cảnh báo "unused variable"
}

// ---- CÁC HÀM LCD MỨC CAO (Không thay đổi) ----
void lcd_write_i2c(uint8_t data) {
    i2c_start();
    i2c_send_address(SLAVE_ADDRESS_LCD << 1);
    i2c_write(data);
    i2c_stop();
}

void lcd_send_4bits(uint8_t data, uint8_t flags) {
    uint8_t packet = (data & 0xF0) | flags | 0x08; // 0x08 là bit đèn nền
    lcd_write_i2c(packet | 0x04); // E = 1
    delay_ms_f4(1);
    lcd_write_i2c(packet & ~0x04); // E = 0
    delay_ms_f4(1);
}

void lcd_send_cmd(char cmd) {
    uint8_t high_nibble = cmd & 0xF0;
    uint8_t low_nibble = (cmd << 4) & 0xF0;
    lcd_send_4bits(high_nibble, 0x00); // RS=0
    lcd_send_4bits(low_nibble, 0x00);  // RS=0
}

void lcd_send_data(char data) {
    uint8_t high_nibble = data & 0xF0;
    uint8_t low_nibble = (data << 4) & 0xF0;
    lcd_send_4bits(high_nibble, 0x01); // RS=1
    lcd_send_4bits(low_nibble, 0x01);  // RS=1
}

void lcd_init(void) {
    i2c_init();
    delay_ms_f4(50);
    lcd_send_4bits(0x30, 0x00);
    delay_ms_f4(5);
    lcd_send_4bits(0x30, 0x00);
    delay_ms_f4(1);
    lcd_send_4bits(0x20, 0x00);
    delay_ms_f4(1);
    lcd_send_cmd(0x28);
    lcd_send_cmd(0x0C);
    lcd_send_cmd(0x06);
    lcd_send_cmd(0x01);
    delay_ms_f4(2);
}

void lcd_send_string(char *str) {
    while (*str) {
        lcd_send_data(*str++);
    }
}

void lcd_clear(void) {
    lcd_send_cmd(0x01);
    delay_ms_f4(2);
}

void lcd_set_cursor(int row, int col) {
    uint8_t address = (row == 0) ? (0x80 + col) : (0xC0 + col);
    lcd_send_cmd(address);
}

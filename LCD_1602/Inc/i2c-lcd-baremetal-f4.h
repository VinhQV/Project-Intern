/*
 * i2c-lcd-baremetal-f4.h
 *
 *  Created on: Sep 4, 2025
 *      Author: vinhv
 */

#ifndef I2C_LCD_BAREMETAL_F4_H_
#define I2C_LCD_BAREMETAL_F4_H_

#include "stm32f401re.h" // Thư viện thanh ghi cho dòng STM32F4

#define SLAVE_ADDRESS_LCD 0x27 // Địa chỉ I2C của module

// Khai báo các hàm
void lcd_init(void);
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_send_string(char *str);
void lcd_clear(void);
void lcd_set_cursor(int row, int col);

#endif /* I2C_LCD_BAREMETAL_F4_H_ */

#include <Wire.h>               // Thư viện giao tiếp I2C
#include <LiquidCrystal_I2C.h>  // Thư viện giao tiếp LCD theo chuẩn I2C
#include "DHTesp.h"             // Thư viện cho cảm biến DHT

// --- Cấu hình ---
LiquidCrystal_I2C lcd(0x27, 16, 2); // Khai báo địa chỉ và thông tin LCD
DHTesp dht;
const int dhtPin = 23; // Chân dữ liệu của cảm biến DHT
const int ledBluePin = 4;  //D4
const int ledRedPin = 5;    //D5
// Biến dùng cho việc đọc cảm biến theo chu kỳ
unsigned long previousMillis = 0;
const long interval = 2000; // Đọc cảm biến mỗi 2 giây

// Mảng byte biểu diễn ký tự độ (°)
byte degree[8] = {
  0b00110,
  0b01001,
  0b01001,
  0b00110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
}; 

void setup() {
  Serial.begin(115200);
  pinMode(ledBluePin, OUTPUT);   
  pinMode(ledRedPin, OUTPUT);
  // Khởi tạo cảm biến DHT11 trên chân dhtPin
  dht.setup(dhtPin, DHTesp::DHT11);
  
  // Khởi tạo màn hình LCD
  lcd.init();
  lcd.backlight();
  
  // Hiển thị màn hình chào
  lcd.setCursor(4, 0); // Đặt con trỏ ở giữa dòng 0
  lcd.print("Welcome!");
  delay(2000); // Hiển thị trong 2 giây
  lcd.clear(); // Xóa màn hình chào
  
  // In các nhãn cố định lên màn hình
  lcd.setCursor(0, 0);
  lcd.print("T:      oC");

  lcd.setCursor(0, 1); // Chuyển xuống dòng thứ 2
  lcd.print("H:      %");
}

void loop() {
  // Chỉ đọc cảm biến sau mỗi khoảng thời gian 'interval'
  if (millis() - previousMillis >= interval) {
    previousMillis = millis(); // Cập nhật lại thời gian

    // Đọc giá trị từ cảm biến
    float humidity = dht.getHumidity();
    float temperature = dht.getTemperature();

    // Kiểm tra xem việc đọc có thành công không
    if (dht.getStatus() == DHTesp::ERROR_NONE) {
      // --- Hiển thị nhiệt độ ---
      lcd.setCursor(2, 0);  // Đặt con trỏ sau chữ "T:"
      lcd.print(temperature, 1); // In giá trị nhiệt độ với 1 chữ số thập phân
      lcd.print(" "); // In một khoảng trắng để xóa ký tự cũ nếu có

      // --- Hiển thị độ ẩm ---
      lcd.setCursor(2, 1);  // Đặt con trỏ sau chữ "H:"
      lcd.print(humidity, 1);    // In giá trị độ ẩm với 1 chữ số thập phân
      lcd.print(" "); // In một khoảng trắng để xóa ký tự cũ
      
      // In ra Serial Monitor để debug
      Serial.printf("Temperature: %.1f°C, Humidity: %.1f%%\n", temperature, humidity);

      if (temperature < 30.0) {
        digitalWrite(ledBluePin, HIGH); 
        digitalWrite(ledRedPin, LOW);
      } else {
        digitalWrite(ledBluePin, LOW);  
        digitalWrite(ledRedPin, HIGH);
      }
    } else {
      Serial.println("Failed to read from DHT sensor");
    }
  }
}
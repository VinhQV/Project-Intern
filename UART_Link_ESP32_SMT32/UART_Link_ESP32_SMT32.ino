const int LED_PIN = 4;
const int BUTTON_PIN = 5;

// Khai báo cổng Serial để giao tiếp với STM32
// Serial2 sử dụng chân GPIO16 (RX2) và GPIO17 (TX2)
HardwareSerial stmSerial(2);

bool ledState = LOW;

// Biến để lưu trạng thái của nút nhấn
int buttonState;
int lastButtonState = HIGH; // Giả sử nút không được nhấn ban đầu (do dùng INPUT_PULLUP)

// Biến cho việc chống dội phím
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 da san sang. Cho lenh 0x10 tu STM32 de bat/tat LED D4.");
  stmSerial.begin(9600, SERIAL_8N1, 16, 17);

  pinMode(LED_PIN, OUTPUT);
  // Sử dụng INPUT_PULLUP để kích hoạt điện trở kéo lên nội bộ của ESP32.
  // Bạn chỉ cần nối nút nhấn giữa chân D5 và GND mà không cần điện trở ngoài.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  // --- PHẦN CODE CÓ SẴN: Lắng nghe lệnh từ STM32 ---
  if (stmSerial.available() > 0)
  {
    byte receivedData = stmSerial.read();

    if (receivedData == 0x10) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);

      if (ledState == HIGH) {
        Serial.println("Nhan duoc 0x10 -> LED D4 BAT");
      } else {
        Serial.println("Nhan duoc 0x10 -> LED D4 TAT");
      }
    }
  }

  // --- PHẦN CODE MỚI: Kiểm tra nút nhấn và gửi lệnh đến STM32 ---
  // Đọc trạng thái hiện tại của nút nhấn
  int reading = digitalRead(BUTTON_PIN);

  // Nếu trạng thái nút nhấn thay đổi (do nhiễu hoặc do nhấn thật)
  if (reading != lastButtonState) {
    // Reset bộ đếm thời gian chống dội
    lastDebounceTime = millis();
  }

  // Nếu trạng thái nút nhấn đã ổn định trong một khoảng thời gian (debounceDelay)
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Và nếu trạng thái đó khác với trạng thái đã xử lý trước đó
    if (reading != buttonState) {
      buttonState = reading;

      // Nếu nút được nhấn (trạng thái chuyển sang LOW vì dùng INPUT_PULLUP)
      if (buttonState == LOW) {
        // Gửi mã 0x11 qua Serial cho STM32
        stmSerial.write(0x11);
        Serial.println("Nhan nut -> Da gui 0x11 cho STM32");
      }
    }
  }
  
  // Cập nhật trạng thái cuối cùng của nút nhấn
  lastButtonState = reading;
}
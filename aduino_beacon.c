#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); // RX, TX 핀

const long interval = 5 * 60 * 1000;
unsigned long previousMillis = 0;

void setup() {
  bluetooth.begin(9600); // 블루투스 모듈 초기화
}

void loop() {
  unsigned long currentMillis = millis(); // 현재시간 측정
  if (currentMillis - previousMillis >= interval) { // 일정 시간이 지나면
    previousMillis = currentMillis; // 이전 시간 갱신
    bluetooth.print("Hello"); // "Hello" 문자열을 전송
  }
}

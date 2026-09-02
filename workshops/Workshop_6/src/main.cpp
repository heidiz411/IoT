/* ---------------------------------------------------------------
 *  File    : main.cpp   (Workshop_6)
 *  ใบงานที่ 6 : การเปิด-ปิดหลอดไฟฟ้า โดยการตรวจจับความเข้มแสง
 *  ฉบับจำลองการทำงานด้วย Wokwi + Visual Studio Code
 *  บอร์ด   : ESP32 DevKit V1  (ใช้แทน NodeMCU ESP8266)
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
#include <Arduino.h>

int sensorPin = A0;                 // A0 ของ ESP32 = GPIO36 (ขา VP) ต่อกับ AO ของ LDR
unsigned int sensorValue = 0;       // ค่าเริ่มต้น = 0
const int LED_PIN = 13;             // GPIO13 (ขา D13) ต่อกับหลอด LED
int THRESHOLD = 1600;               // เกณฑ์ตัดสิน (ต้องปรับตามค่าที่วัดได้จริงในข้อ 10)

void setup() {
  pinMode(LED_PIN, OUTPUT);         // กำหนดขา GPIO13 ส่งค่าออกเป็น output
  Serial.begin(115200);
  Serial.println("Workshop 6 : LDR Light Sensor -> LED");
}

void loop() {
  sensorValue = analogRead(sensorPin);   // ค่าที่อ่านได้จากเซนเซอร์ (0-4095 บน ESP32)

  if (sensorValue < THRESHOLD) {         // ถ้าค่าที่อ่านได้น้อยกว่าเกณฑ์
    digitalWrite(LED_PIN, HIGH);         // LED on
  }
  else {
    digitalWrite(LED_PIN, LOW);          // LED off
  }

  Serial.print(sensorValue, DEC);        // แสดงค่าที่อ่านได้ทาง Serial Monitor
  Serial.println("");
  delay(500);
}

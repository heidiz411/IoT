/* ---------------------------------------------------------------
 *  File    : main.cpp   (Workshop_8.1)
 *  ใบงานที่ 8 ตอนที่ 1 : การตรวจจับการรั่วไหลของแก๊สด้วย MQ-2
 *  ฉบับจำลองการทำงานด้วย Wokwi + Visual Studio Code
 *  บอร์ด   : ESP32 DevKit V1  (ใช้แทน NodeMCU ESP8266)
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
#include <Arduino.h>

#define LED        16    // GPIO16 (ขา RX2) -> LED แจ้งเตือน   [เดิม D0]
#define BUZZER      5    // GPIO5  (ขา D5)  -> บัซเซอร์         [เดิม D1]
#define GASsensor  A0    // A0 = GPIO36 (ขา VP) <- AO ของ MQ-2

int ValuaBegin = 1200;   // ค่าเกณฑ์การแจ้งเตือน (300 ของสเกล 10 บิต x 4)

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(GASsensor, INPUT);
  Serial.begin(115200);
  Serial.println("Workshop 8.1 : MQ-2 Gas Leak Alarm");
}

void loop() {
  int analogSensor = analogRead(GASsensor);

  Serial.print("GAS Value: ");
  Serial.println(analogSensor);      // ต้นฉบับใช้ print จึงพิมพ์ต่อกันเป็นบรรทัดเดียว

  if (analogSensor > ValuaBegin) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000, 200);         // บัซเซอร์ส่งเสียงเตือนแก๊สรั่ว 1000 Hz นาน 200 ms
  }
  else {
    digitalWrite(LED, LOW);
  }

  delay(500);
}

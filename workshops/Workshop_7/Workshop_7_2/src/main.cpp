/* ---------------------------------------------------------------
 *  File    : main.cpp   (Workshop_8.2)
 *  ใบงานที่ 8 ตอนที่ 2 : การวัดระยะทางด้วยอัลตราโซนิค HC-SR04
 *  ฉบับจำลองการทำงานด้วย Wokwi + Visual Studio Code
 *  บอร์ด   : ESP32 DevKit V1  (ใช้แทน NodeMCU ESP8266)
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
#include <Arduino.h>

const int pingPin = 5;   // TRIG : GPIO5 (ขา D5)  [เดิม D1]
const int inPin   = 4;   // ECHO : GPIO4 (ขา D4)  [เดิม D2]

long microsecondsToCentimeters(long microseconds);

void setup() {
  Serial.begin(115200);
  pinMode(pingPin, OUTPUT);
  pinMode(inPin, INPUT);
  Serial.println("Workshop 8.2 : HC-SR04 Distance Meter");
}

void loop() {
  long duration, cm;

  digitalWrite(pingPin, LOW);        // เคลียร์สัญญาณให้สะอาดก่อนเริ่มวัด
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);       // ส่งพัลส์กระตุ้น
  delayMicroseconds(10);             // ต้องกว้างอย่างน้อย 10 ไมโครวินาที
  digitalWrite(pingPin, LOW);

  duration = pulseIn(inPin, HIGH);   // วัดความกว้างของพัลส์ที่สะท้อนกลับ
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.println(" cm");
  delay(200);
}

long microsecondsToCentimeters(long microseconds) {
  // ความเร็วเสียงในอากาศประมาณ 340 เมตร/วินาที หรือ 29 ไมโครวินาที/เซนติเมตร
  // เวลาที่วัดได้คือระยะทางไป-กลับ ดังนั้นระยะทางจริงคือครึ่งหนึ่งของที่วัดได้
  return microseconds / 29 / 2;
}

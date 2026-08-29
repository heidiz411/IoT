/* ---------------------------------------------------------------
 *  File    : main.cpp   (Workshop_5)
 *  ใบงานที่ 5 : การควบคุมอุปกรณ์ไฟฟ้า โดยการตรวจจับการเคลื่อนไหว
 *  ฉบับจำลองการทำงานด้วย Wokwi + Visual Studio Code
 *  บอร์ด   : ESP32 DevKit V1  (ใช้แทน NodeMCU ESP8266 เนื่องจาก
 *            Wokwi ยังไม่รองรับการจำลองชิป ESP8266)
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
#include <Arduino.h>

#define LED 16          // GPIO16 (ขา RX2 บนบอร์ด) -> LED แสดงสถานะ  [เดิม D0 ของ NodeMCU]
int Status = 12;        // GPIO12 (ขา D12)         -> IN ของรีเลย์    [เดิม D6 ของ NodeMCU]
int sensor = 13;        // GPIO13 (ขา D13)         <- OUT ของ PIR     [เดิม D7 ของ NodeMCU]

void setup() {
  Serial.begin(115200);              // *** ต้นฉบับใบงานไม่มีบรรทัดนี้ ถ้าไม่ใส่จะไม่เห็นข้อความใน Serial Monitor ***
  pinMode(LED, OUTPUT);              // กำหนด LED เป็น output
  pinMode(sensor, INPUT);            // กำหนด sensor เป็น input
  pinMode(Status, OUTPUT);           // กำหนดขาควบคุมรีเลย์เป็น output
  digitalWrite(LED, LOW);
  digitalWrite(Status, LOW);
  Serial.println("Workshop 5 : PIR Motion Detection -> Relay + LED");
}

void loop() {
  long state = digitalRead(sensor);  // อ่านค่าจากเซนเซอร์ PIR

  if (state == HIGH) {
    digitalWrite(Status, HIGH);            // สั่งรีเลย์ทำงาน (หลอดโหลดติด)
    Serial.println("Motion detected!");    // ตรวจพบการเคลื่อนไหวของมนุษย์
    digitalWrite(LED, HIGH);               // หลอดไฟติด
    delay(1000);
  }
  else {
    digitalWrite(Status, LOW);             // สั่งรีเลย์หยุดทำงาน (หลอดโหลดดับ)
    Serial.println("Motion absent!");      // ไม่มีการเคลื่อนไหว
    digitalWrite(LED, LOW);                // หลอดไฟดับ
    delay(1000);
  }
}

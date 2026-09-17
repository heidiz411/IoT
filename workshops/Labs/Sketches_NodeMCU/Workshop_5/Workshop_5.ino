/* ---------------------------------------------------------------
 *  ใบงานที่ 5 : การควบคุมอุปกรณ์ไฟฟ้า โดยการตรวจจับการเคลื่อนไหว
 *  บอร์ด : NodeMCU 1.0 (ESP-12E Module)
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
#define LED     D0        // GPIO16 -> บล็อก LED 3
int Status  = D6;         // GPIO12 -> ขา IN2 ของรีเลย์
int sensor  = D7;         // GPIO13 <- ขา O/P ของ PIR

void setup() {
  Serial.begin(115200);   // ต้นฉบับไม่มีบรรทัดนี้ ทำให้ไม่เห็นข้อความบน Serial Monitor
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(Status, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(Status, LOW);
  Serial.println("Workshop 5 : PIR Motion Detection");
  Serial.println("รอ PIR อุ่นเครื่อง 30 วินาที...");
  delay(30000);           // PIR ต้องใช้เวลาปรับสภาพก่อนเริ่มทำงานจริง
  Serial.println("พร้อมตรวจจับ");
}

void loop() {
  long state = digitalRead(sensor);

  if (state == HIGH) {
    digitalWrite(Status, HIGH);          // สั่งรีเลย์ทำงาน
    Serial.println("Motion detected!");  // ตรวจพบการเคลื่อนไหว
    digitalWrite(LED, HIGH);             // หลอดไฟติด
    delay(1000);
  }
  else {
    digitalWrite(Status, LOW);
    Serial.println("Motion absent!");    // ไม่มีการเคลื่อนไหว
    digitalWrite(LED, LOW);              // หลอดไฟดับ
    delay(1000);
  }
}

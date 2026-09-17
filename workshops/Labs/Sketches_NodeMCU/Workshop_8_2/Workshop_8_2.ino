/* ---------------------------------------------------------------
 *  ใบงานที่ 8 ตอนที่ 2 : การวัดระยะทางด้วยอัลตราโซนิค HC-SR04
 *  บอร์ด : NodeMCU 1.0 (ESP-12E Module)
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
const int pingPin = D1;    // GPIO5 -> ขา TRIG
const int inPin   = D2;    // GPIO4 <- ขา ECHO (ผ่านวงจรแบ่งแรงดัน)

long microsecondsToCentimeters(long microseconds);

void setup() {
  Serial.begin(115200);
  pinMode(pingPin, OUTPUT);          // ต้นฉบับกำหนดไว้ใน loop() ซึ่งไม่จำเป็น
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

  duration = pulseIn(inPin, HIGH, 30000);   // กำหนด timeout 30 ms กันโปรแกรมค้าง
  cm = microsecondsToCentimeters(duration);

  if (duration == 0) {
    Serial.println("วัดไม่ได้ (ไกลเกินไปหรือไม่มีสัญญาณสะท้อน)");
  } else {
    Serial.print(cm);
    Serial.println(" cm");
  }
  delay(200);
}

long microsecondsToCentimeters(long microseconds) {
  // ความเร็วเสียงในอากาศประมาณ 340 เมตร/วินาที หรือ 29 ไมโครวินาที/เซนติเมตร
  // เวลาที่วัดได้คือระยะทางไป-กลับ ระยะทางจริงจึงเป็นครึ่งหนึ่งของที่วัดได้
  return microseconds / 29 / 2;
}

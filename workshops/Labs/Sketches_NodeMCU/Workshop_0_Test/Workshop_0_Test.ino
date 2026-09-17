/* ---------------------------------------------------------------
 *  ใบงานที่ 0 : โปรแกรมทดสอบบอร์ด NodeMCU
 *  ตรวจสอบว่าอัปโหลดโปรแกรมได้ และ Serial Monitor ทำงานถูกต้อง
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
int count = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // ไฟ LED บนบอร์ด อยู่ที่ขา D4 (GPIO2)
  Serial.begin(115200);
  delay(500);
  Serial.println();
  Serial.println("=================================");
  Serial.println(" NodeMCU พร้อมใช้งาน");
  Serial.print(" ความเร็ว Serial : ");
  Serial.println(115200);
  Serial.println("=================================");
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);    // ไฟบนบอร์ดเป็นแบบ active-LOW จึงติดเมื่อสั่ง LOW
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);   // ดับ
  delay(500);

  count++;
  Serial.print("ทดสอบครั้งที่ ");
  Serial.println(count);
}

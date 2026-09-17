/* ---------------------------------------------------------------
 *  ใบงานที่ 8 ตอนที่ 1 : การตรวจจับการรั่วไหลของแก๊สด้วย MQ-2
 *  บอร์ด : NodeMCU 1.0 (ESP-12E Module)
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
#define LED        D0      // GPIO16 -> บล็อก LED 1
#define BUZZER     D1      // GPIO5  -> ขา I/P ของบัซเซอร์
#define GASsensor  A0      // ขา A0  <- ขา O/P ของ MQ-2 (ผ่านวงจรแบ่งแรงดัน)

int ValuaBegin = 300;      // ค่าเกณฑ์การแจ้งเตือน (สเกล 0-1023)

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(GASsensor, INPUT);
  Serial.begin(115200);
  Serial.println("Workshop 8.1 : MQ-2 Gas Leak Alarm");
  Serial.println("อุ่นฮีทเตอร์ 20 วินาทีก่อนเริ่มวัดค่า...");
  delay(20000);            // MQ-2 ต้องจ่ายไฟอุ่นฮีทเตอร์ก่อนจึงจะอ่านค่าได้น่าเชื่อถือ
  Serial.println("พร้อมตรวจวัด");
}

void loop() {
  int analogSensor = analogRead(GASsensor);

  Serial.print("GAS Value: ");
  Serial.println(analogSensor);      // ต้นฉบับใช้ print จึงพิมพ์ต่อกันเป็นบรรทัดเดียว

  if (analogSensor > ValuaBegin) {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000, 200);         // เสียงเตือน 1000 Hz นาน 200 ms
  }
  else {
    digitalWrite(LED, LOW);
  }

  delay(500);
}

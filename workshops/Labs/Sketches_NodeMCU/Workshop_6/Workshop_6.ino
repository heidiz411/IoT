/* ---------------------------------------------------------------
 *  ใบงานที่ 6 : การเปิด-ปิดหลอดไฟฟ้า โดยการตรวจจับความเข้มแสง
 *  บอร์ด : NodeMCU 1.0 (ESP-12E Module)
 *  คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด
 * --------------------------------------------------------------- */
int sensorPin = A0;              // ขา A0 ต่อกับจุด LDR P2
unsigned int sensorValue = 0;
const int LED_PIN = D7;          // GPIO13 -> บล็อก LED 4
int THRESHOLD = 400;             // ค่าเริ่มต้น ต้องปรับตามที่วัดได้จริงในข้อ 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Workshop 6 : LDR Light Sensor");
}

void loop() {
  sensorValue = analogRead(sensorPin);   // ค่าที่อ่านได้ 0-1023 (ADC 10 บิต)

  if (sensorValue < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);         // LED on
  }
  else {
    digitalWrite(LED_PIN, LOW);          // LED off
  }

  Serial.print(sensorValue, DEC);
  Serial.println("");
  delay(500);
}

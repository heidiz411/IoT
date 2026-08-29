# Workshop 5 — การควบคุมอุปกรณ์ไฟฟ้าโดยการตรวจจับการเคลื่อนไหว (Wokwi + VS Code)

คณะเทคโนโลยีสารสนเทศ มหาวิทยาลัยราชภัฏร้อยเอ็ด

## โครงสร้างไฟล์

```
Workshop_5/
├── platformio.ini      ← ตั้งค่าบอร์ดและ framework
├── wokwi.toml          ← บอก Wokwi ว่าเฟิร์มแวร์อยู่ที่ไหน
├── diagram.json        ← วงจรจำลอง (ESP32 + PIR + Relay + LED)
├── src/
│   └── main.cpp        ← โค้ดที่ต้องเขียน/แก้ไข
└── README.md
```

## ขั้นตอนใช้งานอย่างย่อ

1. ติดตั้งส่วนขยายใน VS Code: **PlatformIO IDE** และ **Wokwi Simulator**
2. `Ctrl+Shift+P` → `Wokwi: Request a New License` → กด **Get Your License** → กลับมา VS Code
3. เปิดโฟลเดอร์ `Workshop_5` ด้วย VS Code (`File → Open Folder…`)
4. กดปุ่ม **Build** (✓) ของ PlatformIO หรือใช้คำสั่ง `pio run` รอจนขึ้น `SUCCESS`
5. `Ctrl+Shift+P` → `Wokwi: Start Simulator`
6. คลิกที่เซนเซอร์ PIR ในหน้าจำลอง → กด **Simulate Motion** แล้วสังเกตผล

## หมายเหตุสำคัญ

* Wokwi **ยังไม่รองรับ ESP8266 (NodeMCU)** ใบงานนี้จึงใช้ **ESP32 DevKit V1** แทน
  โดยคงหมายเลข GPIO เดิมไว้ทั้งหมด (16 / 12 / 13) เพื่อให้เทียบกับบอร์ดจริงได้ตรง ๆ
* ถ้าหลอด LAMP ติดสลับกับที่คาดไว้ ให้ย้ายสายจากขา `NO` ไป `NC` ของรีเลย์
  หรือแก้ค่า `transistor` ใน `diagram.json` ระหว่าง `"npn"` ↔ `"pnp"`
* ห้ามลบไฟล์ `wokwi.toml` และ `diagram.json` — ถ้าไม่มี Wokwi จะไม่ยอมเริ่มจำลอง

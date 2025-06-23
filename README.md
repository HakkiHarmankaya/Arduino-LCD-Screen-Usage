# 📏 Arduino #14: 16x2 LCD ile Dijital Metre Yapımı

Bu projede, **16x2 LCD ekran** ve **HC-SR04 ultrasonik mesafe sensörü** kullanarak bir **dijital mesafe ölçüm cihazı** tasarlıyoruz.  
Mesafe ölçüm verisi LCD ekranda gerçek zamanlı olarak gösterilir.

🔗 [Web Siteme Bakmak İçin Tıkla](https://www.hakkiharmankaya.com/)  
🔗 [Tinkercad Tasarımına Göz At](https://www.tinkercad.com/things/23y7GRD98lX?sharecode=p3PzmngGrEZMuo2eAOymWmK0wLXSC27fXGW7rBglq_0)

---

## 🧰 Gerekli Malzemeler

- 1 adet **16x2 LCD ekran**
- 1 adet **HC-SR04 Ultrasonik Mesafe Sensörü**
- 1 adet **potansiyometre** (LCD kontrast ayarı için)
- 1 adet **Arduino**
- **Jumper kabloları**

---

## ⚙️ Adım Adım Devre Kurulumu

### 🔹 Adım 1: Devreyi Kurun

**LCD Bağlantıları**:

| LCD Pin | Arduino Bağlantısı |
|---------|--------------------|
| 1 (GND) | GND                |
| 2 (VCC) | 5V                 |
| 3 (VO)  | Potansiyometre Orta Bacak |
| 4 (RS)  | D12                |
| 5 (RW)  | GND                |
| 6 (EN)  | D11                |
| 11 (D4) | D5                 |
| 12 (D5) | D4                 |
| 13 (D6) | D3                 |
| 14 (D7) | D2                 |
| 15 (LED+) | 5V              |
| 16 (LED-) | GND              |

**HC-SR04 Bağlantıları**:

- **VCC** → **5V**
- **GND** → **GND**
- **Trig** → **D6**
- **Echo** → **D7**

**Potansiyometre**:

- **Sağ bacak** → **GND**
- **Sol bacak** → **5V**
- **Orta bacak** → **LCD'nin VO (3. pinine)**

---

## 🔹 Adım 2: Arduino Kodunu Yazın ve Yükleyin

```cpp
#include <LiquidCrystal.h>

int tPin = 6; // Trig pin
int ePin = 7; // Echo pin
int sure;
int uzaklik;

int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(tPin, OUTPUT);
  pinMode(ePin, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(tPin, LOW);
  delayMicroseconds(2);
  digitalWrite(tPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin, LOW);

  sure = pulseIn(ePin, HIGH);
  uzaklik = sure * 0.0345 / 2;

  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Uzaklik:");
  lcd.setCursor(0, 1);
  lcd.print(uzaklik);
  lcd.print(" cm");

  Serial.println(uzaklik);
}

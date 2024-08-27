#include <LiquidCrystal.h>


int tPin = 6; //Sonar trig pini.
int ePin = 7; //Sonar echo pini.
int sure; //Gerekli değişkenler.
int uzaklik; //Gerekli değişkenler.
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //LCD ekran pinleri tanımı.
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  pinMode(tPin, OUTPUT);
  pinMode(ePin, INPUT);
  lcd.begin(16,2); //Ekran boyutu tanımı.
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(tPin, LOW);
  delayMicroseconds(2);
  digitalWrite(tPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin, LOW);

  sure = pulseIn(ePin, HIGH);
  
  uzaklik = sure*0.0345/2;

  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Uzaklik:");
  lcd.setCursor(0,1);
  lcd.print(uzaklik);
  lcd.print(" cm");
  Serial.println(uzaklik);
  Serial.println(sure);
}

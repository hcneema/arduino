#include <LiquidCrystal.h>

LiquidCrystal lcd(22, 23, 24, 25, 26, 27);

void setup() {
  delay(500);
  lcd.begin(16, 2);
  delay(200);
  lcd.clear();
  delay(200);
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  delay(200);
  lcd.setCursor(0, 1);
  lcd.print("LCD Working!");
}

void loop() {}

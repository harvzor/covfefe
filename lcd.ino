#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setupLCD() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.write("LCD ready");
}

void printOut(String str) {
  lcd.clear();
  
  lcd.setCursor(0, 1);
  lcd.write(str.c_str());
  Serial.println(str);
}

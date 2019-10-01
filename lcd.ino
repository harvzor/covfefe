#include <LiquidCrystal.h>

#define LCD_LENGTH 16
#define LCD_HEIGHT 2

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setupLCD() {
  lcd.begin(LCD_LENGTH, LCD_HEIGHT);

  printOutLn("LCD Ready");
}

void printOut(String str) {
  lcd.clear();

  if (str.length() > LCD_LENGTH) {
    printOutLn(str.substring(0, LCD_LENGTH), 0);
    printOutLn(str.substring(LCD_LENGTH), 1);
  } else {
    printOutLn(str);
  }
}
void printOutLn(String str) {
  lcd.clear();
  
  printOutLn(str, 1);
}

void printOutLn(String str, int row) {
  lcd.setCursor(0, row);
  lcd.write(str.c_str());
  Serial.println(str);
}

void printOutLn(String str, int row, bool clear) {
  if (clear) {
    lcd.clear();
  }
  
  printOutLn(str, row);
}

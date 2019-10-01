#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() {
  Serial.begin(9600);  
  Serial.println("Starting...");
  Serial.println("Started!");

  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.write("Okay!");

  setupButtons();
}

void setupButtons() {
  pinMode(2, INPUT);
}

void loop() {
  int buttonState = digitalRead(2);

  Serial.println(buttonState);
}

#include <LiquidCrystal.h>
#include <JC_Button.h>

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

Button button1(2);

void setupButtons() {
  //pinMode(2, INPUT);

  button1.begin();
}

void loop() {
  button1.read();
  
  if (button1.wasPressed()) {
    Serial.println("pressed!");
  }
}

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

unsigned int coffeeCount = 0;

Button buttonCoffee(2);

void setupButtons() {
  buttonCoffee.begin();
}

void readButtons() {
  buttonCoffee.read();
}

void loop() {
  readButtons();
  
  if (buttonCoffee.wasPressed()) {
    coffeeCount++;

    Serial.println("coffee!  " + String(coffeeCount));
  }
}

#include <LiquidCrystal.h>
#include <JC_Button.h>

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() {
  Serial.begin(9600);  
  Serial.println("Starting...");

  setupLCD();

  setupButtons();

  Serial.println("Started!");
}

unsigned int coffeeCount = 0;
unsigned int mateCount = 0;
unsigned int beerCount = 0;

Button buttonCoffee(2);
Button buttonMate(3);
Button buttonBeer(4);

void setupLCD() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.write("LCD ready");
}

void setupButtons() {
  buttonCoffee.begin();
  buttonMate.begin();
  buttonBeer.begin();
}

void readButtons() {
  buttonCoffee.read();
  buttonMate.read();
  buttonBeer.read();
}

void loop() {
  readButtons();
  
  if (buttonCoffee.wasPressed()) {
    coffeeCount++;

    printOut("Coffee: " + String(coffeeCount));
  }

  if (buttonMate.wasPressed()) {
    mateCount++;

    printOut("Mate: " + String(mateCount));
  }

  if (buttonBeer.wasPressed()) {
    beerCount++;

    printOut("Beer: " + String(beerCount));
  }
}

void printOut(String str) {
  lcd.clear();
  
  lcd.setCursor(0, 1);
  lcd.write(str.c_str());
  Serial.println(str);
}

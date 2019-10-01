#include <JC_Button.h>

unsigned int coffeeCount = 0;
unsigned int mateCount = 0;
unsigned int beerCount = 0;

unsigned long lastPressed = 0;
unsigned long lastPrinted = 0;

void setup() {
  Serial.begin(9600);  
  Serial.println("Starting...");

  setupLCD();

  setupButtons();

  Serial.println("Started!");
}

void loop() {
  buttonLoop();

  if (lastPressed != lastPrinted && lastPressed + 1000 < millis()) {
    printOut("Coffee: " + String(coffeeCount));

    lastPrinted = lastPressed;
  }

  delay(5);
}

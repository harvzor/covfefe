#include <JC_Button.h>

#define DRINKS_SIZE 3

int drunkCounts[DRINKS_SIZE] = {
  0,
  0,
  0
};

String drinkNames[DRINKS_SIZE] = {
  "Coffee",
  "Mate",
  "Beer"
};

unsigned long lastPressed = 0;
unsigned long lastPrinted = 0;
unsigned long lastDrinkPrinted = 0;

void setup() {
  Serial.begin(9600);  
  Serial.println("Starting...");

  setupLCD();

  setupButtons();

  Serial.println("Started!");
}

void loop() {
  buttonLoop();

  if (lastPressed + 1000 < millis() && lastPrinted + 1000 < millis()) {
    printOutLn(String(lastDrinkPrinted + 1) + "# " + drinkNames[lastDrinkPrinted] + ": " + String(drunkCounts[lastDrinkPrinted]));
    
    lastPrinted = millis();

    lastDrinkPrinted++;

    if (lastDrinkPrinted == DRINKS_SIZE) {
      lastDrinkPrinted = 0;
    }
  }

  delay(5);
}

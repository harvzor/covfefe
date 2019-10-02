#include <JC_Button.h>

#define DRINKS_SIZE 4

unsigned int drunkCounts[DRINKS_SIZE] = {
  0,
  0,
  0,
  0
};

String drinkNames[DRINKS_SIZE] = {
  "Coffee",
  "Mate",
  "Beer",
  "Orangina"
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

  if (lastPressed + 1000 < millis() && lastPrinted + 3000 < millis()) {
    printOutLn(
      getDrinkStats(lastDrinkPrinted),
      0,
      true
    );
    printOutLn(
      getDrinkStats(lastDrinkPrinted + 1 == DRINKS_SIZE ? 0 : lastDrinkPrinted + 1),
      1
    );
    
    lastPrinted = millis();

    lastDrinkPrinted++;

    if (lastDrinkPrinted == DRINKS_SIZE) {
      lastDrinkPrinted = 0;
    }
  }

  delay(5);
}

String getDrinkStats(int i) {
  return drinkNames[i] + ": " + String(drunkCounts[i]);
}

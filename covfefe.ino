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
    String toPrint = "";

    for (int i = 0; i < DRINKS_SIZE; i++) {
      toPrint += drinkNames[i] + ": ";
      toPrint += String(drunkCounts[i]) + " ";
    }
    
    printOut(toPrint);

    lastPrinted = lastPressed;
  }

  delay(5);
}

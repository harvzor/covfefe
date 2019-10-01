#include <JC_Button.h>

void setup() {
  Serial.begin(9600);  
  Serial.println("Starting...");

  setupLCD();

  setupButtons();

  Serial.println("Started!");
}


void loop() {
  buttonLoop();
}

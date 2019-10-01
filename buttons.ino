
Button buttonCoffee(2);
Button buttonMate(3);
Button buttonBeer(4);

void setupButtons() {
  buttonCoffee.begin();
  buttonMate.begin();
  buttonBeer.begin();
}

void buttonLoop() {
  readButtons();

  if (buttonCoffee.wasPressed()) {
    coffeeCount++;

    printOut("Coffee: " + String(coffeeCount));

    lastPressed = millis();
  }

  if (buttonMate.wasPressed()) {
    mateCount++;

    printOut("Mate: " + String(mateCount));

    lastPressed = millis();
  }

  if (buttonBeer.wasPressed()) {
    beerCount++;

    printOut("Beer: " + String(beerCount));

    lastPressed = millis();
  }
}

void readButtons() {
  buttonCoffee.read();
  buttonMate.read();
  buttonBeer.read();
}

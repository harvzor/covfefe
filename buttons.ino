unsigned int coffeeCount = 0;
unsigned int mateCount = 0;
unsigned int beerCount = 0;

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

void readButtons() {
  buttonCoffee.read();
  buttonMate.read();
  buttonBeer.read();
}

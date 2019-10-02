#include <JC_Button.h>
Button buttons[DRINKS_SIZE] = {
    Button(2),
    Button(3),
    Button(4),
    Button(5)
};

//int getIndexOfDrink(String drinkName) {
//    for (int i = 0; i < DRINKS_SIZE; i++) {
//        if (drinkNames[i] == drinkName) {
//            return i;
//        }
//    }
//}

void setupButtons() {
    for (int i = 0; i < DRINKS_SIZE; i++) {
        buttons[i].begin();
    }
}

void buttonLoop() {
    readButtons();

    for (int i = 0; i < DRINKS_SIZE; i++) {
        if (buttons[i].wasPressed()) {
            drunkCounts[i]++;

            printOutLn(drinkNames[i] + ": " + String(drunkCounts[i]));

            setDrunkCount(i);

            lastPressed = millis();
        }
    }
}

void readButtons() {
    for (int i = 0; i < DRINKS_SIZE; i++) {
        buttons[i].read();
    }
}

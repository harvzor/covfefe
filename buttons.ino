#include <JC_Button.h>

Button buttons[DRINKS_SIZE] = {
    Button(2, 25, true, true),
    Button(3, 25, true, true),
    Button(4, 25, true, true),
    Button(5, 25, true, true)
};

void setupButtons() {
    for (int i = 0; i < DRINKS_SIZE; i++) {
        buttons[i].begin();
    }
}

void buttonLoop() {
    readButtons();

    if (wasAllPressed()) {
        printOutLn("Resetting...");

        for (int i = 0; i < DRINKS_SIZE; i++) {
            drunkCounts[i] = 0;

            setDrunkCount(i);

            // Hack to ensure that the next loop doesn't trigger.
            buttons[i].wasPressed();
        }

        delay(1000);

        printOutLn("Reset!");

        lastPressed = millis();

        return;
    }

    for (int i = 0; i < DRINKS_SIZE; i++) {
        if (buttons[i].wasPressed()) {
            drunkCounts[i]++;

            printOutLn(drinkNames[i] + ": " + String(drunkCounts[i]));

            setDrunkCount(i);

            lastPressed = millis();

            return;
        }
    }
}

bool isAllPressed() {
    for (int i = 0; i < DRINKS_SIZE; i++) {
        if (!buttons[i].isPressed()) {
            return false;
        }
    }

    return true;
}

bool hasAllBeenPressed = false;

bool wasAllPressed() {
    if (hasAllBeenPressed) {
        for (int i = 0; i < DRINKS_SIZE; i++) {
            if (buttons[i].isPressed()) {
                return false;
            }
        }

        hasAllBeenPressed = false;

        return false;
    }

    if (isAllPressed()) {
        hasAllBeenPressed = true;

        return true;
    }

    return false;
}

void readButtons() {
    for (int i = 0; i < DRINKS_SIZE; i++) {
        buttons[i].read();
    }
}

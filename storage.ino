#include <EEPROMex.h>

int memoryAddresses[DRINKS_SIZE] = {
    EEPROM.getAddress(sizeof(int)),
};

void storageSetup() {
    // Avoid wearing out memory.
    EEPROM.setMaxAllowedWrites(10);

    for (int i = 0; i < DRINKS_SIZE; i++) {
        memoryAddresses[i] = EEPROM.getAddress(sizeof(int));

        drunkCounts[i] = EEPROM.readInt(memoryAddresses[i]);
    }
}

void setDrunkCount(int i) {
    bool successfulWrite = EEPROM.updateInt(memoryAddresses[i], drunkCounts[i]);

    Serial.println("Changing " + String(i) + " to " + String(drunkCounts[i]));

    if (!successfulWrite) {
        printOutLn("Max writes exceeded!", 0);
        printOutLn("Restart me!", 1);
    }
}

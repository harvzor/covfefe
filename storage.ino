#include <EEPROMex.h>

int memoryAddresses[DRINKS_SIZE] = {
    EEPROM.getAddress(sizeof(int)),
};

void storageSetup() {
    // Avoid wearing ou memory.
    EEPROM.setMaxAllowedWrites(100);

    for (int i = 0; i < DRINKS_SIZE; i++) {
        memoryAddresses[i] = EEPROM.getAddress(sizeof(int));

        drunkCounts[i] = EEPROM.readInt(memoryAddresses[i]);
    }

    // storageReset();
}

// void storageReset() {
//     for (int i = 0; i < DRINKS_SIZE; i++) {
//         EEPROM.updateInt(memoryAddresses[i], 0);
//     }
// }

void setDrunkCount(unsigned int i) {
    bool successfulWrite = EEPROM.updateInt(memoryAddresses[i], drunkCounts[i]);

    if (!successfulWrite) {
        printOutLn("Max writes exceeded!", 0);
        printOutLn("Restart me!", 1);
    }
}

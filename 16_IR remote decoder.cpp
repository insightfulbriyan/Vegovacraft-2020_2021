#define IR_RECEIVE_PIN 2
#include <Arduino.h>
#define MARK_EXCESS_MICROS    20 // 20 is recommended for the cheap VS1838 modules
#include <IRremote.h>
#define DEBUG_BUTTON_PIN   6


void setup() {
    pinMode(DEBUG_BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(115200);
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.print(F("Ready to receive IR signals at pin "));
    Serial.println(IR_RECEIVE_PIN);
    Serial.print(F("Debug button pin is "));
    Serial.println(DEBUG_BUTTON_PIN);
}

void loop() {
    if (IrReceiver.decode()) {
        IrReceiver.printIRResultShort(&Serial);
        Serial.println();
        IrReceiver.resume();
    }
    delay(200);
}

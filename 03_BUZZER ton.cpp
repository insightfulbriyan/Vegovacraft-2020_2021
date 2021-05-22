#include <Arduino.h>
#define BUZZ 11

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(BUZZ, OUTPUT);
}

void loop() {
    while(Serial.available()){
        char znak = Serial.read();
        if(znak == '1'){
            tone(BUZZ, 440, 500);
        }
    }
}
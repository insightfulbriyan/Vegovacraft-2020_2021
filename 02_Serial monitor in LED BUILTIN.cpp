#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    while (Serial.available()) {
        char znak = Serial.read();
        if (znak == '\n') continue;
        if(znak == '.'){
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.println("Prizgal");
            delay(200);
        }
        else if(znak == ' '){
            digitalWrite(LED_BUILTIN, LOW);
            Serial.println("Ugasnil");
            delay(200);
        }else {
            Serial.print("Neznan znak(");
            Serial.print(znak);
        }
    }
}
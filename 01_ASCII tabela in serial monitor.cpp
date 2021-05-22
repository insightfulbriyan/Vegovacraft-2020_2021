#include <Arduino.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    while (Serial.available()) {
        char znak = Serial.read();
        if (znak == '\n') continue;
        if ('A' <= znak && znak <= 'Z') {
            Serial.print("Poslal si veliko črko (");
            Serial.print(znak);
            Serial.println(").");
        }
        else if ('a' <= znak && znak <= 'z') {
            Serial.print("Poslal si malo črko (");
            Serial.print(znak);
            Serial.println(").");
        }
        else if ('0' <= znak && znak <= '9') {
            Serial.print("Poslal si številko (");
            Serial.print(znak);
            Serial.println(").");
        }
        else {
            Serial.println("Neznan znak");
        }
    }
}
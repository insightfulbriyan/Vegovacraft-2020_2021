#include <Arduino.h>
#define GUMB 3
#define LED 13

void setup(){
    pinMode(GUMB, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

bool stanje_prej = false;
bool stanje_zdej = false;

unsigned long shranjen_cas = 0;

bool led_utripa = false;

void loop(){
    stanje_zdej = !digitalRead(GUMB);

    if(stanje_zdej && stanje_zdej != stanje_prej){
        led_utripa = !led_utripa;
        if(!led_utripa){
            digitalWrite(LED, LOW);
        }
        Serial.println("Spremenil stanje");
        delay(50);
    }

    if(millis() > shranjen_cas + 1000 && led_utripa){
        digitalWrite(LED, !digitalRead(LED));
        shranjen_cas = millis();
    }

    stanje_prej = stanje_zdej;
}
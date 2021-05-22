#include <Arduino.h>
#define RDECA  3
#define ZELENA 5
#define MODRA  6

int zaporedje[] = {RDECA, ZELENA, MODRA};

void setup(){
    pinMode(RDECA, OUTPUT);
    pinMode(ZELENA, OUTPUT);
    pinMode(MODRA, OUTPUT);
}

void loop(){
    for(int i = 0; i < 3; i++){
        for(int j = 1; j >= 0; j--){
            digitalWrite(zaporedje[i], j);
            delay(1000);
        }
    }
}
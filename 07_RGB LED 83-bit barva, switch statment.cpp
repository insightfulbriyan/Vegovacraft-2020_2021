#include <Arduino.h>

#define RED 3
#define GREN 5
#define BLUE 6

int RGB[] = {RED, GREN, BLUE};
void setup(){
    pinMode(RED, OUTPUT);
    pinMode(GREN, OUTPUT);
    pinMode(BLUE, OUTPUT);


}

void led(int barva){
    switch (barva) {
        case 0:
            digitalWrite(RED, LOW);
            digitalWrite(GREN, LOW);
            digitalWrite(BLUE, LOW);
            break;
        case 1:
            digitalWrite(RED, HIGH);
            digitalWrite(GREN, LOW);
            digitalWrite(BLUE, LOW);
            break;
        case 2:
            digitalWrite(RED, HIGH);
            digitalWrite(GREN, HIGH);
            digitalWrite(BLUE, LOW);
            break;
        case 3:
            digitalWrite(RED, LOW);
            digitalWrite(GREN, HIGH);
            digitalWrite(BLUE, LOW);
            break;
        case 4:
            digitalWrite(RED, HIGH);
            digitalWrite(GREN, LOW);
            digitalWrite(BLUE, HIGH);
            break;
        case 5:
            digitalWrite(RED, LOW);
            digitalWrite(GREN, LOW);
            digitalWrite(BLUE, HIGH);
            break;
        case 6:
            digitalWrite(RED, LOW);
            digitalWrite(GREN, HIGH);
            digitalWrite(BLUE, HIGH);
            break;
        case 7:
            digitalWrite(RED, HIGH);
            digitalWrite(GREN, HIGH);
            digitalWrite(BLUE, HIGH);
            break;
    }
}
void loop(){
    for (int i = 0; i < 8; i++){
        led(i);
        delay(1000);
    }
}
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
    if(barva == 0){
        digitalWrite(RED, LOW);
        digitalWrite(GREN, LOW);
        digitalWrite(BLUE, LOW);
    }
    else if(barva == 1){
        digitalWrite(RED, HIGH);
        digitalWrite(GREN, LOW);
        digitalWrite(BLUE, LOW);
    }
    else if(barva == 2){
        digitalWrite(RED, HIGH);
        digitalWrite(GREN, HIGH);
        digitalWrite(BLUE, LOW);
    }
    else if(barva == 3){
        digitalWrite(RED, LOW);
        digitalWrite(GREN, HIGH);
        digitalWrite(BLUE, LOW);
    }
    else if(barva == 4){
        digitalWrite(RED, HIGH);
        digitalWrite(GREN, LOW);
        digitalWrite(BLUE, HIGH);
    }
    else if(barva == 5){
        digitalWrite(RED, LOW);
        digitalWrite(GREN, LOW);
        digitalWrite(BLUE, HIGH);
    }
    else if(barva == 6){
        digitalWrite(RED, LOW);
        digitalWrite(GREN, HIGH);
        digitalWrite(BLUE, HIGH);
    }
    else if(barva == 7){
        digitalWrite(RED, HIGH);
        digitalWrite(GREN, HIGH);
        digitalWrite(BLUE, HIGH);
    }
}
void loop(){
    for (int i = 0; i < 8; i++){
        led(i);
        delay(1000);
    }
}
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

void loop(){
    for (int i = 0; i < 256; i++){
        analogWrite(RED, i);
        delay(10);
    }
    for (int i = 255; i > 0; i--){
        analogWrite(RED, i);
        delay(10);
    }
}


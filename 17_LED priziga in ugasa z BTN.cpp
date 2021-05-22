#include <Arduino.h>
#define GUMB 3
#define LED 13

void setup() {
    pinMode(GUMB, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);

}
bool bGumb = false;
void loop() {
    Serial.println(digitalRead(GUMB));
    if(bGumb){
        digitalWrite(LED, HIGH);
    }else{
        digitalWrite(LED, LOW);
    }
    if(!digitalRead(GUMB)){
        bGumb = !bGumb;
        delay(250);
    }
}
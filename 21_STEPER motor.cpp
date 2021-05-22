#include <Arduino.h>
#define X_os A0
#define Y_os A1

byte servo[] = {2,3,4,5};
int hitrost = 1000;

void korak(bool a, bool b, bool c, bool d){
    digitalWrite(servo[0], a);
    digitalWrite(servo[1], b);
    digitalWrite(servo[2], c);
    digitalWrite(servo[3], d);
}

void naprej(){
    korak(1,0,0,0);
    delayMicroseconds(hitrost);
    korak(1,1,0,0);
    delayMicroseconds(hitrost);
    korak(0,1,0,0);
    delayMicroseconds(hitrost);
    korak(0,1,1,0);
    delayMicroseconds(hitrost);
    korak(0,0,1,0);
    delayMicroseconds(hitrost);
    korak(0,0,1,1);
    delayMicroseconds(hitrost);
    korak(0,0,0,1);
    delayMicroseconds(hitrost);
    korak(1,0,0,1);
    delayMicroseconds(hitrost);
}

void nazaj(){
    korak(0,0,0,1);
    delayMicroseconds(hitrost);
    korak(0,0,1,1);
    delayMicroseconds(hitrost);
    korak(0,0,1,0);
    delayMicroseconds(hitrost);
    korak(0,1,1,0);
    delayMicroseconds(hitrost);
    korak(0,1,0,0);
    delayMicroseconds(hitrost);
    korak(1,1,0,0);
    delayMicroseconds(hitrost);
    korak(1,0,0,0);
    delayMicroseconds(hitrost);
    korak(1,0,0,1);
    delayMicroseconds(hitrost);
}


void setup() {
    for(int i = 0; i < 4; i++){
        pinMode(servo[i], OUTPUT);
        digitalWrite(servo[i], LOW);
    }
    Serial.begin(9600);
}

void loop() {
    int v_x = analogRead(X_os);
    int v_y = analogRead(Y_os);

    Serial.print("X: ");
    Serial.print(v_x);
    Serial.print(", Y: ");
    Serial.println(v_y);
    //delay(100);

    // SMER PREMIKANJA
    if(v_x > 750){
        naprej();
    }
    else if(v_x < 250){
        nazaj();
    }
    else {
        korak(0,0,0,0);
    }
}
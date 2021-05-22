#include <Arduino.h>
#define  G 2
#define  F 3
#define  A 4
#define  B 5
#define  E 6
#define  D 7
#define  C 8
#define DP 9

int dell=500;

void setup() {
    Serial.begin(9600);
    pinMode( G, OUTPUT);
    pinMode( F, OUTPUT);
    pinMode( A, OUTPUT);
    pinMode( B, OUTPUT);
    pinMode( E, OUTPUT);
    pinMode( D, OUTPUT);
    pinMode( C, OUTPUT);
    pinMode(DP, OUTPUT);
}

void loop() {
    digitalWrite( G,LOW);
    digitalWrite( F,LOW);
    digitalWrite( A,HIGH);
    digitalWrite( B,LOW);
    digitalWrite( E,LOW);
    digitalWrite( D,LOW);
    digitalWrite( C,LOW);
    digitalWrite(DP,LOW);
    delay(dell);
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    delay(dell);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    delay(dell);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
    delay(dell);
    digitalWrite(D,LOW);
    digitalWrite(E,HIGH);
    delay(dell);
    digitalWrite(E,LOW);
    digitalWrite(F,HIGH);
    delay(dell);
    digitalWrite(F,LOW);
    digitalWrite(G,HIGH);
    delay(dell);
    digitalWrite(G,LOW);
    digitalWrite(DP,HIGH);
    delay(dell);
}
#include <Arduino.h>#include <FastLED.h>

#define R_PIN A0
#define G_PIN A1
#define B_PIN A2

#define NUM_LEDS 8
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

#define vzorci 4
int rdece[vzorci];
int zelene[vzorci];
int modre[vzorci];
int stevec = 0;

void setup() {
    Serial.begin(9600);
    LEDS.addLeds<NEOPIXEL,DATA_PIN>(leds,NUM_LEDS);
    LEDS.setBrightness(80);
    pinMode(R_PIN,INPUT);
    pinMode(G_PIN,INPUT);
    pinMode(B_PIN,INPUT);
    //Serial.println("B,R,G");
}

void loop() {

    int red = analogRead(R_PIN)/4;
    int green = analogRead(G_PIN)/4;
    int blue = analogRead(B_PIN)/4;
    rdece[stevec%4]=red;
    zelene[stevec%4]=green;
    modre[stevec%4]=blue;
    stevec++;

    int vsota=0;
    for(int i=0;i<vzorci;i++){
        vsota=vsota+rdece[i];  // dobimo vsoto vseh vseh vzorcev
    }
    red=vsota/vzorci; // povprečje shranimo nazaj.

    vsota=0;
    for(int i=0;i<vzorci;i++){
        vsota=vsota+zelene[i];  // dobimo vsoto vseh vseh vzorcev
    }
    green=vsota/vzorci; // povprečje shranimo nazaj.

    vsota=0;
    for(int i=0;i<vzorci;i++){
        vsota=vsota+modre[i];  // dobimo vsoto vseh vseh vzorcev
    }
    blue=vsota/vzorci; // povprečje shranimo nazaj.

    Serial.print(blue);
    Serial.print(" ");
    Serial.print(red);
    Serial.print(" ");
    Serial.println(green);

    pinMode(R_PIN,OUTPUT);
    pinMode(G_PIN,OUTPUT);
    pinMode(B_PIN,OUTPUT);
    delay(10);
    pinMode(R_PIN,INPUT);
    pinMode(G_PIN,INPUT);
    pinMode(B_PIN,INPUT);
    delay(500);

    for(int i = 0; i < 1; i++){
        leds[i]=CRGB(red,green,blue);
    }
    FastLED.show();
}
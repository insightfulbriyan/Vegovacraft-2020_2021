#include <FastLED.h>

#define DATA_PIN 3 // DI na LED traku
#define ST_LEDIC 8

CRGB leds[ST_LEDIC];



void setup(){
    Serial.begin(9600);
    FastLED.setBrightness(150); // nastavi globalno svetlost
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, ST_LEDIC); // inicializiramo trak
}

int svetilnost = 30;
int smer = 10;

void loop(){
    for(int i = ST_LEDIC-1; i >= 1; i--){
        leds[i] = leds[i-1];
    }

    leds[0] = CRGB(svetilnost, 0, 0);
    svetilnost += smer;
    if(svetilnost > 250 || svetilnost < 20){
        smer = -smer;
        svetilnost += smer;
    }

    FastLED.show();
    delay(50);
}
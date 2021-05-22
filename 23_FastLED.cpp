#include <FastLED.h>

#define DATA_PIN 3 // DI na LED traku
#define ST_LEDIC 8

CRGB leds[ST_LEDIC];

void setup(){
    Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, ST_LEDIC); // inicializiramo trak
}

void loop(){
    for(int i = 0; i < ST_LEDIC; i++){
        leds[i] = CRGB::Red;
        if(i == 0)
            leds[7] = CRGB::Black;
        else
            leds[i-1] = CRGB::Black;
        FastLED.show();
        delay(100);
    }

    for(int i = ST_LEDIC-1; i >= 0; i--){
        leds[i] = CRGB::Red;
        if(i == 7)
            leds[0] = CRGB::Black;
        else
            leds[i+1] = CRGB::Black;
        FastLED.show();
        delay(100);
    }
}
#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte znak1[] {
        0b00100,
        0b01010,
        0b00100,
        0b01110,
        0b10101,
        0b00100,
        0b01010,
};

const byte enka[] {
        0b11111,
        0b00000,
        0b11111,
        0b00000,
        0b11111,
        0b00000,
        0b11111,
        0b00000
};

const byte dvojka[] {
        0b00000,
        0b11111,
        0b00000,
        0b11111,
        0b00000,
        0b11111,
        0b00000,
        0b11111
};

void setup() {
    lcd.createChar(0, znak1);
    lcd.createChar(1, enka);
    lcd.begin(16, 2);
    lcd.write(65);
    lcd.write(byte(0));
    for(int i = 0; i < 80; i++){
        lcd.write(byte(1));
    }
}

void loop() {
    lcd.createChar(1, enka);
    delay(1000);
    lcd.createChar(1, dvojka);
    delay(1000);
}
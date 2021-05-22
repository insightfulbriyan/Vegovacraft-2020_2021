#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#define rs 12
#define en 11
#define d4 5
#define d5 4
#define d6 3
#define d7 2

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    lcd.begin(16, 2);
    lcd.cursor();
    lcd.blink();
    //lcd.setCursor(2, 0);
    // Print a message to the LCD.
    //         0         1         2         3         4         5         6         7         8
    //         012345678901234567890123456789012345678901234567890123456789012345678901234567890
    lcd.print("hello, world and goodbye heaven, napisem se par dodatnih besed pa se neki dodatn");
}

void loop() {
    lcd.scrollDisplayLeft();
    delay(2000);
}
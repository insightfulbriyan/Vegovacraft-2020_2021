#include <Arduino.h>
#include <Servo.h>

#define BTN 6

const int gumbi[] = {2, 3, 4, 5};

Servo za_trezor;

void setup() {

    for (int i = 0; i < 4; i++) {
        pinMode(gumbi[i], INPUT_PULLUP);
    }
    pinMode(BTN, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    za_trezor.attach(11);
    za_trezor.write(0);
}

byte koda[] = {2, 0, 3, 3};
byte trenutna_koda[] = {4, 4, 4, 4};

byte stevec = 0;

void loop() {
    for (int i = 0; i < 4; i++) {
        if (!digitalRead(gumbi[i])) {
            digitalWrite(BTN, HIGH);
            Serial.print("Pritisnjen ");
            Serial.println(i);
            trenutna_koda[stevec] = i;
            stevec++;

            delay(200);
        }
    }

    if (stevec > 3) {
        bool je_prava = true;
        for (int i = 0; i < 4; i++) {
            if (koda[i] != trenutna_koda[i]) {
                je_prava = false;
            }
        }
        if (je_prava == true) {
            Serial.println("Koda je pravilna; HACKERMAN");
            za_trezor.write(90);
            digitalWrite(BTN, HIGH);
            delay(1000);
            za_trezor.write(0);
        }
        else {
            digitalWrite(LED_BUILTIN, HIGH);
            Serial.println("Koda ni pravilna");
            delay(1000);
            digitalWrite(LED_BUILTIN, LOW);
        }

        stevec = 0;
        for (int i = 0; i < 4; i++) {
            trenutna_koda[i] = 4;
        }
    }
    digitalWrite(BTN, LOW);
}
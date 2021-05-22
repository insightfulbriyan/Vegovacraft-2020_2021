#include <Arduino.h>
#include <LiquidCrystal.h>

#define JOY_X A0
#define JOY_Y A1

#define LEVO -1
#define DESNO 1
#define CENTER 0
#define DOL -1
#define GOR 1

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*
 * Joystick
 * GND ---------- GND
 * 5V  ---------- 5V
 * VRX ---------- A0
 * VRY ---------- A1
 * SW  ---------- ??
 */

const byte pajac[] {
        0b00100,
        0b01010,
        0b00100,
        0b01110,
        0b10101,
        0b00100,
        0b01010,
        0b10001
};

byte kaktus[8] = {
        0b00100,
        0b10100,
        0b10101,
        0b11101,
        0b00111,
        0b00100,
        0b00100,
        0b11111
};

byte tla[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11111
};

void setup() {
    lcd.createChar(0, pajac);
    delay(100);
    lcd.createChar(6, tla);
    delay(100);
    lcd.createChar(7, kaktus);
    lcd.begin(16, 2);

    pinMode(JOY_X, INPUT);
    pinMode(JOY_Y, INPUT);

    Serial.begin(9600);
}

int x;
int y;

int x_smer = 0; // -1 Levo, 0 Center, 1 Desno
int y_smer = 0; // -1 Dol, 0 Center, 1 Gor

int x_pajac = 0;
int y_pajac = 1;

unsigned long zadnji_cas = 0;
unsigned long trenutni_cas = 0;

byte smo_gor = 0;

void loop(){
    x = analogRead(JOY_X);
    y = analogRead(JOY_Y);
    if(x < 16){
        x_smer = -1;
    }
    else if (x > 1008){
        x_smer = 1;
    }
    else {
        x_smer = 0;
    }

    if(y < 16){
        y_smer = -1;
    }
    else if (y > 1008){
        y_smer = 1;
    }
    else {
        y_smer = 0;
    }

    if(x_pajac == 10 && y_pajac == 1){
        lcd.clear();
        lcd.print("GAME OVER; PRESS");
        lcd.setCursor(0,1);
        lcd.print("RESET TO RESET");
        delay(1000000);
    }

    // izrisuj tla
    for(int i = 0; i <= 15; i++){
        lcd.setCursor(i,1);
        lcd.write(6);
    }

    // riši kaktus
    lcd.setCursor(10, 1);
    lcd.write(7);

    // riši pajac
    lcd.setCursor(x_pajac,y_pajac);
    lcd.write(byte(0));

    delay(100);
    lcd.setCursor(x_pajac,y_pajac);
    lcd.write(' ');

    // Premaknemo v x smeri
    //x_pajac += x_smer;

    if(y_smer == GOR){
        y_pajac = 0;
        smo_gor = 2;
    }

    trenutni_cas = millis();
    if(zadnji_cas + 300 < trenutni_cas){
        x_pajac++;

        if(smo_gor == 0){
            y_pajac = 1;
        }
        else if(smo_gor > 0){
            smo_gor--;
        }

        zadnji_cas = trenutni_cas;
    }

    // če pade ven iz mapce, ga damo nazaj
    if(x_pajac < 0)
        x_pajac = 0;
    else if(x_pajac > 15)
        x_pajac = 15;

    // Premikanje v y smeri
    y_pajac += (-1)*y_smer;

    // Če pade ven iz mapce, ga damo nazaj
    if(y_pajac < 0)
        y_pajac = 0;
    else if(y_pajac > 1)
        y_pajac = 1;


    /*
      TODO:
        [x] omejiti igralno polje
        [ ] znak dino in kaktus, tla: 0b01011111
        [ ] 2x40 mapca namest 2x16
    */
}
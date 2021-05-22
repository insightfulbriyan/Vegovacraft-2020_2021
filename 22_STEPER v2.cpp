#define X_os A0
#define Y_os A1

byte servo[] = {2,3,4,5};
int hitrost = 1000;

long int trenutni_korak = 0;

void korak(bool a, bool b, bool c, bool d){
    digitalWrite(servo[0], a);
    digitalWrite(servo[1], b);
    digitalWrite(servo[2], c);
    digitalWrite(servo[3], d);
}

void izberi_korak(byte ker){
    if(ker == 0)
        korak(1,0,0,0);
    else if(ker == 1)
        korak(1,1,0,0);
    else if(ker == 2)
        korak(0,1,0,0);
    else if(ker == 3)
        korak(0,1,1,0);
    else if(ker == 4)
        korak(0,0,1,0);
    else if(ker == 5)
        korak(0,0,1,1);
    else if(ker == 6)
        korak(0,0,0,1);
    else if(ker == 7)
        korak(1,0,0,1);
    delayMicroseconds(hitrost);
}

void naprej(){
    trenutni_korak++;
    izberi_korak(trenutni_korak%8);
}

void nazaj(){
    trenutni_korak--;
    izberi_korak(trenutni_korak%8);
}

void setup() {
    for(int i = 0; i < 4; i++){
        pinMode(servo[i], OUTPUT);
        digitalWrite(servo[i], LOW);
    }
    Serial.begin(9600);
}

int smer = 1;

void loop() {
    if(trenutni_korak == 4200){
        smer = -1;
    }
    else if (trenutni_korak == 0){
        smer = 1;
    }

    trenutni_korak += smer;
    izberi_korak(trenutni_korak%8);
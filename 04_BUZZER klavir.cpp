#include <Arduino.h>
#define BUZZ 11
//             C    D    E    F    G    A    H    C    D    E   C#   D#   F#   G#   A#   C#   D#
int crke[] = {'q', 'w', 'e', 'r', 't', 'z', 'u', 'i', 'o', 'p', '2', '3', '5', '6', '7', '9', '0'};
//                      C    D    E    F    G    A    H     C    D     E    C#   D#   F#   G#   A#   C#     D#
unsigned int toni[] = {523, 587, 659, 698, 783, 880, 987, 1046, 1174, 1319, 554, 622, 739, 830, 932, 1108, 1244};

void setup(){
    Serial.begin(9600);
    pinMode(BUZZ, OUTPUT);

}

void loop() {
    while (Serial.available()) {
        int znak = Serial.read();
        Serial.println(znak);
        for (int x = 0; x < 16; x = x + 1) {
            if (znak == crke[x]) {
                tone(BUZZ, toni[x], 200);
                delay(250);
                Serial.println(crke[x]);
            }
        }
    }
}
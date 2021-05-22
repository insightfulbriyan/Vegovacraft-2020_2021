#include <Arduino.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

#define ENA LOW  // HIGH
#define NIC HIGH // LOW

// CONNECTIONS:
// DS1302 CLK/SCLK --> A2
// DS1302 DAT/IO --> A1
// DS1302 RST/CE --> A0
// DS1302 VCC --> -5v
// DS1302 GND --> GND

#define CLK A2
#define DAT A1
#define RST A0

ThreeWire myWire(DAT,CLK,RST); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

//const byte stevilke[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0xFF};
const byte stevilke[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00};

//                       A  B  C  D   E   F   G  DP
const byte segmenti[] = {6, 7, 8, 9, 10, 11, 12, 13};
//                    D1 D2 D3 D4
const byte stevke[] = {2, 3, 4, 5};

void prikaziStevko(byte stevka, bool pika){
    byte dva = 1;
    for(int i = 0; i < 7; i++){
        digitalWrite(segmenti[i], dva&stevilke[stevka]);
        dva *= 2;
    }
    if (pika == true){
        digitalWrite(segmenti[7], ENA);
    }
    else {
        digitalWrite(segmenti[7], NIC);
    }
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt){
    char datestring[20];

    snprintf_P(datestring,
               countof(datestring),
               PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
               dt.Month(),
               dt.Day(),
               dt.Year(),
               dt.Hour(),
               dt.Minute(),
               dt.Second() );
    Serial.print(datestring);
}

void setup() {
    for(int i = 0; i < 8; i++){ // i gre od 0 do 7
        pinMode(segmenti[i], OUTPUT); // npr. segmenti[2] bo imel vrednost 8
        digitalWrite(segmenti[i], NIC); // ugasnemo segmente
    }
    pinMode(stevke[0], OUTPUT);
    pinMode(stevke[1], OUTPUT);
    pinMode(stevke[2], OUTPUT);
    pinMode(stevke[3], OUTPUT);

    digitalWrite(stevke[0], ENA);
    digitalWrite(stevke[1], ENA);
    digitalWrite(stevke[2], ENA);
    digitalWrite(stevke[3], ENA);

    // URA
    Serial.begin(9600);

    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.println(__TIME__);

    Rtc.Begin();
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

    if (!Rtc.IsDateTimeValid()) {
        // Common Causes:
        //    1) first time you ran and the device wasn't running yet
        //    2) the battery on the device is low or even missing

        Serial.println("RTC lost confidence in the DateTime!");
        Rtc.SetDateTime(compiled);
    }

    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false);
    }

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if (now < compiled)
    {
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        Rtc.SetDateTime(compiled);
    }
    else if (now > compiled)
    {
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    else if (now == compiled)
    {
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
}

byte trenutni_prikaz[] = {0, 0, 0, 0};
bool pike[] = {true, true, true, true};
int ura;
int minuta;
int prejsnja_sekunda = 0;

void loop() {
    RtcDateTime now = Rtc.GetDateTime();

    //printDateTime(now);
    //Serial.println();

    // Nastavi uro na display
    ura = now.Hour();
    minuta = now.Minute();
    int st = 100 *ura + minuta;

    //int st = 1917;

    // Izpis na display
    for(int i = 3; i >= 0; i--){
        trenutni_prikaz[i] = st%10;
        st = st / 10;
    }

    // Utripanje pike
    if(prejsnja_sekunda != now.Second()){
        Serial.print(ura);
        Serial.print(":");
        Serial.println(minuta);
        if(now.Second() % 2 == 0){
            pike[1] = true;
        }
        else {
            pike[1] = false;
        }
        prejsnja_sekunda = now.Second();
    }

    for(int i = 0; i < 4; i=i+1){
        prikaziStevko(trenutni_prikaz[i], pike[i]);
        digitalWrite(stevke[i], ENA);
        delay(1);
        digitalWrite(stevke[i], NIC);
    }
}
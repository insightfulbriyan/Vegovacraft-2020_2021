#include <Arduino.h>
#include <LiquidCrystal.h>
// funkcija snprintf je definirana v stdio knjižnici
// brez spodnje vrstice je prevajalnik ne najde!
#include <stdio.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//spremenljivka 't' je 32 bitno predznačeno celo število
// int je 16- biten na arduino uno, nano, ipd.
long t=65500;
// za "vrstica" rezerviramo 17 bytov za znake, ki jih izpisujemo
char vrstica[17];
// imamo 2d polje (tabelo) s sadeži (da, sir je sadež). Vsaka beseda je 17 znakov dolga
// zadnji znak vsake besede je znak z ascii kodo 0x00
char besede[][17]={"ananas","banana","kiwi","sir","kokos","jabolko"};

void setup() {
    lcd.begin(16, 2);
}

void loop() {
    //snprintf(vrstica,17 ,"sadez: %9s",besede[t%6]);
    snprintf(vrstica,17,"hex: %04x",t);
    lcd.setCursor(0,0);
    lcd.print(vrstica);
    lcd.setCursor(0,1);
    //V polje "vrstica" pripravimo niz znakov po "receptu"
    // %d -> celo število
    // %ld -> celo število 32 bit (long)
    // %s -> niz znakov
    // %2d -> 2 pomeni, koliko mest najmanj zavzame to polje
    // %02d -> 0 pomeni, da vrine spredaj ničle
    // %-4s -> niz 4 znakov, ki je zaradi - poravnan na levo (po navadi je na desno)
    snprintf(vrstica,17,"cas: %02ld:%02ld:%02ld",(t/3600)%24,(t/60)%60,t%60);
    lcd.print(vrstica);
    if(t>0)t++;
        // z oznako 60L zahtevamo, da prevajalnik obravnava število kot 32 bitno.
    else t=60L*60L*24L;
    // naredi da ne gre prehitr
    delay(100);
}
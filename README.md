# Arduino_IR_Remote-Controll

IR dialkove Ovladanie

Najlepšie Diaľkové ovládanie pre Kodi a čokoľvek iné. 
Prijímač je vytvorený pomocou Dosky - Arduino - SPARK FUN PRO MICRO ATMEGA 32U4 
Doska je automaticky rozpoznaná ako usb Klávesnica. Nie je potrebne ju inštalovať.  
Inštalácia je potrebná len pri programovaní cez Software Arduino IDE. 
Ako som už písal, prijímač si môžete naprogramovať ako chcete. V mojom prípade je naprogramovaný podľa klávesnice.  
Čo sa týka Ovládača, je len na vás aký použijete. Potrebujete len nejaké zariadenie ktoré ma tlačidlá a dokáže vysielať IR kód. Či už použijete ovládač čo ste našli po starých rodičoch alebo nejaký nový, to je úplne jedno.  
Pomocou priloženého kódu si naskenujete jednotlivé tlačidlá a kódy vložíte do kódu IR prijímača. Ku nim nadefinujete funkciu podľa klávesnice.  
Úplne jednoduchá vec a navyše sa už nebudete musieť zaoberať z Lirc a jeho konfiguráciou.  
Či to pripojíte ku Win-PC, Linux-PC, Android alebo čokoľvek iné s USB portom a možnosťou pripojenia USB klávesnice. Všade to bude automaticky rozpoznane. Skúšal som to aj na Android TV boxe a aj na telefóne. Vždy to fungovalo. 
 
SPARK FUN PRO MICRO ATMEGA 32U4 - cena od 7€ 
  
Arduino IDE Soft na programovanie Dosky 
https://downloads.arduino.cc/arduino-1.8.19-windows.exe 
  
Inštalácia Dosky 
https://learn.sparkfun.com/tutorials/qwiic-pro-micro-usb-c-atmega32u4-hookup-guide/setting-up-arduino 
  
Inštalácia Knižnice Arduino_IR_Remote_Master 
https://downloads.arduino.cc/libraries/github.com/z3t0/IRremote-3.6.1.zip 
Projekt / Zahrnúť Knižnice / Pridať ZIP Knižnicu / “Tvoje Umiestnenie stiahnutej knižnice” 
 
IR prijímač 38 kHz - Centova záležitosť Je len na vás aký si zvolíte. Podla typu bude prijímač viac alebo menej citlivý.
https://www.gme.sk/tl1838 
  
Pripojenie IR prijímača 
https://arduinoinfo.mywikis.net/wiki/IR-RemoteControl 
V kóde je napísané ktoré piny sú pripojene. VCC +, GND -, Senzor Pin 

#include <ESP8266WiFi.h>
#include "etatRelais.h"
#include <Arduino.h>

int declarationDesSorties ( ) {      

      pinMode(portSortie0, OUTPUT);
      pinMode(portSortie1, OUTPUT);
      pinMode(portSortie2, OUTPUT);
      pinMode(portSortie3, OUTPUT);
      pinMode(portSortie4, OUTPUT);
      pinMode(portSortie5, OUTPUT);


      digitalWrite( portSortie0, LOW);  
      digitalWrite( portSortie1, LOW);
      digitalWrite( portSortie2, LOW);  
      digitalWrite( portSortie3, LOW);
      digitalWrite( portSortie4, LOW);  
      digitalWrite( portSortie5, LOW);
};

#include <ESP8266WiFi.h>
#include "etatRelais.h"
#include <Arduino.h>

int declarationDesSorties ( ) {      


      pinMode(portSortie5, OUTPUT);
      pinMode(portSortie4, OUTPUT);      
      digitalWrite( portSortie5, LOW);
      digitalWrite( portSortie4, LOW);  

};

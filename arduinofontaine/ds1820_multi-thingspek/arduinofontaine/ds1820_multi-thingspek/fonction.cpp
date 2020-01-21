//#include <ESP8266WiFi.h>
#include "fonction.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

//#include <ESP8266WiFi.h>

#include <ThingSpeak.h>
#include "variables.h"


OneWire sondeTemperatureChaudiereOneWire(sondeTemperatureChaudierePin);
OneWire sondeTemperatureBallonOneWire(sondeTemperatureBallonPin);


//  sondeTemperatureChaudiere.begin();
//  sondeTemperatureBallon.begin();


  DallasTemperature sondeTemperatureChaudiere(&sondeTemperatureChaudiereOneWire);
  DallasTemperature sondeTemperatureBallon(&sondeTemperatureBallonOneWire);

  
float demandeTemperatureChaudiere(){
  sondeTemperatureChaudiere.requestTemperatures();
    while ((sondeTemperatureBallon.getTempCByIndex(0) <= -100 )){ //&&( erreur < 65500)
        sondeTemperatureBallon.requestTemperatures();
//        erreur++ ;
  }
  return sondeTemperatureChaudiere.getTempCByIndex(0);
}

float demandeTemperatureBallon(){
//  sondeTemperatureBallon.requestTemperatures();
//  unsigned short erreur =0;
  while ((sondeTemperatureBallon.getTempCByIndex(0) <= (-100,DEC) )){ //&&( erreur < 65500)
        sondeTemperatureBallon.requestTemperatures();
//        erreur++ ;
  }
  return sondeTemperatureBallon.getTempCByIndex(0);
  }

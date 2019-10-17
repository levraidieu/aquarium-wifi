#ifndef __TEMPERATURE_H_
#define __TEMPERATURE_H_


#include <Arduino.h>
#include <ESP8266WiFi.h>        // pour la connexion WiFi. https://github.com/esp8266/Arduino
#include <WiFiClientSecure.h>   // connexion https

#include "etatRelais.h"

int boot_capteur_temperature   ( );
int demande_temperature_ds1820 ( );

int temperatureAquariumOnOffRelais();


extern String sms;

int smsModulaire1();
void envoiSms(String messageSms);

#endif

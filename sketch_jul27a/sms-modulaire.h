#ifndef __SMS_H_
#define __SMS_H_

#include <Arduino.h>
#include <ESP8266WiFi.h>        // pour la connexion WiFi. https://github.com/esp8266/Arduino
#include <WiFiClientSecure.h>   // connexion https

extern const char* ssid;
extern const char* password;
extern unsigned int localPort;
extern String sms;

int boot();
int smstempDs1820();
int smsModulaire1();
void envoiSms(String messageSms);

	#endif

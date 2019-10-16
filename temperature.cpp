#include "temperature.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>        // pour la connexion WiFi. https://github.com/esp8266/Arduino
#include <WiFiClientSecure.h>   // connexion https

/*
sensors.getTempCByIndex(0) 					//capteur1
sensors.getTempCByIndex(1) 					//capteur2

*/

#include <OneWire.h> //Librairie du bus OneWire
OneWire oneWire=2; //Bus One Wire sur la pin 2 de l'arduino
#include <DallasTemperature.h> //Librairie du capteur
DallasTemperature sensors(&oneWire); //Utilistion du bus Onewire pour les capteurs
DeviceAddress sensorDeviceAddress; //Vérifie la compatibilité des capteurs avec la librairie


sensors.begin(); //Activation des capteurs
sensors.getAddress(sensorDeviceAddress, 0); //Demande l'adresse du capteur à l'index 0 du bus
sensors.setResolution(sensorDeviceAddress, 12); //Résolutions possibles: 9,10,11,12

sensors.requestTemperatures(); //Demande la température aux capteurs

if (sensors.getTempCByIndex(0) == -127) {
Serial.println("Capteur 1 HS");
delay(1000); // pause de 1 secondes


 Serial.print("La température est: ");
 Serial.print(sensors.getTempCByIndex(0)); //affichage la température en celsius du capteur n°0
 Serial.println(" C°");
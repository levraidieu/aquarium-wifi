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

int boot_capteur_temperature ( ) {
	sensors.begin(); //Activation des capteurs
	sensors.getAddress(sensorDeviceAddress, 0); //Demande l'adresse du capteur à l'index 0 du bus
	sensors.setResolution(sensorDeviceAddress, 12); //Résolutions possibles: 9,10,11,12
}


int demande_temperature_ds1820 ( ) {
	sensors.requestTemperatures( ); //Demande la température aux capteurs
	int compteur_default = 1 ;
	int sonde = 0 ;
	for (compteur_default =0 ; compteur_default  != 20 ; compteur_default ++ ) {
	while ( ( sensors.getTempCByIndex(sonde) == -127 )  ) {
	//tant que capteur 127 ou compteur 32000 
	Serial.println("Capteur 1 HS");

	/*
	si comp 





	*/
	
	// delay(1000); // pause de 1 secondes
	}
	}


	else
	{
    /* code */
    Serial.print("La température est: ");
 	Serial.print(sensors.getTempCByIndex(0),DEC); //affichage la température en celsius du capteur n°0
 	Serial.println(" C°");
	}


 }
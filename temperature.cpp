#include "temperature.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>        // pour la connexion WiFi. https://github.com/esp8266/Arduino
#include <WiFiClientSecure.h>   // connexion https

#include "etatRelais.h"
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
	//sensors.requestTemperatures( ); //Demande la température aux capteurs
	unsigned int  sonde_compteur_defaut = 1 ;//0-65535
	unsigned char sonde_nombre = 10 ;//0-255
	boolean sonde_en_defaut = 1;//0-1
//	for (compteur_default =0 ; compteur_default  != 20 ; compteur_default ++ ) {
//	while ( ( sensors.getTempCByIndex(sonde) == -127 )  ) {
		while ( ( sonde_en_defaut == 1 || sonde_compteur_defaut !=65000 )  ) {
			//tant que capteur 127 ou compteur 32000
			sensors.requestTemperatures( ); //Demande la température aux capteurs
			sonde_en_defaut =0 ;
			unsigned char sonde_nombre_test = 0 ;//0-255
			for (sonde_nombre_test =0 ; sonde_nombre_test  != sonde_nombre ; sonde_nombre_test ++ ) {
				if (sensors.getTempCByIndex(sonde_nombre_test) == -127) {
					sonde_en_defaut = 1;
				}
			}
		sonde_compteur_defaut ++ ;
			//Serial.println("Capteur 1 HS");

		/*
		si comp





		*/

		// delay(1000); // pause de 1 secondes
		}



	//else
	//{
    ///* code */
    ///Serial.print("La température est: ");
 	//Serial.print(sensors.getTempCByIndex(0),DEC); //affichage la température en celsius du capteur n°0
 	//Serial.println(" C°");
	//}


 }
int temperatureAquariumOnOffRelais(){
    if (sensors.getTempCByIndex(0) == -127) {
        smsAlarmeds1820hs();
        }
    if (sensors.getTempCByIndex(0) >= 30  ) {
        smsAlarmeds1820supp30();
        }
    if (sensors.getTempCByIndex(0) <= 24  ) {
        chauffeEau = 1 ;
        }

    }

/*
detecteur debordement
detecteur eau haut
detecteur eau niveau bas

temperature aquarium
temperature salon
temperature balcon
temperature exterieur

lcd-sms
  ip wan-lan
  temperature
  alerte
    relais
    horloge 
    etatRelais
    tension pile ds3231 bas
    
prog-horaire
  horloge ds3231
  millis

web
  horodatage
  lien thingspeak
  affichage temperature
  horaire marche/arret relais
  activation desactivation relais (et si desactivation un fois ou plusieur fois)
  modification horaire

boutonAquarium
  defilement  date/horaire
              detecteur
              temperature
              horaire relais on/off

led
  alarme
  relais
  etat du wifi

ntp


broche
  detecteur
  lcd
  clavier
  relais


*/
//  bibliotheque Wi-Fi pour le 8266
#include <ESP8266WiFi.h>
#include "wifi.h"

const char* ssid     = "test";
const char* password = "1234";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output5State = "off";
String output4State = "off";



// Assign output variables to GPIO pins
const int output5 = 5;
const int output4 = 4;

//sms


#include <WiFiClientSecure.h>   // connexion https
#include "sms-modulaire.h"
//************************ WiFi  *************************
//const char* ssid = "XXXXXXXX";
//const char* password = "XXXXXXXX";
unsigned int localPort = 8084;

String sms;


//declaration de sorties et etat relais
#include "etatRelais.h"
byte portSortie0 ;
byte portSortie1 ;
byte portSortie2 ;
byte portSortie3 ;
byte portSortie4 ;
byte portSortie5 ;




//prog horaire
#include "progHoraire3231.h"

// variable relais
boolean LumierePrincipale = 0 ;
boolean lumierePETITE = 0 ;
boolean nourriture = 0 ;
boolean filtre1 = 0 ;
boolean filtre2 = 0 ;
boolean filtre3 = 0 ;
boolean alarmeNiveauEau = 0  ;
boolean voyant = 0 ;
boolean chauffeEau = 0 ;

boolean thermometre;
byte thermometreInterieur = 0 ;
byte thermometreExterieur = 0 ;
byte thermometreExterieurLogia = 0 ;
int bouton = 0 ;

//mail
#include "mail.h"

//lcd

#include "lcd.h"

// bouton aquarium
#include "boutonAquarium.h"

//alarme


#include "alarme.h"

#include "temperature.h"


void setup() {
  Serial.begin(115200);
 init_wifi( );

 smsModulaire1();
  envoiSms(sms);
  smsiplocal();
declarationDesSorties ( );
}

void loop() {
  // put your main code here, to run repeatedly:
  web_page ( );				//wifi.h
  progHoraire ( );			//proghoraire ds3231
}

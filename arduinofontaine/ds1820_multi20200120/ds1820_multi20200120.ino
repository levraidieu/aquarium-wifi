#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

#include <ESP8266WiFi.h>

#include <ThingSpeak.h>
#include "secrets.h"


//thingspeak
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

//wifi
const char* SSID = SECRET_SSID;
const char* password = SECRET_PASS;

// Create the ESP Web Server on port 80
WiFiServer WebServer(80);
// Web Client
WiFiClient client;


// millis
int intervalAffichage = 2000;
int intervalThingSpeak =20000;
unsigned long previousMillis = 0;
unsigned long previousMillisThingspeak ;

//divers
int numero =0;
float numerobis =0;
float numeroter =0;

//Temp Sensors pin
const int sondeTemperatureChaudierePin = 10;//15
const int sondeTemperatureBallonPin = 14;
unsigned int ds1820erreur = 1000;



//Setup OneWire
OneWire sondeTemperatureChaudiereOneWire(sondeTemperatureChaudierePin);
OneWire sondeTemperatureBallonOneWire(sondeTemperatureBallonPin);

//Setup temp sensors
DallasTemperature sondeTemperatureChaudiere(&sondeTemperatureChaudiereOneWire);
DallasTemperature sondeTemperatureBallon(&sondeTemperatureBallonOneWire);

float chaudiere = 0;
float ballon = 0;

float erreurCuisine =0;


float demandeTemperatureChaudiere();

float demandeTemperatureBallon();

  
void setup() {
delay(10000);



  
Serial.begin( 115200 );
  Serial.print( "initialisation port serie\n" );
sondeTemperatureChaudiere.begin();
  sondeTemperatureBallon.begin();

  // Connect to WiFi network
  Serial.println();
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to ");
  Serial.println(SSID);
  WiFi.begin(SSID, password);
  WiFi.hostname("esp-chaudiere");

 
  ThingSpeak.begin(client);  // Initialize ThingSpeak


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");

  // Start the Web Server
  WebServer.begin();
  Serial.println("Web Server started");

  // Print the IP address
  Serial.print("You can connect to the ESP8266 at this URL: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  Serial.print("IP address   : ");
  Serial.println(WiFi.localIP());
  Serial.print("GW address   : ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("MAC address  : ");
  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.hostname());

  Serial.print( "initialisation port serie\n" );

  Serial.println("https://thingspeak.com/channels/955285");

  //desactivation wdt +loop
  ESP.wdtDisable();
// ESP.wdtEnable(WDTO_59S);
// ESP.wdtEnable(60000);

  
  demandeTemperatureBallon();
}

void loop() {
 // desactivatio wdt
  ESP.wdtFeed();
//  float erreur=0;
//  erreurCuisine= *erreur;
unsigned long currentMillis = millis();
numerobis++;

  if ((currentMillis - previousMillis) >= intervalAffichage ) {
    // save the last time you blinked the LED
    previousMillis = currentMillis; 
      
       numero++;
   Serial.print (  numero  );
   Serial.print (  "  " ) ;
   numerobis = numeroter - numerobis ;
   Serial.print (  numerobis );
   numerobis = numeroter ;
    Serial.print (  "  " ) ;
     Serial.println(  numeroter );


chaudiere = 127; //demandeTemperatureChaudiere();
ballon = demandeTemperatureBallon();



     
  Serial.print("Temperature de la Chaudiere: ");
  Serial.print(chaudiere);
  Serial.print("\xC2\xB0 ");
  Serial.println("C");
  Serial.println("\xC2\xB0 ");

  Serial.print("Temperature du Ballon: ");
  Serial.print(ballon);
//  Serial.print(char(176));
  Serial.print(" \xC2\xB0");
  Serial.println("C");
//      Serial.println("\xC2");
//      Serial.println("\xB0");
            Serial.println("\xC2\xB0");
//      Serial.write(0xC2);
//



Serial.println();
//      Serial.write(0xB0);
//      Serial.println();
//      Serial.write(194);
//      Serial.println();
//      Serial.write(176);
//      Serial.println("\xC2");
//      Serial.println("\xB0");
  
Serial.println();

}
  ThingSpeak.setField(1, 127);
  ThingSpeak.setField(2, ballon);

 if ((currentMillis - previousMillisThingspeak) >= intervalThingSpeak ) {
    // save the last time you blinked the LED
    previousMillisThingspeak = currentMillis;  
// write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("                                                                              Channel update successful.");
  }
  else{
    Serial.println("                                                                              Probleme mise a jour thingspeak. HTTP error code " + String(x));
  }
    Serial.println("                                                                              https://thingspeak.com/channels/955285\n" );

}

}






float demandeTemperatureChaudiere(){
  Serial.println ("debut boucle demandeTemperatureChaudiere");
 unsigned int erreur=0;
 do { 
  sondeTemperatureChaudiere.requestTemperatures();
    Serial.print ("erreur " );
    Serial.print (erreur  );
    Serial.print ("  " );
  Serial.println (sondeTemperatureChaudiere.getTempCByIndex(0),DEC);
  Serial.print ("   chaudiere " );
  erreur++;
  delay (500);
    ESP.wdtFeed();
 }
 while ((sondeTemperatureChaudiere.getTempCByIndex(0) >= -127)|| (erreur <= ds1820erreur ));
  Serial.println ("fin          boucle demandeTemperatureChaudiere");
  return sondeTemperatureChaudiere.getTempCByIndex(0);
}

float demandeTemperatureBallon(){
    Serial.println ("debut boucle demandeTemperatureBallon");
 unsigned int erreur=0;
 do {
  sondeTemperatureBallon.requestTemperatures();
//  delay (1000) ;
      Serial.print ("erreur " );
    Serial.print (erreur  );
    Serial.print ("  " );
  Serial.print (sondeTemperatureBallon.getTempCByIndex(0),DEC);
  Serial.println ("   ballon" );
    erreur++;
      ESP.wdtFeed();
    
 }
 while ( (sondeTemperatureBallon.getTempCByIndex(0),DEC == -127)||(erreur <= ds1820erreur));
  return sondeTemperatureBallon.getTempCByIndex(0);
}

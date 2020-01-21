#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

#include <ESP8266WiFi.h>

#include <ThingSpeak.h>
#include "secrets.h"

#include "variables.h"
#include "fonction.h"

//led
int fredledgauche =16;
int fredleddroite =14;


//thingspeak
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

//wifi
const char* SSID = SECRET_SSID;
const char* password = SECRET_PASS;
WiFiServer WebServer(80);  // Create the ESP Web Server on port 80
WiFiClient client;  // Web Client


// millis
int intervalAffichage = 2000;
int intervalThingSpeak =900000;
unsigned long previousMillis = 0;
unsigned long previousMillisThingspeak ;

//divers
int numero =0;
float numerobis =0;
float numeroter =0;

//Temp Sensors pin
int sondeTemperatureChaudierePin = 15;
int sondeTemperatureBallonPin = 14;

//Setup OneWire
OneWire sondeTemperatureChaudiereOneWire(sondeTemperatureChaudierePin);
OneWire sondeTemperatureBallonOneWire(sondeTemperatureBallonPin);

//Setup temp sensors
//DallasTemperature sondeTemperatureChaudiere(&sondeTemperatureChaudiereOneWire);
//DallasTemperature sondeTemperatureBallon(&sondeTemperatureBallonOneWire);
  DallasTemperature sondeTemperatureChaudiere(&sondeTemperatureChaudiereOneWire);
  DallasTemperature sondeTemperatureBallon(&sondeTemperatureBallonOneWire);
float chaudiere = 0;
float ballon = 0;

void setup() {

 digitalWrite(fredledgauche , HIGH);
 digitalWrite(fredleddroite , HIGH);
 delay(10000);
 digitalWrite(fredledgauche , LOW);
 digitalWrite(fredleddroite , LOW);
// initds1820();
  
  sondeTemperatureChaudiere.begin();
 sondeTemperatureBallon.begin();

  Serial.begin( 115200 );
  Serial.print( "initialisation port serie\n" );

  // Connect to WiFi network
  Serial.println();
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to ");
  Serial.println(SSID);
  WiFi.begin(SSID, password);
  WiFi.hostname("esp8266chaudiere");
 
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(fredledgauche , HIGH);
    delay(500);
    digitalWrite(fredledgauche , LOW);
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

  ThingSpeak.begin(client);  // Initialize ThingSpeak
  Serial.print( "initialisation port serie\n" );
  Serial.println("https://thingspeak.com/channels/955285");  
}

void loop() {
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
 digitalWrite(fredleddroite , HIGH);

chaudiere = demandeTemperatureChaudiere();
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
    delay(500);
 digitalWrite(fredleddroite , LOW);

}
  ThingSpeak.setField(1, chaudiere);
  ThingSpeak.setField(2, demandeTemperatureBallon());

 if ((currentMillis - previousMillisThingspeak) >= intervalThingSpeak ) {
    // save the last time you blinked the LED
    previousMillisThingspeak = currentMillis;  
// write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("                                                                              Channel update successful.");
    digitalWrite(fredledgauche , HIGH);
    delay(500);
    digitalWrite(fredledgauche , LOW);    
    
  }
  else{
    Serial.println("                                                                              Probleme mise a jour thingspeak. HTTP error code " + String(x));
  }
    Serial.println("                                                                              https://thingspeak.com/channels/955285\n" );

}

}

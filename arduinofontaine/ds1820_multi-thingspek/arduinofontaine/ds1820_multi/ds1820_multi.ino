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
const int sondeTemperatureChaudierePin = 15;
const int sondeTemperatureBallonPin = 14;

//Setup OneWire
OneWire sondeTemperatureChaudiereOneWire(sondeTemperatureChaudierePin);
OneWire sondeTemperatureBallonOneWire(sondeTemperatureBallonPin);

//Setup temp sensors
DallasTemperature sondeTemperatureChaudiere(&sondeTemperatureChaudiereOneWire);
DallasTemperature sondeTemperatureBallon(&sondeTemperatureBallonOneWire);

float chaudiere = 0;
float ballon = 0;

float demandeTemperatureChaudiere(){
  sondeTemperatureChaudiere.requestTemperatures();
  return sondeTemperatureChaudiere.getTempCByIndex(0);
}

float demandeTemperatureBallon(){
  sondeTemperatureBallon.requestTemperatures();
  return sondeTemperatureBallon.getTempCByIndex(0);
}
  
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

}
  ThingSpeak.setField(1, chaudiere);
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

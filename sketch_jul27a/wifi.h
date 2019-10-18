#ifndef __WIFI_H_
#define __WIFI_H_

extern String header;
extern WiFiServer server;


extern const char* ssid    ;
extern const char* password ;










// Auxiliar variables to store the current output state
extern String output5State ;
extern String output4State ;

// Assign output variables to GPIO pins
extern const int output5 ;
extern const int output4 ;


int web_page ( );
int init_wifi();

 #endif

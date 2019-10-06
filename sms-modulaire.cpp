#include "sms-modulaire.h"
#include <ESP8266WiFi.h>        // pour la connexion WiFi. https://github.com/esp8266/Arduino
#include <WiFiClientSecure.h>   // connexion https
#include <Arduino.h>

int boot(){
	string sms ="boot ou reboot"
	sms.replace(" ", "%20"); // encode URL espace " " par "%20"
  	sms.replace("\n", "%0D%0A"); // encode URL a la ligne "\n" par "%0D%0A"
    envoiSms(sms);

}

int smstempDs1820(){
	   string sms = sondeTemperatureAqua + sondeTemperatureSalon ;
	   sms.replace(" ", "%20"); // encode URL espace " " par "%20"
  	 sms.replace("\n", "%0D%0A"); // encode URL a la ligne "\n" par "%0D%0A"
     envoiSms(sms);

}




int smsModulaire1()
  {

  //  http://wittyboard.free.fr
  // certains caractères sont indésirables dans l'URL il faut l'encoder
  String sms = " essai de sms free-mobile \n a partir de Witty.";
  Serial.println(sms);
  sms.replace(" ", "%20"); // encode URL espace " " par "%20"
  sms.replace("\n", "%0D%0A"); // encode URL a la ligne "\n" par "%0D%0A"
  Serial.println(sms);
  envoiSms(sms);
  }






void envoiSms(String messageSms) {
const char* host = "smsapi.free-mobile.fr";
const int   httpsPort = 443;
const char* user = "XXXXXXXX";
const char* pass = "XXXXXXXX";
// Pour trouver le fingerprint de free sms, se connecter avec votre navigateur
// à https://smsapi.free-mobile.fr puis,clic a la suite:
// clic droit,inspecter,securité,voir le certificat,détails,empreinte numérique
const char* fingerprint = "18 EB 36 0D AD 38 0D 0E D1 87 8B 09 4D 44 CF 45 38 90 F7 DC";
  WiFiClientSecure client;
  Serial.print("connection.... ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection erreur");
    return;
  }
  if (client.verify(fingerprint, host)) {
    Serial.println("certificat correct");
  } else {
    Serial.println("certificat incorrect");
  }
  String url = "/sendmsg?user=" + String(user) + "&pass=" + pass + "&msg=" + messageSms;
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: Esp8266_Witty_Gizwits\r\n" +
               "Connection: close\r\n\r\n");
  while (client.connected()) {
    String line = client.readStringUntil('\r');
    Serial.println("Lecture des headers ");
    Serial.println(line);
    break;
  }
  Serial.println("close connection");
  }

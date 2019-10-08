//      DS3231_get(&t);
//      Serial.print("date : ");
//      Serial.print(t.mday);
//      Serial.print("/");
//      Serial.print(t.mon);
//      Serial.print("/");
//      Serial.print(t.year);
//      Serial.print("\t Heure : ");
//      Serial.print(t.hour);
//      Serial.print(":");
//      Serial.print(t.min);
//      Serial.print(".");
//      Serial.println(t.sec);
#ifndef __progHORAIRE3231_H_
#define __progHORAIRE3231_H_


int LumierePrincipaleOnOff ( );
int lumierePETITEOnOff ( );
int nourritureOnOff ( );
int filtre1OnOff ( );
int filtre2OnOff ( );
int filtre3OnOff ( );
int thermometreInterieurETEHIVER ( ); //a modifier par rapport au date


int progHoraire ( );                  //reprend tout les ... du dessus 
  #endif

#include "ds3231.h"
    struct ts t;                    //variable pour utilisation ds3231
#include <Wire.h>

#include "progHoraire3231.h"

#include "etatRelais.h"             //variable commun declarer dans un fichier sur etat de sorti des relais



  

int LumierePrincipaleOnTh = 9;
int LumierePrincipaleOnTm = 0;
int LumierePrincipaleOffTh = 20;
int LumierePrincipaleOffTm = 0;

int lumierePETITEOnTh = 9;
int lumierePETITEOnTm = 0;
int lumierePETITEOffTh = 20;
int lumierePETITEOffTm = 0;

int nourritureOnTh = 9;
int nourritureOnTm = 0;
int nourritureOffTh = 20;
int nourritureOffTm = 0;

int filtre1OnTh = 9;
int filtre1OnTm = 0;
int filtre1OffTh = 20;
int filtre1OffTm = 0;

int filtre2OnTh = 9;
int filtre2OnTm = 0;
int filtre2OffTh = 20;
int filtre2OffTm = 0;

int filtre3OnTh = 9;
int filtre3OnTm = 0;
int filtre3OffTh = 20;
int filtre3OffTm = 0;




int LumierePrincipaleOnOff ( ) {
  if  ((t.hour  >= LumierePrincipaleOnTh   && t.min  >= LumierePrincipaleOnTm )
   ||  (t.hour  <= LumierePrincipaleOffTh  && t.min  >= LumierePrincipaleOffTm )) {
    LumierePrincipale  = 1;
  }
  else 
  {
    LumierePrincipale  = 0;
  }
  };

int lumierePETITEOnOff ( ) {
  if  ((t.hour  >= lumierePETITEOnTh   && t.min  >= lumierePETITEOnTm )
   ||  (t.hour  <= lumierePETITEOffTh  && t.min  >= lumierePETITEOffTm )) {
    lumierePETITE  = 1;
  }
  else 
  {
    lumierePETITE  = 0;
  }
  };

int nourritureOnOff ( ) {
  if  ((t.hour  >= nourritureOnTh   && t.min  >= nourritureOnTm )
   ||  (t.hour  <= nourritureOffTh  && t.min  >= nourritureOffTm )) {
    nourriture  = 1;
  }
  else 
  {
    nourriture  = 0;
  }
  };

int filtre1OnOff ( ) {
  if  ((t.hour  >= filtre1OnTh   && t.min  >= filtre1OnTm )
   ||  (t.hour  <= filtre1OffTh  && t.min  >= filtre1OffTm )) {
    filtre1  = 1;
  }
  else 
  {
    filtre1  = 0;
  }
  };

int filtre2OnOff ( ) {
  if  ((t.hour  >= filtre2OnTh   && t.min  >= filtre2OnTm )
   ||  (t.hour  <= filtre2OffTh  && t.min  >= filtre2OffTm )) {
    filtre2  = 1;
  }
  else 
  {
    filtre2  = 0;
  }
  };

int filtre3OnOff ( ) {
  if  ((t.hour  >= filtre3OnTh   && t.min  >= filtre3OnTm )
   ||  (t.hour  <= filtre3OffTh  && t.min  >= filtre3OffTm )) {
    filtre3  = 1;
  }
  else 
  {
    filtre3  = 0;
  }
  };

  
int thermometreInterieurETEHIVER ( ) {
  if  ((t.hour  >= filtre3OnTh   && t.min  >= filtre3OnTm )
   ||  (t.hour  <= filtre3OffTh  && t.min  >= filtre3OffTm )) {
    filtre3  = 1;
  }
  else 
  {
    filtre3  = 0;
  }
  };





int progHoraire ( ){
    LumierePrincipaleOnOff ( );
    lumierePETITEOnOff ( );
    nourritureOnOff ( );
    filtre1OnOff ( );
    filtre2OnOff ( );
    filtre3OnOff ( );
    thermometreInterieurETEHIVER ( );
};


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

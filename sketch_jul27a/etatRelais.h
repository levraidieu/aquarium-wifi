#ifndef __etatRelaiss_H_
#define __etatRelaiss_H_

#include <Arduino.h>



//int LumierePrincipale = 0 ;
extern boolean LumierePrincipale  ;
extern boolean lumierePETITE  ;
extern boolean nourriture  ;
extern boolean filtre1  ;
extern boolean filtre2  ;
extern boolean filtre3      ;
extern boolean alarmeNiveauEau   ;
extern boolean voyant       ;
extern boolean thermometre  ;
extern boolean chauffeEau  ;
extern int     bouton       ;


extern  byte portSortie0 ;
extern  byte portSortie1 ;
extern  byte portSortie2 ;
extern  byte portSortie3 ;
extern  byte portSortie4 ;
extern  byte portSortie5 ;



//sms.h
//extern unsigned int localPort ;
//extern String sms;
//extern  client;
//extern WiFiClientSecure client;

int declarationDesSorties ( );





	#endif

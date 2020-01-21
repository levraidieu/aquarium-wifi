#ifndef __VARIABLES_H_
#define __VARIABLES_H_





//int LumierePrincipale = 0 ;
extern float sondeTemperatureChaudiere  ;
extern const int sondeTemperatureChaudierePin ;
extern const int sondeTemperatureBallonPin ;

extern WiFiServer webserver;
extern String header;





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

extern  byte portSortie5 ;
extern  byte portSortie4 ;


int declarationDesSorties ( );




  #endif

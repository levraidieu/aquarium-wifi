#include "ds3231.h"
struct ts t; //variable pour utilisation ds3231
#include <Wire.h>

#include "progHoraire3231.h"

#include "etatRelais.h" //variable commun declarer dans un fichier sur etat de sorti des relais

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

long time_millis_nourriture;
boolean nourriture_activation_millis;
boolean nourriture_activation_millis;

boolean lumiere_drapeau; // evite le conflit avec la prog jounaliere (s'active au debut de la journer)
long lumiere_drapeau_millis;
long time_millis_lumiere;                  //valeur millis + temps desactivation
long temp_desactivation_lumiere_en_millis; //temps en milliseconde de la desactivation de la lumiere
boolean lumiere_activation_millis;         //activation routine web

boolean lumiere_activation_journer;

boolean nourriture_drapeau = 0;

boolean filtre_drapeau = 0;
long time_millis_filtre;
long temp_desactivation_filtre_en_millis;
boolean filtre_activation_millis =0 ;


int drapeauTh = 6;
int drapeauTm = 0;

int re_init_drapeau24h()
{
  if (t.hour >= drapeauTh && t.hour <= (drapeauTh + 1))
  {
    if (millis() >= (lumiere_drapeau_millis + 86400000))
    {
      lumiere_drapeau_millis = millis();
      lumiere_drapeau = 1;
      filtre_drapeau = 1;
      nourriture_drapeau = 1;
    }
  }
}

int LumierePrincipaleOnOff()
{
  if (lumiere_drapeau == 1)
  {
    if ((t.hour >= LumierePrincipaleOnTh && t.min >= LumierePrincipaleOnTm) || (t.hour <= LumierePrincipaleOffTh && t.min >= LumierePrincipaleOffTm))
    {
      LumierePrincipale = 1;
    }
    else
    {
      LumierePrincipale = 0;
    }
  }
}

int lumierePETITEOnOff()
{
  if (lumiere_drapeau == 1)
  {
    if (lumiere_drapeau == 1)
    {
      if ((t.hour >= lumierePETITEOnTh && t.min >= lumierePETITEOnTm) || (t.hour <= lumierePETITEOffTh && t.min >= lumierePETITEOffTm))
      {
        lumierePETITE = 1;
      }
      else
      {
        lumierePETITE = 0;
      }
    }
  }
}

int nourritureOnOff()
{
  if (nourriture_drapeau == 1)
  {
    if ((t.hour >= nourritureOnTh && t.min >= nourritureOnTm) || (t.hour <= nourritureOffTh && t.min >= nourritureOffTm))
    {
      nourriture = 1;
    }
    else
    {
      nourriture = 0;
    }
  }
}

int filtre1OnOff()
{
  if (filtre_drapeau == 1)
  {
    if ((t.hour >= filtre1OnTh && t.min >= filtre1OnTm) || (t.hour <= filtre1OffTh && t.min >= filtre1OffTm))
    {
      filtre1 = 1;
    }
    else
    {
      filtre1 = 0;
    }
  }
}

int filtre2OnOff()
{
  if (filtre_drapeau == 1)
  {
    if ((t.hour >= filtre2OnTh && t.min >= filtre2OnTm) || (t.hour <= filtre2OffTh && t.min >= filtre2OffTm))
    {
      filtre2 = 1;
    }
    else
    {
      filtre2 = 0;
    }
  }
}

int filtre3OnOff()
{
  if (filtre_drapeau == 1)
  {
    if ((t.hour >= filtre3OnTh && t.min >= filtre3OnTm) || (t.hour <= filtre3OffTh && t.min >= filtre3OffTm))
    {
      filtre3 = 1;
    }
    else
    {
      filtre3 = 0;
    }
  }
}

int thermometreInterieurETEHIVER()
{
  if (lumiere_drapeau == 1)
  {
    if ((t.hour >= filtre3OnTh && t.min >= filtre3OnTm) || (t.hour <= filtre3OffTh && t.min >= filtre3OffTm))
    {
      filtre3 = 1;
    }
    else
    {
      filtre3 = 0;
    }
  }
}

int desactivationLumiere()
{
}

////////////////////////////////////////////////////////////////////
////////     nourriture web    /////////////////////////////////////
////////////////////////////////////////////////////////////////////

int nourritureWebMillis()
{
  time_millis_nourriture = (millis() + 3000);
  nourriture = 1;                   // relais nourriture en marche
  nourriture_activation_millis = 1; // activatio d'un drapeau nourriture
}

/*int nourritureWebJourner (){
  time_millis_nourriture = (millis() + 3000 );
  nourriture  = 1;
  nourriture_activation_millis = 1;
  nourriture_activation_journer = 1;
}
*/

int nourriture_exeptionnelle()
{
  if (nourriture_activation_millis == 1)
  { // verif si drapeau est active
    if ((millis() - time_millis_nourriture) < 0))
      {                 //verif si le temps c'est ecouler
        nourriture = 1; // si condition vrai relais activer
      }
    else if ((millis() - time_millis_nourriture) >= 0))
      { //si le temps est passer desativation du drapeau et du relais
        nourriture = 0;
        nourriture_activation_millis == 0;
      }
  }
}
////////////////////////////////////////////////////////////////////
///////////////  lumiere web  //////////////////////////////////////
////////////////////////////////////////////////////////////////////

int lumiereWebMillisoff()
{
  time_millis_lumiere = (millis() + temp_desactivation_lumiere_en_millis);
  lumierePETITE  =  LumierePrincipale = 0;
  lumiere_activation_millis = 1; //active  la routine web
  lumiere_drapeau = 0;           //desactive la routine principale
}

int lumiere_web_heure()
{
  if (lumiere_activation_millis == 1)
  {
    if ((millis() - time_millis_lumiere) <= 0))
      { //a tester si <= ou <
  lumierePETITE  =  LumierePrincipale = 0;
   lumiere_drapeau = 0;
      }
    else if ((millis() - time_millis_lumiere) > 0))
      { //a tester si >= ou >
        // lumiere  = 0;
        lumiere_activation_millis = 0;
        lumiere_drapeau = 1;
      }
  }
}

int lumiere_web_journer()
{
  if (lumiere_activation_journer == 1)
  {
    if ((millis() - time_millis_lumiere) < 0))
      {
        LumierePrincipale = 0;
        lumierePETITE = 0;
        lumiere_drapeau = 0;
      }
    else if ((millis() - time_millis_lumiere) >= 0))
      {
        //lumiere  = 0;
        //lumiere_activation_journer == 0;
        lumiere_drapeau = 0; // on laisse la prog journaliere gerer
        //lumiere_activation_millis == 0;

      }
  }
}


//////////////////////////////////////////////////////////////
//////// filtre  web /////////////////////////////////////////
//////////////////////////////////////////////////////////////


int filtreWebMillisoff()
{
  time_millis_filtre = (millis() + temp_desactivation_filtre_en_millis);
filtre1 = filtre2 = filtre3 =0;
  filtre_activation_millis = 1; //active  la routine web
  filtre_drapeau = 0;           //desactive la routine principale
}

int filtre_web_heure()
{
  if (filtre_activation_millis == 1)
  {
    if ((millis() - time_millis_filtre) <= 0))
      { //a tester si <= ou <
filtre1 = filtre2 = filtre3 =0;
      }
    else if ((millis() - time_millis_filtre) > 0))
      { //a tester si >= ou >
        // lumiere  = 0;
        filtre_activation_millis = 0;
        filtre_drapeau = 1;
      }
  }
}

int filtre_web_journer()
{
  if (filtre_activation_journer == 1)
  {
    if ((millis() - time_millis_filtre) < 0))
      {
filtre1 = filtre2 = filtre3 =0;
        filtre_drapeau = 0;
      }
    else if ((millis() - time_millis_filtre) >= 0))
      {

        filtre_drapeau = 0; // on laisse la prog journaliere gerer

      }
  }
}







int progHoraire()
{
  LumierePrincipaleOnOff();
  lumierePETITEOnOff();
  nourritureOnOff();
  filtre1OnOff();
  filtre2OnOff();
  filtre3OnOff();
  thermometreInterieurETEHIVER();
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

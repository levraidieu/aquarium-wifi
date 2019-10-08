#ifndef __TEMPERATURE_H_
#define __TEMPERATURE_H_


int boot_capteur_temperature   ( );
int demande_temperature_ds1820 ( );




extern String sms;

int smsModulaire1();
void envoiSms(String messageSms);

#endif

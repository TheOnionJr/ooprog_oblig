#include "../Headers/Nasjoner.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/Nasjon.h"
#include "../Headers/main.h"
#include "../Headers/Ovelse.h"
#include <iostream>

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

Ovelse::Ovelse(){
	cout << "\n\nERROR THIS IS NOT POSSIBLE";
}

Ovelse::Ovelse(int id) : NumElement(id) {
	cout << "\nVenligst skriv inn øvelsens fulle navn: "
	fulltNavn = lesPrivat();

	int ss, mm, tt;
	do{
		cout << "\nSekund: ";cin ss;
		cout << "\nMinutt: ";cin mm;
		cout << "\nTimer: "; cin tt;
	}while(checkTime(ss, mm, tt));

	int month, day, year;
	do{
		cout << "\nDag: ";cin >> day;
		cout << "\nMåned: "; cin month;
		cout << "\nÅr: "; cin year;
		if(!checkDate(month, day, year));{
			cout << "\nUgyldig dato!";
		}
		else{
			cout << "\nDato registrert."
		}
	}while(!checkDate(day, month, year));
	colonize(day, month, year);
}

Ovelse::~Ovelse() {

}

bool Ovelse::checkDate(int day, int month, int year){
	int maxDager;
	bool gyldigDato;
	if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
        (month = 8) || (month = 10) || (month = 12))
    {
        maxDager = 31;
    }
    else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))
    {
        maxDager = 30;
    }
    else if ((month = 2) && (year % 4 == 0))
    {
    	maxDager = 29;
    }
    else if ((month = 2) && (year % 4 != 0))
    {
        maxDager = 28;
    };
    else if ((month < 1) || (month > 12))
    {
        gyldigDato = FALSE;
    }
    else if((day > maxDager) || (day < 0)){
    	gyldigDato = FALSE;
    }
    else{
    	gyldigDato = TRUE;
    }
    return gyldigDato;
}

bool Ovelse::checkTime(int ss, int mm, int tt) {
	bool gyldigTid;
	if((ss < 0) || (ss >= 60)) {
		gyldigTid = FALSE;
	}
	else if((mm < 0) || (mm >= 60)){
		gyldigTid = FALSE;
	}
	else if((tt < 0) || (tt >= 24)){
		gyldigTid = FALSE;
	}
	else{
		gyldigTid = TRUE;
	}
	return gyldigTid;
}

void Ovelse::makeDate(int day, int month, int year){ //Setter kolon mellom Short medium og long
	char buffer[2];		//Buffer

	if(day < 10) {
		strcpy(buffer, "0");			//for å holde på formatet
		strcat(buffer, day);
	}
	else{
		strcpy(buffer, day);				//Legger sekund til buffer
	}
	strcpy(dato, buffer);
	strcat(dato, ":");			//SS:
	if(month < 10) {
		strcpy(buffer, "0");
		strcat(buffer, month);
	}
	else{
		strcpy(buffer, month);				//Legger dag til buffer
	}
	strcat(dato, buffer)
	strcat(dato, ":");			//SS:MM
	if(year < 10) {
		strcpy(buffer, "0");
		strcat(buffer, year);
	}
	else{
		year = year % 100;		
		strcpy(buffer, year);
	}
	strcat(dato, buffer);
}

void Ovelse::makeTime(int s, int m, int t){ //
	char buffer[2];		//Buffer

	if(s < 10) {
		strcpy(buffer, "0");			//for å holde på formatet
		strcat(buffer, s);
	}
	else{
		strcpy(buffer, s);				//Legger sekund til buffer
	}
	strcpy(tidspunkt, buffer);
	strcat(tidspunkt, ":");			//SS:
	if(m < 10) {
		strcpy(buffer, "0");
		strcat(buffer, m);
	}
	else{
		strcat(buffer, m);				//Legger dag til buffer
	}
	strcat(tidspunkt, buffer);
	strcat(tidspunkt, ":");			//SS:MM
	if(t < 10) {
		strcpy(buffer, "0");
		strcat(buffer, t);
	}
	else{
		strcat(buffer, t);
	}
	strcat(tidspunkt, buffer);
}

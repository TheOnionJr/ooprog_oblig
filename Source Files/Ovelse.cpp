#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "../Headers/Nasjoner.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/Nasjon.h"
#include "../Headers/main.h"
#include "../Headers/Ovelse.h"
#include "../Headers/ListTool2B.h"
#include "../Headers/Deltagere.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
 

Ovelse::Ovelse(){
	cout << "\n\nERROR THIS IS NOT POSSIBLE";
}

Ovelse::Ovelse(int id) : NumElement(id) {
	cout << "\nVenligst skriv inn øvelsens fulle navn: ";
	fulltNavn = lesPrivat();

	int ss, mm, tt;
	do{
		cout << "\nSekund: ";cin >> ss;		//Leser sekund
		cout << "\nMinutt: ";cin >> mm;		//Leser minutt
		cout << "\nTimer: "; cin >> tt;		//Leser timer
		if(!checkTime(ss, mm, tt)){
			cout << "\nUgyldig tidspunkt!";
		}
		else {
			makeTime(ss, mm, tt);
			cout << "\nTidspunktet er registrert.";
		}
	}while(checkTime(ss, mm, tt));

	int month, day, year;
	do{
		cout << "\nDag: ";cin >> day;		//Leser hvilken dag
		cout << "\nMåned: "; cin >> month;	//Leser hvilken måned
		cout << "\nÅr: "; cin >> year;		//Leser hvilket år
		year = year % 100;				   //year ikke overskriver 2 karakterer
		if(!checkDate(month, day, year)) {	//Sjekker om datoen er gyldig
			cout << "\nUgyldig dato!";		//Gir beskjed om ugyldig
		}
		else {
			makeDate(day, month, year);		//Lagrer datoen om den er gyldig
			cout << "\nDato registrert.";	//Gir beskjed om registrert
		}
	} while (!checkDate(day, month, year));
}

Ovelse::~Ovelse() {

}

void Ovelse::endre() {
	cout << "\nVenligst skriv inn øvelsens fulle navn: ";
	fulltNavn = lesPrivat();

	int ss, mm, tt;
	do{
		cout << "\nSekund: ";cin >> ss;		//Leser sekund
		cout << "\nMinutt: ";cin >> mm;		//Leser minutt
		cout << "\nTimer: "; cin >> tt;		//Leser timer
		if(!checkTime(ss, mm, tt)){
			cout << "\nUgyldig tidspunkt!";
		}
		else {
			makeTime(ss, mm, tt);
			cout << "\nTidspunktet er registrert.";
		}
	}while(checkTime(ss, mm, tt));

	int month, day, year;
	do{
		cout << "\nDag: ";cin >> day;		//Leser hvilken dag
		cout << "\nMåned: "; cin >> month;	//Leser hvilken måned
		cout << "\nÅr: "; cin >> year;		//Leser hvilket år
		year = year % 100;				   //year ikke overskriver 2 karakterer
		if(!checkDate(month, day, year)) {	//Sjekker om datoen er gyldig
			cout << "\nUgyldig dato!";		//Gir beskjed om ugyldig
		}
		else {
			makeDate(day, month, year);		//Lagrer datoen om den er gyldig
			cout << "\nDato registrert.";	//Gir beskjed om registrert
		}
	} while (!checkDate(day, month, year));
}

int Ovelse::returnID(){
	return number;
}

void Ovelse::display() {
	cout << "\nID: " << number;
	cout << "\nFullt Navn: " << fulltNavn;
	cout << "\nTidspunkt: " << tidspunkt;
	cout << "\nDato: " << dato;
	cout << "Antall Deltagere: " << antDeltagere;
	// Display deltagere
	// Display resultater
}

void Ovelse::nyDeltager(){
	int id = les("\nDeltagerens ID: ", DIVMIN, DIVMAX);
	bool done = false;
	for(int i = 0; i <= MAXDELTAGERE; i++) {
		if((startListe[i] == 0) && (done == false) && (deltagere->finnesDeltager(id))) {
			startListe[i] = id;
			done = true;
		}
		else if(!deltagere->finnesDeltager(id)){
			cout << "\nDenne deltageren finnes ikke!";
			done = true;
		}
	}
}
bool Ovelse::checkDate(int day, int month, int year){
	int maxDager;
	bool gyldigDato = true;
	if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
        (month = 8) || (month = 10) || (month = 12)) //Om måneden har 31 dager
    {
        maxDager = 31;
    }
    else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))	
    {												//Eller 30 dager
        maxDager = 30;
    }
    else if ((month = 2) && (year % 4 == 0))		//Eller februar og skuddår
    {
    	maxDager = 29;
    }
    else if ((month = 2) && (year % 4 != 0))		//Eller ikke
    {
        maxDager = 28;
    }
    if ((month < 1) || (month > 12))			//Om måneden finnes
    {
        gyldigDato = false;
    }
    else if((day > maxDager) || (day < 0)){			//Om ikke for mange dager
    	gyldigDato = false;
    }
    return gyldigDato;
}

bool Ovelse::checkTime(int ss, int mm, int tt) {
	bool gyldigTid = true;
	if((ss < 0) || (ss >= 60)) {					//Om !innenfor ett minutt
		gyldigTid = false;
	}
	else if((mm < 0) || (mm >= 60)){				//Om !innnenfor en time
		gyldigTid = false;
	}
	else if((tt < 0) || (tt >= 24)){				//Om !innenfor ett døgn
		gyldigTid = false;
	}
	return gyldigTid;
}

void Ovelse::makeDate(int day, int month, int year){ //Setter kolon mellom Short medium og long
	char buffer[2];		//Buffer

	if(day < 10) {
		strcpy_s(tidspunkt, 8, "0");			//legger til '0' for å holde formatet
		_itoa_s(day, buffer, 2, 10);			//int -> char
	}
	else if(day >= 10){
		_itoa_s(day, buffer, 2, 10);			//Legger sekund til buffer
	}
	strcpy_s(tidspunkt, 8, buffer);			//Legger over fra buffer til char array
	strcat_s(tidspunkt, 8, ":");				//Legger til ':' for format SS:MM:TT
	if(month < 10) {
		strcat_s(tidspunkt, 8, "0");			//legger til '0' for å holde formatet
		_itoa_s(month, buffer, 2, 10);			//int -> char
	}
	else{
		_itoa_s(month, buffer, 2, 10);		//Legger til minutt i buffer
	}
	strcat_s(tidspunkt, 8, buffer);			//Legger over fra buffer til char array
	strcat_s(tidspunkt, 8, ":");				//Legger til ':' for format SS:MM:TT
	if(year < 10) {
		strcat_s(tidspunkt, 8, "0");			//Legger til '0' for å holde formatet
		_itoa_s(year, buffer, 2, 10);			//int -> char
	}
	else{
		_itoa_s(year, buffer, 2, 10);			//Legger til timer i buffer
	}
	strcat_s(tidspunkt, 8, buffer);			//Legger over fra buffer til char array
}

void Ovelse::makeTime(int s, int m, int t){ //
	char buffer[2];		//Buffer

	if(s < 10) {
		strcpy_s(tidspunkt, 8, "0");			//legger til '0' for å holde formatet
		_itoa_s(s, buffer, 2, 10);			//int -> char
	}
	else if(s > 10){
		_itoa_s(s, buffer, 2, 10);			//Legger sekund til buffer
	}
	strcpy_s(tidspunkt, 8, buffer);			//Legger over fra buffer til char array
	strcat_s(tidspunkt, 8, ":");				//Legger til ':' for format SS:MM:TT
	if(m < 10) {
		strcat_s(tidspunkt, 8, "0");			//legger til '0' for å holde formatet
		_itoa_s(m, buffer, 2, 10);			//int -> char
	}
	else{
		_itoa_s(m, buffer, 2, 10);			//Legger til minutt i buffer
	}
	strcat_s(tidspunkt, 8, buffer);			//Legger over fra buffer til char array
	strcat_s(tidspunkt, 8, ":");				//Legger til ':' for format SS:MM:TT
	if(t < 10) {
		strcat_s(tidspunkt, 8, "0");			//Legger til '0' for å holde formatet
		_itoa_s(t, buffer, 2, 10);			//int -> char
	}
	else{
		_itoa_s(t, buffer, 2, 10);			//Legger til timer i buffer
	}
	strcat_s(tidspunkt, 8, buffer);			//Legger over fra buffer til char array
}

void Ovelse::ovelseMeny() {
	char kommando;
	deltagerMeny();
	kommando = lesKommando();
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':
			break;
		case 'E':
			break;
		case 'F':
			break;
		case 'A':
			break;
		case 'L':
			break;
		case 'R':
			break;
		default:
			break;
		}
		deltagerMeny();
		kommando = lesKommando();
	}
}

char* Ovelse::filnavn(int id) {
	char filnavn[FILLEN];
	char buffer[FILLEN];

	_itoa(id, buffer, 10);
	strcpy(filnavn, "OV");
	strcat(filnavn, buffer);
	strcat(filnavn, ".RES");
	return(filnavn);
}

void Ovelse::finnes(int id) {
	int tempSiste;
	ifstream innfil(filnavn(id));

	innfil >> tempSiste;
	if ((innfil && (tempSiste <= 0)) || !innfil)
		nyResList(id);
	else
		cout << "Lista finnes allerede!";
}
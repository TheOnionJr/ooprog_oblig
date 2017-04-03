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
#include "../Headers/Deltager.h"
#include "../Headers/Gren.h"
#include "../Headers/Grener.h"
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
	// Display resultater
}

void Ovelse::nyDeltager(){
	int id = les("\nDeltagerens ID: ", DIVMIN, DIVMAX);
	bool finnes = false;
	for(int i = 0; i <= MAXDELTAGERE; i++) {	// Sjekker om listen er tom
		if(startListe[i] != 0) {
			finnes = true;						//Om listen ikke er tom
		}
	}
	if(!startListe) {						//Lager ny liste
		char kommando = 'N';
		int i = 0;
		while(kommando != 'Y'){					//Om bruker ikke vil avslutte
			cout << "\nSkriv inn deltagerens ID: "; cin >> startListe[i];
			while(!deltagere->finnesDeltager(startListe[i]) && startListe[MAXDELTAGERE] != 0){	//Om deltageren ikke finnes
				cout << "\nDenne deltageren finnes ikke!";
				cout << "\nSkriv inn deltagerens ID: "; cin >> startListe[i];
			}
			if(antDeltagere == MAXDELTAGERE-1){				// Om listen er full
				cout << "\nListen er nå full";
				kommando = 'Y';
			}
			else{											//Om listen ikke er full
				i++;
				antDeltagere++;
				cout << "\nVil du avslutte? (y/n): ";
				kommando = lesKommando();
			}
		}
		ofstream utfil(filnavnSTA(number));
		for(int i = 0; i < antDeltagere; ){
			utfil << startListe[i] << "\n";					//Skriver ID til fil
		}
	}
	else{
		cout << "\nDet finnes allerede en startliste!";
	}
}

void Ovelse::endreListe() {
	int id = les("\nDeltagerens ID: ", DIVMIN, DIVMAX);
	bool done = false;
	if(!score){
		for(int i = 0; i <= MAXDELTAGERE; i++) {
			if((startListe[i] == 0) && (done == false) && (deltagere->finnesDeltager(id))) {
				startListe[i] = id;
				done = true;
				antDeltagere++;
			}
			else if(!deltagere->finnesDeltager(id)){
				cout << "\nDenne deltageren finnes ikke!";
				done = true;
			}
		}
	}
	else{
		cout << "\nDet finnes allerede en resultatliste. Det er ikke mulig å endre på deltagerlisten!";
	}
}

void Ovelse::lesInnStartListe() {
	ifstream innfil(filnavnSTA(number));
	if(innfil){
		for(int i = 0; i <=antDeltagere; i++){
			innfil >> startListe[i];
		}
	}
}

void Ovelse::skrivStartListe() {
	lesInnStartListe();
	for(int i = 0; i <= antDeltagere; i++){
		deltagere->skrivForOvelse(startListe[i]);
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


char* Ovelse::filnavnSTA(int id) {				//Funksjon som genererer filnavn for en ovelse.
	char filnavn[FILLEN];					//Filnavnet.
	char buffer[FILLEN];					//Mellomlagring.

	_itoa(id, buffer, 10);					//Skriver om inten id til char-mellomlagringa.
	strcpy(filnavn, "OV");					//Kopierer OV i starten av filnavn.
	strcat(filnavn, buffer);				//appender nummeret til ovelsen bak 'OV' i filnavn.
	strcat(filnavn, ".STA");				//appender '.RES' på slutten av filnavn.
	return(filnavn);						//Returnerer filnavn.
}

char* Ovelse::filnavnRES(int id) {				//Funksjon som genererer filnavn for en ovelse.
	char filnavn[FILLEN];					//Filnavnet.
	char buffer[FILLEN];					//Mellomlagring.

	_itoa(id, buffer, 10);					//Skriver om inten id til char-mellomlagringa.
	strcpy(filnavn, "OV");					//Kopierer OV i starten av filnavn.
	strcat(filnavn, buffer);				//appender nummeret til ovelsen bak 'OV' i filnavn.
	strcat(filnavn, ".RES");				//appender '.RES' på slutten av filnavn.
	return(filnavn);						//Returnerer filnavn.
}

void Ovelse::finnes(int id) {				//Funksjon som sjekker om fil finnes/er i bruk.
	int tempSiste;							//Mellomlagring.
	ifstream innfil(filnavnRES(id));			//Henter inn riktig fil.

	innfil >> tempSiste;					//Leser inn sistebrukt.
	if ((innfil && (tempSiste <= 0)) || !innfil)	//Sjekker om filen finnes og  ikke er i bruk eller om den ikke finnes.
		nyResList(id);						//Kaller funksjon for å lage ny liste.
	else
		cout << "Lista finnes allerede!";	//Feilmelding hvis lista finnes og er i bruk.
}

void Ovelse::nyResList(int id) {			//Lager ny resultatliste.
	hentPs();								//Kaller funksjon som henter inn enumen 'ps'.

	for (int i = 0; i >= antDeltagere; i++) {	//Teller gjennom antall deltagere.
		Deltager* hjelpeObjekt = deltagere->plsHelp(startListe[i]);	//Lager hjelpeobjekt.
		strcpy(nasj[i], hjelpeObjekt->returnKortNavn());			//Henter ut nasjonaliteten til deltager nr i.
		strcpy(deltNavn[i], hjelpeObjekt->returnNavn());			//Henter ut navnet til deltager i.

		switch(ps) {							//Switch etter hvilken enum som er i bruk.
			case(poengH):						//Poengtype: hopp. Form: x.
				cout << "\nHvor mange poeng fikk " << deltNavn[i] 
					 << " fra " << nasj[i] <<  " ? (x) ";				//Spør hvor mange poeng deltager fra land fikk.
				cin >> score[i];										//Leser inn poeng.
				break;
			case(poengK):						//Poengtype: kunstløp. Form: xx.
				cout << "\nHvor mange poeng fikk " << deltNavn[i] 
					 << " fra " << nasj[i] << " ? (x): ";				//Spør hvor mange poeng deltager fra land fikk.
				cin >> score[i];										//Leser inn poeng.
				break;
			case(tidTi):						//Tid med tideler.
				cout << "\nHvilken tid fikk " << deltNavn[i]			
					 << " fra " << nasj[i] << "? (på formen mmsst): ";	//Spør hvilken tid deltager fra land fikk.
				cin >> score[i];										//Leser inn tid.
				break;
			case(tidHu):						//Tid med hundredeler.
				cout << "\nHvilken tid fikk " << deltNavn[i]			
					 << " fra " << nasj[i] << "? (på formen mmssth): ";	//Spør hvilken tid deltager fra land fikk.
				cin >> score[i];										//Leser inn tid.
				break;
			case(tidTu):						//Tid med tusendeler.
				cout << "\nHvilken tid fikk " << deltNavn[i] 
					 << " fra " << nasj[i] << "? (på formen mmsstht): ";//Spør hvilken tid deltager fra land fikk.
				cin >> score[i];										//Leser inn tid.
				break;
		}
		sisteBrukt++;								//Teller opp sisteBrukt.
		sorter();									//Sorterer array.
		deltagere->thankYou(hjelpeObjekt);			//Legger tilbake hjelpeobjektet i deltagerlista.
	}
}

void Ovelse::sorter() {			//Funksjon som går gjennom arrayen og sorterer etter medaljeverdi.
	for (int i = sisteBrukt; i >= 0; i--) {				//Går gjennom arrayen.	
		if (score[i] >= score[i - 1]) {					//Sjekker om i-1 er større.
			char temp[NASJKORTLEN];						//Mellomlagring nasjonsforkortelse.
			char tempNvn[NVNLEN];						//Mellomlagring navn.
			int tempi;									//Mellomlagring score.b

			strcpy(temp, deltNavn[i]); strcpy(tempNvn, nasj[i]); tempi = score[i];						//Kopierer i inn i mellomlagring.
			strcpy(deltNavn[i], deltNavn[i - 1]); strcpy(nasj[i], nasj[i - 1]); score[i] = score[i - 1];	//Setter i til i-1.
			strcpy(deltNavn[i - 1], temp); strcpy(nasj[i-1], temp); score[i - 1] = tempi;	//Kopierer fra mellomlagring til i.
		}
	}
}

void Ovelse::skrivResTilFil() {						//Funksjon som skriver resultatlista til fil.
	ofstream utfil(filRES);							//Finner filen.

	if (utfil) {									//Sjekker om filen finnes/blir opprettet.
		utfil << sisteBrukt;						//Skriver sisteBrukt til starten av filen.
		for (int i = 0; i >= sisteBrukt; i++) {		//Teller gjennom antall entries i filen.
			utfil << nasj[i] << '\n';					//Skriver nasjon.
			utfil << score[i] << '\n';					//Skriver score.
			utfil << deltNavn[i] << "\n\n";				//Skriver deltagernavnet. + hopper over en linje.
		}
	}
}

void Ovelse::lesResFraFil() {						//Leser resultatliste fra fil.
	ifstream innfil(filRES);						//Finner filen.

	if (innfil) {									//Hvis filen finnes...
		innfil >> sisteBrukt; innfil.ignore();			//Leser inn sisteBrukt og hopper til neste linje.
		for (int i = 0; i >= sisteBrukt; i++) {		//Teller gjennom alle entries i filen.
			innfil.getline(nasj[i], NASJKORTLEN + 1);	//Leser inn nasjonen.
			innfil >> score[i]; innfil.ignore();		//Leser inn score.
			innfil.getline(deltNavn[i], NVNLEN + 1);	//Leser inn deltagernavnet.
			innfil.ignore();							//Ignorerer en linje.
		}
	}
}


void Ovelse::hentPs() {								//Henter enumen ps.
	Gren* hjelpeGren = grener->plsHelp(grenNavn);		//grenNavn = navnet som blir hentet inn når man kaller 'O'.
	ps = (hjelpeGren->returnPt());
	grener->thankYou(hjelpeGren);
}
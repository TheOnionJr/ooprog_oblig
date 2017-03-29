#include "../Headers/Nasjoner.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/Nasjon.h"
#include "../Headers/main.h"
#include <iostream>

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

void Nasjoner::nasjonsmeny() {
	char kommando;
	nasjonerMeny();
	kommando = lesKommando();
	while (kommando != 'X') {
		switch (kommando)
		{
		case 'N':					//Legge til en ny nasjon
			nyNasjon();
			break;
		case 'E': 					//Endre eksisterende nasjon
			endreNasjon();
			break;
		case 'A':					//Alle hoveddata om alle nasjoner
			nasjonsliste->displayList();
			break;
		case 'T': 					//Skriv en nasjons deltagertropp
			visNasjonsDeltagere();
			break;
		case 'S': 					//Skriver alle data om en nasjon
			visNasjonsInfo();
			break;
		case 'X': break;			//Gå tilbake
		default:
			nasjonerMeny();
			break;
		}
		nasjonerMeny();
		kommando = lesKommando(); //Bruker skriver her kommando for nasjonsmeny
	}
}

void Nasjoner::nyNasjon() {
	char id[NASJKORTLEN];
	char* nasjkort;
	les("\nVennligst skriv landets forkortelse: ", id, NASJKORTLEN);
	nasjkort = new char[strlen(id) + 1];
	strcpy_s(nasjkort, NASJKORTLEN, id);
	if (!nasjonsliste->inList(nasjkort)) {	//Om landet ikke finnes
		nasjonsliste->add(new Nasjon(nasjkort));//lager nytt land
	}
	else {	//Om landet finnes fra før
		cout << "\nNasjonen eksisterer allerede.";
	}
}

void Nasjoner::endreNasjon() {
	char id[NASJKORTLEN];
	char kommando = '0';
	les("\nForkortelsen til den nasjonen du vil endre: ", id, NASJKORTLEN);
	if (nasjonsliste->inList(id)) {	//Om landet finnes
		Nasjon* hjelpenasjon = (Nasjon*)nasjonsliste->remove(id);
		while (kommando != 'X') {
			endreNasjonerMeny();			//Endringsmeny
			kommando = lesKommando();		//Leser kommando
			hjelpenasjon->endre(kommando);	//Utfører kommando
											//Looper til bruker skriver kommando 'X'
		}
		nasjonsliste->add(hjelpenasjon);
		kommando = 'V';		//S� bruker kan velge nye ting
	}
	else
		cout << "\nFant ikke nasjonen.";
}

void Nasjoner::visNasjonsDeltagere() {
	char id[NASJKORTLEN];
	les("\nForkortelsen til den nasjoner du vil vise: ", id, NASJKORTLEN);
	if (nasjonsliste->inList(id)) {
		Nasjon* hjelpenasjon = (Nasjon*)nasjonsliste->remove(id);
		hjelpenasjon->displayDeltagere();
		nasjonsliste->add(hjelpenasjon);
	}
}

void Nasjoner::visNasjonsInfo() {
	char id[NASJKORTLEN];
	while (!nasjonsliste->inList(id)) { //Sjekker om nasjon finnes
		les("\nLandets forkortelse", id, NASJKORTLEN);
	}
	nasjonsliste->displayElement(id);	//Skriver ut data
}

bool Nasjoner::inList(const char* t) {
	return(nasjonsliste->inList(t));
}
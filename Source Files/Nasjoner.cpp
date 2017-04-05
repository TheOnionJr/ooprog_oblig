#include "../Headers/Nasjoner.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/Nasjon.h"
#include "../Headers/main.h"
#include <iostream>
#include <fstream>

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
		case 'X': break;			//G√• tilbake
		default:
			break;
		}
		nasjonerMeny();				//Skriver nasjonsmeny
		kommando = lesKommando();	//Bruker skriver her kommando for nasjonsmeny
	}
}

void Nasjoner::nyNasjon() {			//Lager en ny nasjon, og legger den til i lista
	char id[NASJKORTLEN];
	char* nasjkort;
	les("\nVennligst skriv landets forkortelse: ", id, NASJKORTLEN);
	nasjkort = new char[strlen(id) + 1];
	strcpy_s(nasjkort, NASJKORTLEN, id);
	if (!nasjonsliste->inList(nasjkort)) {	//Om landet ikke finnes
		nasjonsliste->add(new Nasjon(nasjkort));//lager nytt land
	}
	else {	//Om landet finnes fra f√∏r
		cout << "\nNasjonen eksisterer allerede.";
	}
}

void Nasjoner::endreNasjon() {		//Endrer en nasjons informasjon
	char id[NASJKORTLEN];
	char kommando = '0';			//Initierer for Â kunne entre while-l¯kke
	les("\nForkortelsen til den nasjonen du vil endre: ", id, NASJKORTLEN);
	if (nasjonsliste->inList(id)) {	//Om landet finnes
		Nasjon* hjelpenasjon = (Nasjon*)nasjonsliste->remove(id);
		while (kommando != 'X') {
			endreNasjonerMeny();			//Endringsmeny
			kommando = lesKommando();		//Leser kommando
			hjelpenasjon->endre(kommando);	//Utf√∏rer kommando
											//Looper til bruker skriver kommando 'X'
		}
		nasjonsliste->add(hjelpenasjon);
	}
	else
		cout << "\nFant ikke nasjonen.";
}

void Nasjoner::visNasjonsDeltagere() {		//Viser alle deltagere til en nasjon
	char id[NASJKORTLEN];
	les("\nForkortelsen til den nasjoner du vil vise: ", id, NASJKORTLEN);
	if (nasjonsliste->inList(id)) {			//Hvis nasjonen eksisterer
		Nasjon* hjelpenasjon = (Nasjon*)nasjonsliste->remove(id);	//Henter nasjonen fra lista
		hjelpenasjon->displayDeltagere();	//Skriver alle deltagerene til nasjonen pÂ skjermen
		nasjonsliste->add(hjelpenasjon);	//Legger nasjonen tilbake i lista
	}
	else
		cout << "\nFant ikke nasjonen.";
}

void Nasjoner::visNasjonsInfo() {			//Viser detaljert informasjon om en nasjon, 
											//og hvor mange deltagere nasjonen har
	char id[NASJKORTLEN];
	les("\nLandets forkortelse", id, NASJKORTLEN);	//Leser brukerens valg
	if (nasjonsliste->inList(id)) {			//Sjekker at nasjonen eksisterer
		Nasjon* hjelpeobjekt = (Nasjon*)nasjonsliste->remove(id);	//Henter nasjonen fra lista
		hjelpeobjekt->display();			//Viser hovedinfo
		hjelpeobjekt->displayKontakt();		//Viser info om kontaktperson
		cout << "\nNasjonen har " << hjelpeobjekt->returnAntDeltagere() << " deltager(e).";
		nasjonsliste->add(hjelpeobjekt);	//Viser antall deltagere
	}
	else									//Dersom nasjonen ikke blir funnet
		cout << "\nFant ikke nasjonen.";
}

bool Nasjoner::inList(const char* t) {		//Returnerer om nasjonen eksisterer i den private lista, da man ikke kan sjekke dette globalt
	return(nasjonsliste->inList(t));
}

void Nasjoner::leggTilDeltager(char* t) {	//Forteller et nasjonsobjekt at det skal plusse pÂ 1 i sin private "antDeltagere"
	Nasjon* hjelpeobjekt = (Nasjon*) nasjonsliste->remove(t);
	hjelpeobjekt->leggTilDeltager();
	nasjonsliste->add(hjelpeobjekt);
}

void Nasjoner::fjernDeltager(char* t) {		//Forteller et nasjonsobjekt at det skal trekkes fra 1 i sin private "antDeltagere"
	Nasjon* hjelpeobjekt = (Nasjon*)nasjonsliste->remove(t);
	hjelpeobjekt->fjernDeltager();
	nasjonsliste->add(hjelpeobjekt);
}

void Nasjoner::skrivTilFil() {
	ofstream utfil("NASJONER.DTA");
	if (utfil) {
		utfil << nasjonsliste->noOfElements() << endl;
		for (int i = 1; i <= nasjonsliste->noOfElements(); i++) {
			Nasjon* hjelpeobjekt = (Nasjon*)nasjonsliste->removeNo(i);
			hjelpeobjekt->skrivTilFil(utfil);
			nasjonsliste->add(hjelpeobjekt);
		}
	}
}

void Nasjoner::lesFraFil() {
	ifstream innfil("NASJONER.DTA");
	if (innfil) {
		int antNasjoner;
		innfil >> antNasjoner;
		for (int i = 0; i <= antNasjoner; i++) {
			char id[NASJKORTLEN]; 
			innfil.ignore();  innfil.getline(id, NASJKORTLEN);
			nasjonsliste->add(new Nasjon(id, innfil));
		}
	}
}
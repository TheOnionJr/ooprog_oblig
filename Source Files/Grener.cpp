#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include "../Headers/enumer.h"
#include "../Headers/Const.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Grener.h"
#include "../Headers/Gren.h"
#include <iostream>
using namespace std;

void Grener::grenerMeny() {
	char kommando;
	grenMeny();
	kommando = lesKommando();		//Leser kommando.
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':				//Oppretter ny gren.
			nyGren();
			break;
		case 'E':				//Endrer navnet på en gren.
			endreGren();
			break;
		case 'A':				//Skriver hoveddata om alle grener.
			skrivHovedGren();
			break;
		case 'S': break;
		case 'X': break;
		default:  cout << "Ukjent svar, prøv igjen!"; break;	//Feilmelding.
		}
		grenMeny();
		kommando = lesKommando(); //Bruker skriver her kommando for gren-meny
	}
	
}
	

void Grener::nyGren() {
	char tempNvn[NVNLEN];

	les("Grenens navn", tempNvn, NVNLEN);	//Leser inn navnet til grenen.
	if (!grenliste->inList(tempNvn))			//Sjekker om finnes allerede.
		grenliste->add(new Gren(tempNvn));	//Legger til grenen.
	else									//Feilmelding.
		cout << "En gren med det navnet finnes allerede!";
}

void Grener::endreGren() {
	char grenNvn[NVNLEN];	//Temp. for sammenligning
							//Spør om navnet på gren som skal endres.
	les("Navnet på grenen du vil endre", grenNvn, NVNLEN);
	//Hvis grenen finnes...
	if (grenliste->inList(grenNvn)) {
		Gren* hjelpeGren = (Gren*)grenliste->remove(grenNvn);
		hjelpeGren->endre();	//Fjerner, endrer, og adder
		grenliste->add(hjelpeGren);//grenen i lista.
	}
	else {				//Feilmeld.
		cout << "\nFant ikke en gren med det navnet!\n";
	}
}

void Grener::skrivHovedGren() {
	grenliste->displayList();
}

//void Grener::skrivGren() {}

void Grener::ovelsemeny() {
	char kommando;
	char* navn;
	char buffer[NVNLEN];
	cout << "\nHva er ovelsens navn?:\t";
	cin >> buffer;
	navn = new char[strlen(buffer) + 1];
	strcpy(navn, buffer);
	ovelseMeny();
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
		ovelseMeny();
		kommando = lesKommando();
	}
}

void Grener::ovelseMeny() {
	cout << "\n\nMENYVALG FOR ØVELSER:";
	cout << "\n\tN: Registrer ny øvelse.";
	cout << "\n\tE:	Endre en øvelse.";
	cout << "\n\tF: Fjern en øvelse.";
	cout << "\n\tA: Skriv hoveddata om alle øvelser.";
	cout << "\n\tL: Deltagerlister.";
	cout << "\n\tR: Resusltatlister.";
	cout << "\n\tX: Gå tilbake.";
}

Gren* Grener::plsHelp(char* id) {
	return((Gren*)grenliste->remove(id));
}

void Grener::thankYou(Gren* hjelpeobjekt) {
	grenliste->add(hjelpeobjekt);
}
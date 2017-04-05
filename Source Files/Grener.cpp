#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include "../Headers/enumer.h"
#include "../Headers/Const.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Grener.h"
#include "../Headers/Gren.h"
#include <iostream>
#include <fstream>
using namespace std;

void Grener::grenerMeny() {			//Menyvalg for grener
	char kommando;
	grenMeny();						//Skriver grenmeny
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
		case 'S': 
			displayAllGren();
			break;
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
	cout << "\nHva er grenens navn?:\t";
	cin >> buffer;
	navn = new char[strlen(buffer) + 1];
	strcpy(navn, buffer);
	if (grenliste->inList(navn)) {
		Gren* hjelpeobjekt = (Gren*)grenliste->remove(navn);
		ovelseMeny();
		kommando = lesKommando();
		while (kommando != 'X') {
			switch (kommando) {
			case 'N':
				hjelpeobjekt->nyOvelse();
				break;
			case 'E':
				hjelpeobjekt->endreOvelse();
				break;
			case 'F':
				hjelpeobjekt->slettOvelse();
				break;
			case 'A':
				hjelpeobjekt->displayOvelser();
				break;
			case 'L':
				hjelpeobjekt->startListe();
				break;
			case 'R':
				hjelpeobjekt->resultatListe();
				break;
			default:
				break;
			}
			ovelseMeny();
			kommando = lesKommando();
		}
		grenliste->add(hjelpeobjekt);
	}
	else
		cout << "\nFant ikke grenen.";
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

void Grener::displayAllGren() {
	char* navn;
	char buffer[STRLEN];
	les("\nHvilken gren vil du se info om?:\t", buffer, STRLEN);
	navn = new char[strlen(buffer + 1)];
	strcpy(navn, buffer);
	if (grenliste->inList(navn)) {
		Gren* hjelpeobjekt = (Gren*)grenliste->remove(navn);
		hjelpeobjekt->display();
		hjelpeobjekt->displayOvelser();
		grenliste->add(hjelpeobjekt);
	}
	else
		cout << "\nFant ikke gren.";
}

void Grener::skrivTilFil() {
	ofstream utfil("GRENER.DTA");
	if (utfil) {
		utfil << grenliste->noOfElements() << endl;
		for (int i = 1; i <= grenliste->noOfElements(); i++) {
			Gren* hjelpeobjekt = (Gren*)grenliste->removeNo(i);
			hjelpeobjekt->skrivTilFil(utfil);
			grenliste->add(hjelpeobjekt);
		}
	}
}

void Grener::lesFraFil() {
	ifstream innfil("GRENER.DTA");
	if (innfil) {
		int sisteBrukt;
		innfil >> sisteBrukt;
		for (int i = 0; i < sisteBrukt; i++) {
			char text[NVNLEN]; innfil >> text;
			grenliste->add(new Gren(text, innfil));
		}
	}
}
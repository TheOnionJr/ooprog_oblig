#include "../Headers/headere.h"
using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

										//Constructor.
Gren::Gren() : TextElement {

}

										//Constructor m/navn-parameter.
Gren::Gren(char tempNavn[NVNLEN]) : TextElement(tempNavn) {
	char svar;

	strcpy(navn, tempNavn);				//Setter navn fra parameter.
										//Sp�r om hvordan prestasjon m�les.
	cout << "Hvordan m�les prestasjon i grenen? 't'=tid, 'p'=poeng: ";
	
	do {
		svar = lesKommando();			//Leser inn og upcaser.
		switch (svar) {
			case'T': pt = tid;	 break;	//Setter enum til tid.
			case'P': pt = poeng; break;	//Setter enum til poeng.
			default:					//Feilmelding.
				cout << "Ukjent svar, skriv 'T' for tid, eller 'P' for poeng.";
				break;
		}								//do-whie som looper til godkjent svar.
	} while (svar != 'T' && svar != 'P');
}

Gren::~Gren(){							//Destructor
	delete navn, pt, sisteBrukt, ovelseNr;	//Sletter alle data.
}

										//Funksjon for � endre data i en gren.
void Gren :: endre() {
	char tempNavn[NVNLEN];
	les("Grenens nye navn", tempNavn, NVNLEN);
	strcpy(navn, tempNavn);
	cout << "\nNavnet er endret, det er n� " << navn << ".";
}

										//Skriver alle data om en gren.
void Gren::display() {
	cout << "\nNavn: \t" << navn;		//Navn.

	cout << "\nTid/poeng: ";			//Om prestasjonsm�ling er tid/poeng.
	if (pt = tid) cout << "tid.";
	else		  cout << "poeng.";

	cout << "\nAntall �velser: " << sisteBrukt;		//Antall �velser i grenen.
}
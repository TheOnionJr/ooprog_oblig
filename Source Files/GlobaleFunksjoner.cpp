#include "headere.h"

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 


//Generelle funksjoner.
void skrivMeny() {
	cout << "\n\nTILGJENGELIGE VALG:";
	cout << "\n\tN: Nasjoner.";
	cout << "\n\tD: Deltakere";
	cout << "\n\tG: Grener";
	cout << "\n\tO: Ovelser";
	cout << "\n\tM: Medaljeoversikt";
	cout << "\n\tP: Poengoversikt";
	cout << "\n\tX: Avslutt program";
}

char les() {
	char ch;
	cout << "\nKommando: ";
	cin >> ch; cin.ignore();
}

char lesKommando() {
	char ch;
	cout << "\nKommando: ";
	cin >> ch; cin.ignore();
	toupper(ch);
	return(ch);
}

int les(const char * t, const int min, const int max)
{
	int tall;
	do {
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> tall; cin.ignore();
	} while (tall < min || tall > max);
	return 0;
}

void les(const char t[], char s[], const int LEN) {
	do {
		cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);           //  Sjekker at tekstlengden er ulik 0.
}


//Nasjoner-funksjoner.
void nasjonerMeny() {
	cout << "\n\nMENYVALG FOR NASJONER:";
	cout << "\n\tN: Registrer en ny nasjon.";
	cout << "\n\tE: Endre en nasjon.";
	cout << "\n\tA: Skriv hoveddataene alle nasjoner.";
	cout << "\n\tT: Skriv en nasjons deltagertropp.";
	cout << "\n\tS: Skriv alle data om en nasjon.";
}

//Deltager-funksjoner.
void deltagerMeny() {
	cout << "\n\nMENYVALG FOR DELTAGERE:";
	cout << "\n\tN: Registrer ny deltager.";
	cout << "\n\tE: Endre en deltager.";
	cout << "\n\tA: Skriv hoveddataene om alle deltagere.";
	cout << "\n\tS: Skriv alle data om en gitt deltager.";
}

//Gren-funksjoner
void grenMeny() {
	cout << "\n\nMENYVALG FOR GRENER";
	cout << "\n\tN: Registrer ny gren.";
	cout << "\n\tE: Endre en gren.";
	cout << "\n\tA: Skriv hoveddataene om alle grener.";
	cout << "\n\tS: Skriv alle data om en gitt gren.";
}

//Ovelse-funksjoner
void ovelseMeny() {
	cout << "\n\nMENYVALG FOR OVELSER";
	cout << "\n\tN: Registrer en ny ovelse.";
	cout << "\n\tE: Endre en ovelse.";
	cout << "\n\tF: Fjerne en ovelse.";
	cout << "\n\tA: Skriv hoveddataene om alle ovelser";
	cout << "\n\tL: Deltagerlister og startlister.";
	cout << "\n\tR: Resultatlister.";
}

void deltagerlisteMeny() {
	cout << "\n\nMENYVALG FOR DELTAGERLISTER:";
	cout << "\n\tS: Skriv deltager-/startliste.";
	cout << "\n\tN: Ny deltager-/startliste.";
	cout << "\n\tE: Endre deltager-/startliste.";
	cout << "\n\tF: Fjerne deltager-/startliste.";
}

void resultatlisteMeny() {
	cout << "\n\nMENYVALG FOR RESULTATLISTER:";
	cout << "\n\tS: Skriv resultatliste.";
	cout << "\n\tN: Ny resultatliste.";
	cout << "\n\tF: Fjern resultatliste.";
}
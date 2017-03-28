#include "../Headers/headere.h"

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 


//Generelle funksjoner.
										//Skriver hovedmeny.
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
										//Leser inn char (ikke upcaset).
char les() {
	char ch;
	cout << "\nKommando: ";
	cin >> ch; cin.ignore();
	return ch;
}
										//Leser inn kommando og gir upcaset char
char lesKommando() {
	char ch;
	cout << "\nKommando: ";
	cin >> ch; cin.ignore();
	ch = toupper(ch);
	return(ch);
}
										//Leser inn tall i et intervall.
int les(const char * t, const int min, const int max)
{
	int tall;
	do {
		cout << '\t' << t << " (" << min << '-' << max << "): ";
		cin >> tall; //cin.ignore();
	} while (tall < min || tall > max);
	return tall;
}

void les(const char t[], char s[], const int LEN) {
	do {
		cout << '\t' << t << ": ";	cin.getline(s, LEN); //  Ledetekst og leser.
	} while (strlen(s) == 0);           //  Sjekker at tekstlengden er ulik 0.
}

char* lesPrivat() {
	char* retur;
	char buffer[NVNLEN];
	cin.getline(buffer, NVNLEN);
	retur = new char[strlen(buffer) + 1];
	strcpy(retur, buffer);
	return retur;
}


//Nasjoner-funksjoner.
void nasjonerMeny() {
	cout << "\n\nMENYVALG FOR NASJONER:";
	cout << "\n\tN: Registrer en ny nasjon.";
	cout << "\n\tE: Endre en nasjon.";
	cout << "\n\tA: Skriv hoveddataene alle nasjoner.";
	cout << "\n\tT: Skriv en nasjons deltagertropp.";
	cout << "\n\tS: Skriv alle data om en nasjon.";
	cout << "\n\tX: Tilbake til hovedmeny.";
}

void endreNasjonerMeny(){
	cout << "\n\nTING SOM KAN ENDRES:";
	cout << "\n\nN: Nasjonens navn.";
	cout << "\n\nK: Kontakt navn.";
	cout << "\n\nT: Kontakt nummer.";
	cout << "\n\nX: Gå tilbake.";
}

//Deltager-funksjoner.
										//Skriver undermeny for deltager.
void deltagerMeny() {
	cout << "\n\nMENYVALG FOR DELTAGERE:";
	cout << "\n\tN: Registrer ny deltager.";
	cout << "\n\tE: Endre en deltager.";
	cout << "\n\tA: Skriv hoveddataene om alle deltagere.";
	cout << "\n\tS: Skriv alle data om en gitt deltager.";
	cout << "\n\tX: Tibake til hovedmeny.";
}

//Gren-funksjoner
										//Skriver undermeny for gren.
void grenMeny() {
	cout << "\n\nMENYVALG FOR GRENER";
	cout << "\n\tN: Registrer ny gren.";
	cout << "\n\tE: Endre en gren.";
	cout << "\n\tA: Skriv hoveddataene om alle grener.";
	cout << "\n\tS: Skriv alle data om en gitt gren.";
	cout << "\n\tX: Tilbake til hovedmeny.";
}

//Ovelse-funksjoner
										//Skriver undermy for ovelse.
void ovelseMeny() {
	cout << "\n\nMENYVALG FOR OVELSER";
	cout << "\n\tN: Registrer en ny ovelse.";
	cout << "\n\tE: Endre en ovelse.";
	cout << "\n\tF: Fjerne en ovelse.";
	cout << "\n\tA: Skriv hoveddataene om alle ovelser";
	cout << "\n\tL: Deltagerlister og startlister.";
	cout << "\n\tR: Resultatlister.";
	cout << "\n\tX: Tilbake til hovedmeny.";
}

										//Skriver undermeny for deltager.
void deltagerlisteMeny() {
	cout << "\n\nMENYVALG FOR DELTAGERLISTER:";
	cout << "\n\tS: Skriv deltager-/startliste.";
	cout << "\n\tN: Ny deltager-/startliste.";
	cout << "\n\tE: Endre deltager-/startliste.";
	cout << "\n\tF: Fjerne deltager-/startliste.";
	cout << "\n\tX: Tilbake til hovedmeny.";
}

										//Skriver undermeny for deltagerliste.
void resultatlisteMeny() {
	cout << "\n\nMENYVALG FOR RESULTATLISTER:";
	cout << "\n\tS: Skriv resultatliste.";
	cout << "\n\tN: Ny resultatliste.";
	cout << "\n\tF: Fjern resultatliste.";
	cout << "\n\tX: Tilbake til hovedmeny.";
}

										//Registrerer ny deltager
void nyDeltager() {
	char nasjonalitet[NASJKORTLEN];	
	int nummer;
	cout << "\nHva er deltagerens nasjonalitet (forkortelse på 3 bokstaver)?\t";
	cin.getline(nasjonalitet, (NASJKORTLEN - 1));
	if (nasjoner->inList(nasjonalitet)) {
		cout << "\nHvilket nummer har deltageren?\t";
		cin >> nummer;
		if (!deltagere->inList(nummer)) {
			Deltager* hjelpeobjekt = new Deltager(nummer);
		}
		else
			cout << "\nDeltager finnes allerede.";
	}
}

										//Endrer en deltager
void endreDeltager() {

}

										//Skriver info om alle deltagere
void skrivDeltagerliste() {

}

										//Skriver info om en deltager
void skrivDeltager() {

}
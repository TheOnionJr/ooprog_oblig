#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "../Headers/Statistikk.h"
#include "../Headers/Poeng.h"
#include <iostream>
#include <fstream>
using namespace std;


void Poeng::sorter() {			//Funksjon som går gjennom arrayen og sorterer etter medaljeverdi.
	for (int i = sisteBrukt; i >= 0; i--) {				//Går gjennom arrayen.	
		if (medaljer[i] >= poeng[i - 1]) {			//Sjekker om i-1 er større.
			char temp[NASJKORTLEN];						//Mellomlagring.
			int tempi;									//Mellomlagring.

			strcpy(temp, nasjKort[i]); tempi = poeng[i];			//Kopierer i inn i mellomlagring.
			strcpy(nasjKort[i], nasjKort[i - 1]); poeng[i] = poeng[i - 1];	//Setter i til i-1.
			strcpy(nasjKort[i - 1], temp); poeng[i - 1] = tempi;	//Kopierer fra mellomlagring til i.
		}
	}
}


void Poeng::lesArrayFraFil() {
	ifstream innfil("MEDALJER.DTA");

	if (innfil) {											//Sjekker om filen ble funnet.
		innfil >> sisteBrukt; innfil.ignore();				//Leser inn sisteBrukt fra starten av filen.
		for (int i = 0; i < sisteBrukt; i++) {				//Kjører for antall nasjoner som er skrevet til filen.
			innfil.getline(nasjKort[i], MAXNASJONER + 1);	//Leser inn nasjKort, og setter i riktig arraynr.
			innfil >> poeng[i]; innfil.ignore();			//Leser inn medalje-verdien.
			innfil.ignore();								//Blank spacer.
		}
	}
}

void Poeng::skrivArrayTilFil() {
	ofstream utfil("MEDALJER.DTA");

	if (utfil) {											//Sjekker om filen ble funnet.
		utfil << sisteBrukt << '\n';						//Skriver sisteBrukt helt i starten av filen.
		for (int i = 0; i < sisteBrukt; i++) {				//Går gjennom alle nasjoner i arrayen, og skriver til fil.
			utfil << nasjKort[i] << '\n';					//Skriver nasjKort.
			utfil << poeng[i] << '\n';						//Skriver poeng.
			utfil << '\n';									//Blank space
		}

	}
	else {
		cout << "Klarte ikke skrive til MEDALJER.DTA!";	//Feilmelding.
	}
}

void Poeng::display() {
	
}
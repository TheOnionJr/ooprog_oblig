#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "../Headers/Statistikk.h"
#include "../Headers/Medaljer.h"
#include <iostream>
#include <fstream>
using namespace std;

void Medaljer::lesArrayFraFil() {	//Funksjon for � oppdatere data (legge til)
	ifstream innfil("MEDALJER.DTA");

	if (innfil) {										//Sjekker om filen ble funnet.
		innfil >> sisteBrukt; innfil.ignore();			//Leser inn sisteBrukt fra starten av filen.
		for (int i = 0; i < sisteBrukt; i++) {			//Kj�rer for antall nasjoner som er skrevet til filen.
			innfil.getline(nasjKort[i], MAXNASJONER + 1);	//Leser inn nasjKort, og setter i riktig arraynr.
			innfil >> medaljer[i]; innfil.ignore();		//Leser inn medalje-verdien.
			innfil.ignore();							//Blank spacer.
		}
	}
	else {
		cout << "Fant ikke filen MEDALJER.DTA!";		//Feilmelding.
	}
}


void Medaljer::skrivArrayTilFil() {
	ofstream utfil("MEDALJER.DTA");

	if (utfil) {										//Sjekker om filen ble funnet.
		utfil << sisteBrukt << '\n';					//Skriver sisteBrukt helt i starten av filen.
		for (int i = 0; i < sisteBrukt; i++) {			//G�r gjennom alle nasjoner i arrayen, og skriver til fil.
			utfil << nasjKort[i] << '\n';				//Skriver nasjKort.
			utfil << medaljer[i] << '\n';				//Skriver medaljeverdi.
			utfil << '\n';								//Blank space
		}

	}
	else {
		cout << "Klarte ikke skrive til MEDALJER.DTA!";	//Feilmelding.
	}
}

void Medaljer::sorter() {			//Funksjon som g�r gjennom arrayen og sorterer etter medaljeverdi.
	for (int i = sisteBrukt; i >= 0; i--) {				//G�r gjennom arrayen.	
		if (medaljer[i] >= medaljer[i - 1]) {			//Sjekker om i-1 er st�rre.
			char temp[NASJKORTLEN];						//Mellomlagring.
			int tempi;									//Mellomlagring.

			strcpy(temp, nasjKort[i]); tempi = medaljer[i];			//Kopierer i inn i mellomlagring.
			strcpy(nasjKort[i], nasjKort[i - 1]); medaljer[i] = medaljer[i - 1];	//Setter i til i-1.
			strcpy(nasjKort[i - 1], temp); medaljer[i - 1] = tempi;	//Kopierer fra mellomlagring til i.
		}
	}
}


void Medaljer::leggTilMedaljer() {
	lesArrayFraFil();					//Henter arrayen fra fil.



	skrivArrayTilFil();					//Skriver (over) arrayen til fil.
}

void Medaljer::trekkFraMedaljer() {
	lesArrayFraFil();					//Henter arrayen fra fil.



	skrivArrayTilFil();					//Skriver (over) arrayen til fil.
}

void Medaljer::display(int i) {		//Regner ut og skriver medaljer.
	int gull, solv, bronse;
		gull = medaljer[i] / 10000;						//Regner ut antall gull.
		solv = (medaljer[i] - (gull * 10000)) / 100;	//Regner ut antall solv.
		bronse = medaljer[i] % 100;						//Regner ut antall bronse.

		cout << "\nNasjon: " << nasjKort[i]				//Skriver ut nasjonen,
			 << "\n Medaljer: Gull: " <<  gull			//antall gull,
			 << "\t Solv: "	  << solv					//antall solv,
			 << "\t Bronse: " << bronse << '\n';		//antall bronse.		
}

void Medaljer::displayAll() {	//Skriver ut alle medaljeverdiene.
	for (int i = 1; i >= sisteBrukt; i++)				//G�r gjennom alle.
		display(i);										//Kaller displayfunksjon for i.
}
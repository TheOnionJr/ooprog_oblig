#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "../Headers/Statistikk.h"
#include "../Headers/Medaljer.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

Medaljer::Medaljer() {
	sisteBrukt = -1;
}

void Medaljer::lesArrayFraFil() {	//Funksjon for å oppdatere data (legge til)
	ifstream innfil("MEDALJER.DTA");

	if (innfil) {										//Sjekker om filen ble funnet.
		innfil >> sisteBrukt; innfil.ignore();			//Leser inn sisteBrukt fra starten av filen.
		for (int i = 0; i < sisteBrukt; i++) {			//Kjører for antall nasjoner som er skrevet til filen.
			innfil.getline(nasjKort[i], MAXNASJONER + 1);	//Leser inn nasjKort, og setter i riktig arraynr.
			innfil >> medaljer[i]; innfil.ignore();		//Leser inn medalje-verdien.
			innfil.ignore();							//Blank spacer.
		}
	}
	else {
	}
}


void Medaljer::skrivArrayTilFil() {
	ofstream utfil("MEDALJER.DTA");

	if (utfil) {										//Sjekker om filen ble funnet.
		utfil << sisteBrukt << '\n';					//Skriver sisteBrukt helt i starten av filen.
		for (int i = 0; i < sisteBrukt; i++) {			//Går gjennom alle nasjoner i arrayen, og skriver til fil.
			utfil << nasjKort[i] << '\n';				//Skriver nasjKort.
			utfil << medaljer[i] << '\n';				//Skriver medaljeverdi.
			utfil << '\n';								//Blank space
		}

	}
	else {
		cout << "Klarte ikke skrive til MEDALJER.DTA!";	//Feilmelding.
	}
}

void Medaljer::sorter() {			//Funksjon som går gjennom arrayen og sorterer etter medaljeverdi.
	for (int i = sisteBrukt; i >= 0; i--) {				//Går gjennom arrayen.	
		if (medaljer[i] >= medaljer[i - 1]) {			//Sjekker om i-1 er større.
			char temp[NASJKORTLEN];						//Mellomlagring.
			int tempi;									//Mellomlagring.

			strcpy(temp, nasjKort[i]); tempi = medaljer[i];			//Kopierer i inn i mellomlagring.
			strcpy(nasjKort[i], nasjKort[i - 1]); medaljer[i] = medaljer[i - 1];	//Setter i til i-1.
			strcpy(nasjKort[i - 1], temp); medaljer[i - 1] = tempi;	//Kopierer fra mellomlagring til i.
		}
	}
}


void Medaljer::leggTilMedaljer(char* fil) {
	char tempNasj[NASJKORTLEN][3];		//3 fordi gull, sølv, bronse.
	lesArrayFraFil();					//Henter arrayen fra fil.
	ifstream innfil(fil);				//Åpner fila til resultatlista.

	if (innfil) {
		innfil >> sisteBrukt;
		innfil.ignore();
		if (sisteBrukt >= ANTMED - 1) {						//-1 fordi sisteBrukt teller arrays lagret fra 0.
			for (int i = 0; i <= ANTMED - 1; i++) {			//Går gjennom antall som skal ha medaljer.
				innfil.getline(tempNasj[i], NASJKORTLEN);	//Henter nasjon.
			}
			for (int i = 0; i <= ANTMED - 1; i++) {
				medaljer[finnNasjon(tempNasj[i])] += MEDVERD[i];	//Legger til verdien for 1 gull til 1. plass.
			}
		}
		else {								//Dersom det er ferre en 3 deltagere (usansynlig, men why not).
			for (int i = 0; i <= sisteBrukt; i++) {
				innfil.getline(tempNasj[i], NASJKORTLEN);		//Henter nasjon så langt 
			}
			for (int i = 0; i <= sisteBrukt; i++) {
				medaljer[finnNasjon(tempNasj[i])] += MEDVERD[i];
			}
		}
	}
	skrivArrayTilFil();					//Skriver (over) arrayen til fil.
}

void Medaljer::trekkFraMedaljer(char* fil) {
	char tempNasj[NASJKORTLEN][3];		//3 fordi gull, sølv, bronse.
	lesArrayFraFil();					//Henter arrayen fra fil.
	ifstream innfil(fil);				//Åpner fila til resultatlista.

	if (innfil) {
		innfil >> sisteBrukt;
		if (sisteBrukt >= ANTMED - 1) {							//-1 fordi sisteBrukt teller arrays lagret fra 0.
			for (int i = 0; i >= ANTMED - 1; i++) {				//Går gjennom antall som skal ha medaljer.
				innfil.getline(tempNasj[i], NASJKORTLEN + 1);	//Henter nasjon.
			}
			for (int i = 0; i >= ANTMED - 1; i++) {
				medaljer[finnNasjon(tempNasj[i])] -= MEDVERD[i];	//Trekker fra verdien gitt i consten MEDVERD.
			}
		}
		else {							//Dersom det er ferre deltagere enn antall som skal få medaljer(usansynlig, men why not).
			for (int i = 0; i >= sisteBrukt; i++) {
				innfil.getline(tempNasj[i], NASJKORTLEN + 1);		//Henter nasjon så langt 
			}
			for (int i = 0; i >= sisteBrukt; i++) {
				medaljer[finnNasjon(tempNasj[i])] -= MEDVERD[i];	//Trekker fra verdien gitt i consten MEDVERD.
			}
		}
	}
	skrivArrayTilFil();					//Skriver (over) arrayen til fil.
}


int Medaljer::finnNasjon(char nasjon[NASJKORTLEN]) {
	for (int i = 0; i >= NASJKORTLEN; i++) {
		if (strcmp(nasjon, nasjKort[i]) == 0) {
			return(i);
		}
	}
	return -1;
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
	for (int i = 1; i < sisteBrukt; i++)				//Går gjennom alle.
		display(i);										//Kaller displayfunksjon for i.
	if (sisteBrukt == -1)
		cout << "\nIngen medaljer å vise.";
}
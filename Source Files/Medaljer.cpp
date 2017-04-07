#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "../Headers/Statistikk.h"
#include "../Headers/Medaljer.h"
#include "../Headers/main.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

Medaljer::Medaljer() {
	sisteBrukt = (-1);
	for (int i = 0; i < MAXNASJONER; i++) {
		medaljer[i] = 0;
	}
}

void Medaljer::lesArrayFraFil() {	//Funksjon for å oppdatere data (legge til)
	ifstream innfil("MEDALJER.DTA");
	if (innfil) {
		innfil >> sisteBrukt;
		innfil.ignore();
		for (int i = 0; i <= sisteBrukt; i++) {
			innfil.getline(nasjKort[i], '\n');
			innfil >> medaljer[i];
			innfil.ignore(); innfil.ignore();
		}
	}
	else {
		sisteBrukt = -1;
	}
}


void Medaljer::skrivArrayTilFil() {
	ofstream utfil("MEDALJER.DTA");

	if (utfil) {										//Sjekker om filen ble funnet.
		utfil << sisteBrukt << '\n';					//Skriver sisteBrukt helt i starten av filen.
		for (int i = 0; i <= sisteBrukt; i++) {			//Går gjennom alle nasjoner i arrayen, og skriver til fil.
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
	for (int i = sisteBrukt; i > 0; i--) {				//Går gjennom arrayen.	
		if (medaljer[i] >= medaljer[i - 1]) {					//Sjekker om i-1 er større.
			char temp[NASJKORTLEN];						//Mellomlagring nasjonsforkortelse.
			int tempi;									//Mellomlagring score.b

			strcpy(temp, nasjKort[i]); tempi = medaljer[i];						//Kopierer i inn i mellomlagring.
			strcpy(nasjKort[i], nasjKort[i - 1]); medaljer[i] = medaljer[i - 1];	//Setter i til i-1.
			strcpy(nasjKort[i - 1], temp); medaljer[i - 1] = tempi;	//Kopierer fra mellomlagring til i.
		}
	}
}


void Medaljer::leggTilMedaljer(char* fil) {
	ifstream innfil(fil);
	int antRes;
	innfil >> antRes;
	innfil.ignore();
	char tempNasj[ANTMED][NASJKORTLEN];
	if ((antRes + 1) > ANTMED) {
		for (int i = 0; i < ANTMED; i++) {
			bool fant = false;
			innfil.getline(tempNasj[i], NASJKORTLEN);
			innfil.ignore(265, '\n');
			innfil.ignore(265, '\n');
			innfil.ignore();
			for (int j = 0; j < MAXDELTAGERE; j++) {
				if (strcmp(tempNasj[i], nasjKort[j]) == 0) {
					medaljer[j] += MEDVERD[i];
					fant = true;
				}
			}
			if (!fant) {
				sisteBrukt++;
				strcpy(nasjKort[sisteBrukt], tempNasj[i]);
				medaljer[sisteBrukt] += MEDVERD[i];
			}
			if(sisteBrukt != 0)
				sorter();
		}
		
	}
	else {
		for (int i = 0; i <= antRes; i++) {
			bool fant = false;
			innfil.getline(tempNasj[i], NASJKORTLEN);
			innfil.ignore(265, '\n');
			innfil.ignore(265, '\n');
			innfil.ignore();
			for (int j = 0; j < MAXDELTAGERE; j++) {
				if (strcmp(tempNasj[i], nasjKort[j]) == 0) {
					medaljer[j] += MEDVERD[i];
					fant = true;
				}
			}
			if (!fant) {
				sisteBrukt++;
				strcpy(nasjKort[sisteBrukt], tempNasj[i]);
				medaljer[sisteBrukt] += MEDVERD[i];
			}
			if(sisteBrukt != 0)
				sorter();
		}

	}
}

void Medaljer::trekkFraMedaljer(char* fil) {
	ifstream innfil(fil);
	int antRes;
	innfil >> antRes;
	innfil.ignore();
	char tempNasj[ANTMED][NASJKORTLEN];
	if ((antRes + 1) > ANTMED) {
		for (int i = 0; i < ANTMED; i++) {
			bool fant = false;
			innfil.getline(tempNasj[i], NASJKORTLEN);
			innfil.ignore(265, '\n');
			innfil.ignore(265, '\n');
			innfil.ignore();
			for (int j = 0; j < MAXDELTAGERE; j++) {
				if (strcmp(tempNasj[i], nasjKort[j]) == 0) {
					medaljer[j] -= MEDVERD[i];
					fant = true;
				}
			}
			if (!fant) {
				sisteBrukt++;
				strcpy(nasjKort[sisteBrukt], tempNasj[i]);
				medaljer[sisteBrukt] -= MEDVERD[i];
			}
			sorter();
		}

	}
	else {
		for (int i = 0; i <= antRes; i++) {
			bool fant = false;
			innfil.getline(tempNasj[i], NASJKORTLEN);
			innfil.ignore(265, '\n');
			innfil.ignore(265, '\n');
			innfil.ignore();
			for (int j = 0; j < MAXDELTAGERE; j++) {
				if (strcmp(tempNasj[i], nasjKort[j]) == 0) {
					medaljer[j] -= MEDVERD[i];
					fant = true;
				}
			}
			if (!fant) {
				sisteBrukt++;
				strcpy(nasjKort[sisteBrukt], tempNasj[i]);
				medaljer[sisteBrukt] -= MEDVERD[i];
			}
			sorter();
		}

	}
}


int Medaljer::finnNasjon(char* nasjon) {
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
	for (int i = 0; i <= sisteBrukt; i++)				//Går gjennom alle.
		display(i);										//Kaller displayfunksjon for i.
	if (sisteBrukt == -1)
		cout << "\nIngen medaljer å vise.";
}
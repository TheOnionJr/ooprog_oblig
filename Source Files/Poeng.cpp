#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "../Headers/Statistikk.h"
#include "../Headers/Poeng.h"
#include "../Headers/Const.h"
#include <iostream>
#include <fstream>
using namespace std;


Poeng::Poeng() {
	sisteBrukt = (-1);
	for(int i = 0; i < MAXNASJONER; i++)
		poeng[i] = 0;
}

void Poeng::sorter() {			//Funksjon som går gjennom arrayen og sorterer etter poeng.
	for (int i = sisteBrukt; i >= 0; i--) {				//Går gjennom arrayen.	
		if (poeng[i] >= poeng[i - 1]) {			//Sjekker om i-1 er større.
			char temp[NASJKORTLEN];						//Mellomlagring.
			int tempi;									//Mellomlagring.

			strcpy(temp, nasjKort[i]); tempi = poeng[i];			//Kopierer i inn i mellomlagring.
			strcpy(nasjKort[i], nasjKort[i - 1]); poeng[i] = poeng[i - 1];	//Setter i til i-1.
			strcpy(nasjKort[i - 1], temp); poeng[i - 1] = tempi;	//Kopierer fra mellomlagring til i.
		}
	}
}


void Poeng::lesArrayFraFil() {
	ifstream innfil("POENG.DTA");
	if (innfil) {
		innfil >> sisteBrukt;
		innfil.ignore();
		for (int i = 0; i <= sisteBrukt; i++) {
			innfil.getline(nasjKort[i], '\n');
			innfil >> poeng[i];
			innfil.ignore(); innfil.ignore();
		}
	}
	else {
		sisteBrukt = -1;
	}
}

void Poeng::skrivArrayTilFil() {
	ofstream utfil("POENG.DTA");

	if (utfil) {										//Sjekker om filen ble funnet.
		utfil << sisteBrukt << '\n';					//Skriver sisteBrukt helt i starten av filen.
		for (int i = 0; i <= sisteBrukt; i++) {			//Går gjennom alle nasjoner i arrayen, og skriver til fil.
			utfil << nasjKort[i] << '\n';				//Skriver nasjKort.
			utfil << poeng[i] << '\n';				//Skriver medaljeverdi.
			utfil << '\n';								//Blank space
		}

	}
	else {
		cout << "Klarte ikke skrive til MEDALJER.DTA!";	//Feilmelding.
	}
}

void Poeng::leggTilPoeng(char* fil) {
	ifstream innfil(fil);
	int antRes;
	innfil >> antRes;
	innfil.ignore();
	char tempNasj[PSKALALEN][NASJKORTLEN];
	if ((antRes + 1) > PSKALALEN) {
		for (int i = 0; i < PSKALALEN; i++) {
			bool fant = false;
			innfil.getline(tempNasj[i], NASJKORTLEN);
			innfil.ignore(265, '\n');
			innfil.ignore(265, '\n');
			innfil.ignore();
			for (int j = 0; j < MAXDELTAGERE; j++) {
				if (strcmp(tempNasj[i], nasjKort[j]) == 0) {
					poeng[j] += POENGSKALA[i];
					fant = true;
				}
			}
			if (!fant) {
				sisteBrukt++;
				strcpy(nasjKort[sisteBrukt], tempNasj[i]);
				poeng[sisteBrukt] += POENGSKALA[i];
			}
			//if(sisteBrukt != 0)
			//	sorter();
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
					poeng[j] += POENGSKALA[i];
					fant = true;
				}
			}
			if (!fant) {
				sisteBrukt++;
				strcpy(nasjKort[sisteBrukt], tempNasj[i]);
				poeng[sisteBrukt] += POENGSKALA[i];
			}
			//if(sisteBrukt != 0)
			//	sorter();
		}

	}
}

void Poeng::trekkFraPoeng(char* fil) {
	ifstream innfil(fil);
	int antRes;
	innfil >> antRes;
	innfil.ignore();
	char tempNasj[PSKALALEN][NASJKORTLEN];
	if ((antRes + 1) > PSKALALEN) {
		for (int i = 0; i < PSKALALEN; i++) {
			bool fant = false;
			innfil.getline(tempNasj[i], NASJKORTLEN);
			innfil.ignore(265, '\n');
			innfil.ignore(265, '\n');
			innfil.ignore();
			for (int j = 0; j < MAXDELTAGERE; j++) {
				if (strcmp(tempNasj[i], nasjKort[j]) == 0) {
					poeng[j] -= POENGSKALA[i];
					fant = true;
				}
			}
			if (!fant) {
				sisteBrukt++;
				strcpy(nasjKort[sisteBrukt], tempNasj[i]);
				poeng[sisteBrukt] -= POENGSKALA[i];
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
					poeng[j] -= POENGSKALA[i];
					fant = true;
				}
			}
			if (!fant) {
				sisteBrukt++;
				strcpy(nasjKort[sisteBrukt], tempNasj[i]);
				poeng[sisteBrukt] -= POENGSKALA[i];
			}
			sorter();
		}

	}
}

void Poeng::displayAll() {
	bool fant = false;
	for (int i = 0; i <= sisteBrukt; i++) {
		cout << "\nNasjon: " << nasjKort[i]			//Skriver ut nasjonen,
			 << "\tPoeng: " << poeng[i] 			//antall poeng.	
			 << "\n";								//Mellomrom.
		fant = true;
	}
	if (!fant)
		cout << "\nFant ingen poeng-statistikk.";
}
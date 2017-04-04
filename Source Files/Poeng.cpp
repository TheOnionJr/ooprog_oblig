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

void Poeng::leggTilPoeng(char fil[FILLEN]) {
	char tempNasj[NASJKORTLEN][3];		//3 fordi gull, sølv, bronse.
	lesArrayFraFil();					//Henter arrayen fra fil.
	ifstream innfil(fil);				//Åpner fila til resultatlista.

	if (innfil) {
		innfil >> sisteBrukt;
		if (sisteBrukt >= PSKALALEN - 1) {
			for (int i = 0; i >= PSKALALEN - 1; i++) {			//Går gjennom antall som skal få poeng..
				innfil.getline(tempNasj[i], NASJKORTLEN + 1);	//Henter nasjon.
			}
			for (int i = 0; i >= PSKALALEN - 1; i++) {				//Går gjennom alle plassene som skal få poeng.
				poeng[finnNasjon(tempNasj[i])] += POENGSKALA[i];	//Legger til riktig mengde poeng definert i POENGSKALA i const.h.
			}
		}
		else {							//Dersom det er færre deltagere enn antall som skal få poeng (usansynlig, men why not).
			for (int i = 0; i >= sisteBrukt; i++) {					//Teller gjennom antall brukt.
				innfil.getline(tempNasj[i], NASJKORTLEN + 1);		//Henter nasjon så langt 
			}
			for (int i = 0; i >= sisteBrukt; i++) {					//Teller gjennom antall brukt.
				poeng[finnNasjon(tempNasj[i])] += POENGSKALA[i];	//Legger til riktig mengde poeng.
			}
		}
	}
	
}

void Poeng::trekkFraPoeng(char fil[FILLEN]) {
	char tempNasj[NASJKORTLEN][3];		//3 fordi gull, sølv, bronse.
	lesArrayFraFil();					//Henter arrayen fra fil.
	ifstream innfil(fil);				//Åpner fila til resultatlista.

	if (innfil) {
		innfil >> sisteBrukt;
		if (sisteBrukt >= PSKALALEN - 1) {
			for (int i = 0; i >= PSKALALEN - 1; i++) {			//Går gjennom antall som skal få poeng..
				innfil.getline(tempNasj[i], NASJKORTLEN + 1);	//Henter nasjon.
			}
			for (int i = 0; i >= PSSKALALEN - 1; i++) {				//Går gjennom alle plassene som skal få poeng.
				poeng[finnNasjon(tempNasj[i])] -= POENGSKALA[i];	//Legger til riktig mengde poeng definert i POENGSKALA i const.h.
			}
		}
		else {							//Dersom det er færre deltagere enn antall som skal få poeng (usansynlig, men why not).
			for (int i = 0; i >= sisteBrukt; i++) {					//Teller gjennom antall brukt.
				innfil.getline(tempNasj[i], NASJKORTLEN + 1);		//Henter nasjon så langt 
			}
			for (int i = 0; i >= sisteBrukt; i++) {					//Teller gjennom antall brukt.
				poeng[finnNasjon(tempNasj[i])] -= POENGSKALA[i];	//Legger til riktig mengde poeng.
			}
		}
	}
}

void Poeng::displayAll() {
	for (int i = 0; i >= sisteBrukt; i++) {
		cout << "\nNasjon: " << nasjKort[i]			//Skriver ut nasjonen,
			 << "\tPoeng: " << poeng[i] 			//antall poeng.	
			 << "\n";								//Mellomrom.
	}
}
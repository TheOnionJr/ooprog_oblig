#include "../Headers/enumer.h"
#include "../Headers/Const.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Grener.h"
#include "../Headers/Gren.h"
#include <iostream>
using namespace std;

void Grener::grenerMeny() {
	char kommando;
	grenMeny();
	kommando = lesKommando();		//Leser kommando.
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':				//Oppretter ny gren.
			nyGren();
			break;
		case 'E':				//Endrer navnet på en gren.
			endreGren();
			break;
		case 'A':
			skrivHovedGren();
			break;
		case 'S': break;
		default:
			nasjonerMeny();	break;
		}
		grenerMeny();
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

void Grener::skrivHovedGren() {}
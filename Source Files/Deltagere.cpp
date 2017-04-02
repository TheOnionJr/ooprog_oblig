#include "../Headers/Deltagere.h"
#include "../Headers/Deltager.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/main.h"
#include <iostream>

void Deltagere::deltagermeny() {
	char kommando;
	deltagerMeny();
	kommando = lesKommando();
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':
			nyDeltager();
			break;
		case 'E':
			endreDeltager();
			break;
		case 'A':
			skrivDeltagerliste();
			break;
		case 'S':
			skrivDeltager();
			break;
		default:
			break;
		}
		deltagerMeny();
		kommando = lesKommando();
	}
}

void Deltagere::nyDeltager() {
	char nasjonalitet[NASJKORTLEN];
	int nummer;
	cout << "\nHva er deltagerens nasjonalitet (forkortelse på 3 bokstaver)?\t";
	cin.getline(nasjonalitet, (NASJKORTLEN));
	if (nasjoner->inList(nasjonalitet)) {
		cout << "\nHvilket nummer har deltageren?\t";
		cin >> nummer;
		if (!deltagerliste->inList(nummer)) {
			Deltager* hjelpeobjekt = new Deltager(nummer, nasjonalitet);
			deltagerliste->add(hjelpeobjekt);
			nasjoner->leggTilDeltager(nasjonalitet);
		}
		else
			cout << "\nDeltager finnes allerede.";
	}
}

void Deltagere::endreDeltager() {
	char kommando = '0';
	int nummer;
	cout << "\nHva er nummeret til deltageren du vil endre på?\t";
	cin >> nummer;
	if (deltagerliste->inList(nummer)) {	//Om landet finnes
		Deltager* hjelpeobjekt = (Deltager*)deltagerliste->remove(nummer);
		while (kommando != 'X') {
			endreDeltagerMeny();			//Endringsmeny
			kommando = lesKommando();		//Leser kommando
			hjelpeobjekt->endre(kommando);	//UtfÃ¸rer kommando
											//Looper til bruker skriver kommando 'X'
		}
		deltagerliste->add(hjelpeobjekt);
		kommando = 'V';		//Så bruker kan velge nye ting
	}
	else
		cout << "\nFant ikke deltageren.";
}

void Deltagere::skrivDeltagerListe(const char* t) {
	if (deltagerliste->noOfElements() > 0) {
		for (int i = 1; i <= deltagerliste->noOfElements(); i++) {
			Deltager* hjelpeobjekt = (Deltager*)deltagerliste->removeNo(i);
			if (strcmp(t, hjelpeobjekt->returnKortNavn()) == 0) {
				hjelpeobjekt->display();
			}
			deltagerliste->add(hjelpeobjekt);
		}
	}
	else
		cout << "\nNasjonen har ingen deltagere.";
}

void Deltagere::endreDeltagerMeny() {
	cout << "\nHva vil du endre på?" << endl
		<< "Navn:			A" << endl
		<< "Nasjonalitet:	B" << endl
		<< "Kjønn:			C" << endl
		<< "Gå tilbake:		X";
}
bool Deltagere::finnesDeltager(int id){
	if(deltagerliste->inList(id)){
		return true;
	}
	else{
		return false;
	}
}

void Deltagere::skrivDeltager() {
	int id;
	cout << "\nHva er nummeret til deltageren du vil se info om?: ";
	cin >> id;
	if (deltagerliste->inList(id)) {
		Deltager* hjelpeobjekt = (Deltager*) deltagerliste->remove(id);
		hjelpeobjekt->display();
		deltagerliste->add(hjelpeobjekt);
	}
}

void Deltagere::skrivDeltagerliste() {
	deltagerliste->displayList();
}
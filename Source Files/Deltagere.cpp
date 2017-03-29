#include "../Headers/Deltagere.h"
#include "../Headers/Deltager.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/main.h"
#include <iostream>

void Deltagere::deltagerMeny() {
	char kommando;
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
			//skrivDeltager();
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
	cin.getline(nasjonalitet, (NASJKORTLEN - 1));
	if (nasjoner->inList(nasjonalitet)) {
		cout << "\nHvilket nummer har deltageren?\t";
		cin >> nummer;
		if (!deltagerliste->inList(nummer)) {
			Deltager* hjelpeobjekt = new Deltager(nummer);
		}
		else
			cout << "\nDeltager finnes allerede.";
	}
}

void Deltagere::endreDeltager() {

}

void Deltagere::skrivDeltagerliste() {

}
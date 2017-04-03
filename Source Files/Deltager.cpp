#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include "../Headers/ListTool2B.h"
#include "../Headers/Deltager.h"
#include "../Headers/Const.h"
#include "../Headers/main.h"

using namespace std;

Deltager::Deltager(int id, char* nasj) : NumElement(id) {	// Deltagers data skrives inn
	// ID legges i numElement
	char buffer[NVNLEN];					//Mellomlagring av navn
	strcpy(nasjonalitet, nasj);
	cout << "\nDeltagersdNavn: ";			
	cin.ignore();							
	cin.getline(buffer, NVNLEN);			//Henter brukerens ønskede navn
	dNavn = new char[strlen(buffer) + 1];	//Setter av nøyaktig så mye plass som trengs
	strcpy(dNavn, buffer);					//Setter navnet
	cout << "\nDeltagers kjønn(m/k): ";		
	while (kjonn != 'M' && kjonn != 'K') {	//Spør om hvilket kjønn deltageren er til gyldig valg er gjort
		cin >> kjonn;
		kjonn = toupper(kjonn);
	}
}

Deltager::~Deltager() {
	// Må lages
}

void Deltager::endre(char hva) { // Endrer deltagers data (ikke id)
	char buffer[NVNLEN];
	if (hva == 'A') {
		cout << "\nDeltagers navn: ";
		cin.getline(buffer, NVNLEN);			//Henter brukerens ønskede navn
		dNavn = new char[strlen(buffer) + 1];	//Setter av nøyaktig så mye plass som trengs
		strcpy(dNavn, buffer);					//Setter navnet
	}
	else if (hva == 'C') {
		cout << "\nDeltagers kjønn(m/k): ";
		do {									//Spør om hvilket kjønn deltageren er til gyldig valg er gjort
			cin >> kjonn;
			kjonn = toupper(kjonn);
		} while (kjonn != 'M' && kjonn != 'K');
	}
	else if (hva == 'B') {
		char nasj[NASJKORTLEN];
		strcpy(nasj, nasjonalitet);
		nasjoner->fjernDeltager(nasj);
		cout << "\nHva er deltagerens nye nasjonalitet (forkortelse på 3 bokstaver)?\t";
		cin.getline(nasj, (NASJKORTLEN));
		if (nasjoner->inList(nasj)) {
			strcpy(nasjonalitet, nasj);
			nasjoner->leggTilDeltager(nasj);
		}
		else {
			nasjoner->leggTilDeltager(nasjonalitet);
			cout << "\nNasjonen eksisterer ikke.";
		}
	}
}

void Deltager::display() {	//Skriver ut deltagers data
	cout << "\nID: " << number;
	cout << "\nNavn: " << dNavn;
	cout << "\nKjonn: " << kjonn;
}

char* Deltager::returnKortNavn() {
	return (nasjonalitet);
}

char* Deltager::returnNavn() {
	return (dNavn);
}
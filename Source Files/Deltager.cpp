#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include "../Headers/ListTool2B.h"
#include "../Headers/Deltager.h"
#include "../Headers/Const.h"
#include "../Headers/main.h"

using namespace std;

Deltager::Deltager(int id) : NumElement(id) {	// Deltagers data skrives inn
	// ID legges i numElement
	char buffer[NVNLEN];					//Mellomlagring av navn
	cout << "\nDeltagersdNavn: ";			
	cin.ignore();							
	cin.getline(buffer, NVNLEN);			//Henter brukerens �nskede navn
	dNavn = new char[strlen(buffer) + 1];	//Setter av n�yaktig s� mye plass som trengs
	strcpy(dNavn, buffer);					//Setter navnet
	cout << "\nDeltagers kj�nn(m/k): ";		
	while (kjonn != 'M' && kjonn != 'K') {	//Sp�r om hvilket kj�nn deltageren er til gyldig valg er gjort
		cin >> kjonn;
		kjonn = toupper(kjonn);
	}
}

Deltager::~Deltager() {
	// M� lages
}

void Deltager::endre(char hva) { // Endrer deltagers data (ikke id)
	char buffer[NVNLEN];
	if (hva == 'A') {
		cout << "\nDeltagers navn: ";
		cin.ignore();
		cin.getline(buffer, NVNLEN);			//Henter brukerens �nskede navn
		dNavn = new char[strlen(buffer) + 1];	//Setter av n�yaktig s� mye plass som trengs
		strcpy(dNavn, buffer);					//Setter navnet
	}
	else if (hva == 'C') {
		cout << "\nDeltagers kj�nn(m/k): ";
		while (kjonn != 'M' && kjonn != 'K') {	//Sp�r om hvilket kj�nn deltageren er til gyldig valg er gjort
			cin >> kjonn;
			kjonn = toupper(kjonn);
		}
	}
	else if (hva == 'B') {
		nasjoner->fjernDeltager(nasjonalitet);
		cout << "\nHva er deltagerens nye nasjonalitet (forkortelse p� 3 bokstaver)?\t";
		cin.getline(nasjonalitet, (NASJKORTLEN));
		nasjoner->leggTilDeltager(nasjonalitet);
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
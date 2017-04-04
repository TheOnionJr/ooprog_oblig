#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include "../Headers/ListTool2B.h"
#include "../Headers/Deltager.h"
#include "../Headers/Const.h"
#include "../Headers/main.h"

using namespace std;

Deltager::Deltager(int id, char* nasj) : NumElement(id) {	// Deltagers data skrives inn
	// ID legges i numElement
	char buffer[NVNLEN];					//Mellomlagring av navn
	strcpy(nasjonalitet, nasj);
	cout << "\nDeltagers Navn: ";			
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

Deltager::Deltager(int id, ifstream &innfil) : NumElement(id) {
	char midNavn[NVNLEN];
	innfil.ignore();
	innfil.getline(midNavn, NVNLEN);
	dNavn = new char[strlen(midNavn) + 1];
	innfil.getline(nasjonalitet, NASJKORTLEN);
	innfil >> kjonn;
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
	else if (hva == 'C') {						//Endring av deltagers kjønn
		cout << "\nDeltagers kjønn(m/k): ";
		do {									//Spør om hvilket kjønn deltageren er til gyldig valg er gjort
			cin >> kjonn;
			kjonn = toupper(kjonn);
		} while (kjonn != 'M' && kjonn != 'K');
	}
	else if (hva == 'B') {						//Endring av deltagers nasjonalitet
		char nasj[NASJKORTLEN];
		strcpy(nasj, nasjonalitet);
		nasjoner->fjernDeltager(nasj);			//Trekker fra 1 på antDeltagere i nasjonen deltageren var i før endring
		cout << "\nHva er deltagerens nye nasjonalitet (forkortelse på 3 bokstaver)?\t";
		cin.getline(nasj, (NASJKORTLEN));		//Henter brukerens ønskede nye nasjon
		if (nasjoner->inList(nasj)) {			//Sjekker at den nye najonen eksisterer
			strcpy(nasjonalitet, nasj);			//Endrer deltagerens nasjonalitet
			nasjoner->leggTilDeltager(nasj);	//Legger til 1 i nasjonens antDeltagere
		}
		else {									//Den innskrevne nasjonen eksisterer ikke
			nasjoner->leggTilDeltager(nasjonalitet);	//Legger til 1 i deltagerens originale nasjonalitet, da den ikke ble endret
			cout << "\nNasjonen eksisterer ikke.";
		}
	}
}

void Deltager::display() {	//Skriver ut deltagers data
	cout << "\nID: " << number;
	cout << "\nNavn: " << dNavn;
	cout << "\nKjonn: " << kjonn;
}

void Deltager::ovelseDisplay() {	//Skriver nasjonsnavnet og nasjonsforkortelsen på skjermen
	cout << "\nNavn: " << dNavn;
	cout << "\nNasjonalitet: " << nasjonalitet;
}

char* Deltager::returnKortNavn() {		//Returnerer nasjonsforkortelsen til bruk andre steder
	return (nasjonalitet);
}

char* Deltager::returnNavn() {			//Returnerer nasjonens fulle navn til bruk andre steder
	return (dNavn);
}

void Deltager::skrivTilFil(ofstream &utfil) {
	utfil << number << endl << dNavn << endl
		<< nasjonalitet << endl << kjonn;
}
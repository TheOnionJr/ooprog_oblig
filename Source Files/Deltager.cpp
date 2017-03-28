#include "../Headers/headere.h"

Deltager::Deltager(int id) : NumElement(id) {	// Deltagers data skrives inn
	// ID legges i numElement
	char buffer[NVNLEN];					//Mellomlagring av navn
	cout << "\nDeltagersdNavn: ";			
	cin.ignore();							
	cin.getline(buffer, NVNLEN);			//Henter brukerens ønskede navn
	dNavn = new char[strlen(buffer) + 1];	//Setter av nøyaktig så mye plass som trengs
	strcpy(dNavn, buffer);					//Setter navnet
	cout << "\nDeltagers kjønn(m/k): ";		
	while (kjonn != 'M' || kjonn != 'K') {	//Spør om hvilket kjønn deltageren er til gyldig valg er gjort
		cin >> kjonn;
		kjonn = toupper(kjonn);
	}
}

Deltager::~Deltager() {
	// Må lages
}

void Deltager::endre(int hva) { // Endrer deltagers data (ikke id)
	char buffer[NVNLEN];
	cout << "\nDeltagersdNavn: "; 
	cin.ignore();
	cin.getline(buffer, NVNLEN);			//Henter brukerens ønskede navn
	dNavn = new char[strlen(buffer) + 1];	//Setter av nøyaktig så mye plass som trengs
	strcpy(dNavn, buffer);					//Setter navnet
	cout << "\nDeltagers kjønn(m/k): ";
	while (kjonn != 'M' || kjonn != 'K') {	//Spør om hvilket kjønn deltageren er til gyldig valg er gjort
		cin >> kjonn;
		kjonn = toupper(kjonn);
	}
}

void Deltager::display() {	//Skriver ut deltagers data
	cout << "\nID: " << number;
	cout << "\nNavn: " << dNavn;
	cout << "\nKjonn: " << kjonn;
}
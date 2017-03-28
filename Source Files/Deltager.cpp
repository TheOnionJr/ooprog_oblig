#include "../Headers/headere.h"

Deltager::Deltager(int id) : NumElement(id) {	// Deltagers data skrives inn
	// ID ligger i numElement construtor
	char buffer[NVNLEN];
	cout << "\nDeltagersdNavn: "; 
	cin.ignore();
	cin.getline(buffer, NVNLEN);
	dNavn = new char[strlen(buffer) + 1];
	strcpy(dNavn, buffer);
	cout << "\nDeltagers kjønn(m/k): "; 
	while (kjonn != 'm' || kjonn != 'k') {
		cin >> kjonn;
	}
}

Deltager::~Deltager() {
	// Må lages
}

void Deltager::endre(int hva) { // Endrer deltagers data (ikke id)
	cout << "\nDeltagersdNavn: "; cin >> dNavn;
	cout << "\nDeltagers kjønn(m/k): "; cin >> kjonn;
}

void Deltager::display() {	//Skriver ut deltagers data
	cout << "\nID: " << number;
	cout << "\nNavn: " << dNavn;
	cout << "\nKjonn: " << kjonn;
}
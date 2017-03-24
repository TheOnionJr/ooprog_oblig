#include "../Headers/headere.h"

Deltager::Deltager() {	// Deltagers data skrives inn
	// ID ligger i numElement construtor
	cout << "\nDeltagers navn: "; cin navn;
	cout << "\nDeltagers kjønn(m/k): "; cin kjonn;
}

Deltager::~Deltager() {
	// Må lages
}

void Deltager::endre() { // Endrer deltagers data (ikke id)
	cout << "\nDeltagers navn: "; cin navn;
	cout << "\nDeltagers kjønn(m/k): "; cin kjonn;
}

void Deltager::skrivData() {	//Skriver ut deltagers data
	cout << "\nID: " << number;
	cout << "\nNavn: " << navn;
	cout << "\nKjonn: " << kjonn;
}
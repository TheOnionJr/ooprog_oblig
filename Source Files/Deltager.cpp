#include "../Headers/headere.h"

Deltager::Deltager() {	// Deltagers data skrives inn
	// ID ligger i numElement construtor
	cout << "\nDeltagersdNavn: "; cin >> dNavn;
	cout << "\nDeltagers kj�nn(m/k): "; cin >> kjonn;
}

Deltager::~Deltager() {
	// M� lages
}

void Deltager::endre(int hva) { // Endrer deltagers data (ikke id)
	cout << "\nDeltagersdNavn: "; cin >> dNavn;
	cout << "\nDeltagers kj�nn(m/k): "; cin >> kjonn;
}

void Deltager::display() {	//Skriver ut deltagers data
	cout << "\nID: " << number;
	cout << "\nNavn: " << dNavn;
	cout << "\nKjonn: " << kjonn;
}
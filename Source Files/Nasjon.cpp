#include "../Headers/headere.h"

Nasjon:Nasjon{
	// Forkortelsen til nasjonen:
	   cout << "\nVenligst skriv inn nasjonens forkortelse: ";
	   cin >> forkortelse;

	// Nasjonens fulle navn:
	   cout << "\nVenligst skriv inn nasjonens fulle navn: ";
	   char buffer[NVNLEN];
	   cin.ignore();
	   cin.getline(buffer, NVNLEN);
	   fulltNavn = new char[strlen(buffer) + 1]; strcpy(fulltNavn, buffer);

	// Nasjonens kontaktperson:
	   cout << "\nVenligst skriv inn navnet på nasjonens kontaktperson: ";
	   cin.ignore();
	   cin.getline(buffer, NVNLEN);
	   kontaktNavn = new char[strlen(buffer) + 1]; strcpy(kontaktNavn, buffer);

	// Nummeret til denne kontaktpersonen:
	   cout << "\nVenligst skriv inn tlfnummer til " << kontaktNavn << ": ";
	   cin >> kontaktNr;
}

Nasjon:~Nasjon{
	   // Sletter alle data:
	   delete[] forkortelse, fulltNavn, kontaktNavn; delete kontaktNr;
	   // Egen for deltagere må legges til
}
void Nasjon : endre(int hva) { // TRENGER CASE FOR DELTAGERE
	switch (hva)
	{
	case 1:		//Endre fullt navn på en nasjon
		char buffer[NVNLEN];
		cout << "\nNasjonens nye navn: ";
		cin.ignore();
		cin.getline(buffer, NAVNLEN);
		fulltNavn = new char[strlen(buffer) + 1]; strcpy(fulltNavn, buffer);
		cout << "\nNavnet er oppdatert. Det er nå: " << fulltNavn << endl;
	case 2:		//Endre kontaktpersons navn
		char buffer[NVNLEN];
		cout << "\nKontaktpersonens nye navn: ";
		cin.ignore();
		cin.getline(buffer, NAVNLEN);
		kontaktNavn = new char[strlen(buffer) + 1]; strcpy(kontaktNavn, buffer);
		cout << "\nNavnet er oppdatert. Det er nå: " << kontaktNavn << endl;
	case 3:		//Endre kontaktpersons nummer
		cout << "\nKontaktpersonens nye tlfnummer: ";
		cin >> kontaktNr;
		cout << "\nTlfnummeret er oppdatert. Det er nå: " << kontaktNr << endl;
	default:
		break;
	}
}
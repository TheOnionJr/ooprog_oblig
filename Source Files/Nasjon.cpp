#include "../Headers/headere.h"

Nasjon::Nasjon(){
	while(nasjoner->inList(text) || (strlen(text) > 3 || strlen(text) <= 0)){
		TextElement:TextElement();		//Spør om id på nytt om finnes allerede
	}

	// Nasjonens fulle navn:
	   les("\nVenligst skriv inn nasjonens fulle navn: ", fulltNavn, NVNLEN);

	// Nasjonens kontaktperson:
	   cout << "\nVenligst skriv inn navnet på nasjonens kontaktperson: ";
	   les("\nVenligst skriv inn navnet på nasjonens kontaktperson: ", kontaktNavn, NVNLEN);

	// Nummeret til denne kontaktpersonen:
	   les("\nVenligst skriv inn kontaktpersonens tlfnummer: ", MINTLF, MAXTLF);

	   deltagere = new List(Sorted);	//Lager deltagere listen
}

Nasjon::~Nasjon(){
	   // Sletter alle data:
	   delete[] forkortelse, fulltNavn, kontaktNavn;
	   // Egen for deltagere må legges til
}

void Nasjon::endre(int hva) { // TRENGER CASE FOR DELTAGERE
	switch (hva)
	{
	case 1:		//Endre fullt navn på en nasjon
		les("\nNasjonens nye navn: ", fulltNavn, NVNLEN);
		cout << "\nNavnet er oppdatert. Det er nå: " << fulltNavn << endl;
		break;
	case 2:		//Endre kontaktpersons navn
		les("\nKontaktpersonens nye navn: ", kontaktNavn, NVNLEN);
		cout << "\nNavnet er oppdatert. Det er nå: " << kontaktNavn << endl;
		break;
	case 3:		//Endre kontaktpersons nummer
		les("\nKontaktpersonens nye tlfnummer: ", MINTLF, MAXTLF);
		cout << "\nTlfnummeret er oppdatert. Det er nå: " << kontaktNr << endl;
		break;
	default:
		break;
	}
}

void Nasjon::display() {	//Skriver hoveddata om nasjonen
	cout << "\nForkortelse: " << text;
	cout << "Navn: " << fulltNavn;
	cout << "Antall deltagere: " << deltagere->noOfElements();
}

void Nasjon::displayAll() {  //Skriver all data om en gitt nasjon
	cout << "\nForkortelse: " << text;
	cout << "\nNavn: " << fulltNavn;
	cout << "\nKontakt: " << kontaktNavn;
	cout << "\nKontakt nummer: " << kontaktNr;

	cout << "\n\nNasjonens deltagere: ";
	if (deltagere->noOfElements() > 0) {
		for (int i = 0; i < deltagere->noOfElements(); i++) {
			Deltager* hjelpeDeltager;
			hjelpeDeltager = (Deltager*) deltagere->removeNo(i);
			cout << "\n"; hjelpeDeltager->display();
			deltagere->add(hjelpeDeltager);
		}
	}
	else {
		cout << "\nNasjonen har ingen deltagere.";
	}
}
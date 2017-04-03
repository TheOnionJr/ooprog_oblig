#include "../Headers/Nasjon.h"
#include "../Headers/Const.h"
#include <iostream>
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Deltager.h"
#include "../Headers/main.h"
#include "../Headers/Deltagere.h"


Nasjon::Nasjon(){
	/*while(nasjoner->inList(text) || (strlen(text) > 3 || strlen(text) <= 0)){
		TextElement:TextElement();		//Sp�r om id p� nytt om finnes allerede
	}

	// Nasjonens fulle navn:
	   les("\nVenligst skriv inn nasjonens fulle navn: ", fulltNavn, NVNLEN);
	*/

	
}

Nasjon::Nasjon(char id[NASJKORTLEN]) : TextElement(id){
	// Nasjonens fulle navn:
	cout << "\nVennligst skriv inn det fulle navnet p� nasjonen: ";
	fulltNavn = lesPrivat();

	// Nasjonens kontaktperson:
	cout << "\nVenligst skriv inn navnet p� nasjonens kontaktperson: ";
	kontaktNavn = lesPrivat();

	// Nummeret til denne kontaktpersonen:
	kontaktNr = les("\nVenligst skriv inn kontaktpersonens tlfnummer: ", MINTLF, MAXTLF);

	antDeltagere = 0;
}

Nasjon::~Nasjon(){
	// Sletter alle data:
	delete[] fulltNavn, kontaktNavn;
	// Egen for deltagere m� legges til
}

void Nasjon::endre(char hva) { // TRENGER CASE FOR DELTAGERE
	switch (hva)
	{
	case 'N':		//Endre fullt navn p� en nasjon
		les("\nNasjonens nye navn: ", fulltNavn, NVNLEN);
		cout << "\nNavnet er oppdatert. Det er n�: " << fulltNavn << endl;
		break;
	case 'K':		//Endre kontaktpersons navn
		les("\nKontaktpersonens nye navn: ", kontaktNavn, NVNLEN);
		cout << "\nNavnet er oppdatert. Det er n�: " << kontaktNavn << endl;
		break;
	case 'T':		//Endre kontaktpersons nummer
		les("\nKontaktpersonens nye tlfnummer: ", MINTLF, MAXTLF);
		cout << "\nTlfnummeret er oppdatert. Det er n�: " << kontaktNr << endl;
		break;
	case 'X':
		cout << "\nAvslutter endring av nasjon." << endl;
		break;
	default:
		cout << "\nDette er ikke et valg.";
		break;
	}
}

void Nasjon::display() {	//Skriver hoveddata om nasjonen
	cout << "\nForkortelse:\t\t" << text;
	cout << "\nNavn:\t\t\t" << fulltNavn;
	cout << "\nAntall deltagere:\t" << antDeltagere;
}

void Nasjon::displayDeltagere() {
	deltagere->skrivDeltagerListe(text);
}

void Nasjon::displayAll() {  //Skriver all data om en gitt nasjon
	display();
	cout << "\nKontaktperson:\t\t" << kontaktNavn;
	cout << "\nTelefonnummer:\t\t" << kontaktNr;
	displayDeltagere();
}

void Nasjon::leggTilDeltager() {
	antDeltagere++;
}

void Nasjon::fjernDeltager() {
	antDeltagere--;
}
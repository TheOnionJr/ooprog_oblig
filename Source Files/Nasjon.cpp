#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include "../Headers/Nasjon.h"
#include "../Headers/Const.h"
#include <iostream>
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Deltager.h"
#include "../Headers/main.h"
#include "../Headers/Deltagere.h"
#include <fstream>

using namespace std;


Nasjon::Nasjon(){
	/*while(nasjoner->inList(text) || (strlen(text) > 3 || strlen(text) <= 0)){
		TextElement:TextElement();		//Spør om id på nytt om finnes allerede
	}

	// Nasjonens fulle navn:
	   les("\nVenligst skriv inn nasjonens fulle navn: ", fulltNavn, NVNLEN);
	*/

	
}

Nasjon::Nasjon(char* navn) : TextElement(navn){
	// Nasjonens fulle navn:
	cout << "\nVennligst skriv inn det fulle navnet på nasjonen: ";
	fulltNavn = lesPrivat();

	// Nasjonens kontaktperson:
	cout << "\nVenligst skriv inn navnet på nasjonens kontaktperson: ";
	kontaktNavn = lesPrivat();

	// Nummeret til denne kontaktpersonen:
	kontaktNr = les("\nVenligst skriv inn kontaktpersonens tlfnummer: ", MINTLF, MAXTLF);

	antDeltagere = 0;
}

Nasjon::Nasjon(char* id, ifstream &innfil) : TextElement(id) {
	char midNavn[NVNLEN];								//Temp navn
	innfil.getline(midNavn, NVNLEN);					//Getliner temp navn
	fulltNavn = new char[strlen(midNavn) + 1];			//Setter fullt navn
	strcpy(fulltNavn, midNavn);
	innfil >> antDeltagere;								//Setter antall deltagere
	innfil.ignore();							
	innfil.getline(midNavn, NVNLEN);					//Henter nytt temp navn
	kontaktNavn = new char[strlen(midNavn) + 1];		//Setter kontaktens navn
	strcpy(kontaktNavn, midNavn);
	innfil >> kontaktNr;								//Setter kontaktens tlf
}

Nasjon::~Nasjon(){
	// Sletter alle data:
	delete[] fulltNavn, kontaktNavn;
	// Egen for deltagere må legges til
}

void Nasjon::endre(char hva) { // TRENGER CASE FOR DELTAGERE
	switch (hva)
	{
	case 'N':		//Endre fullt navn på en nasjon
		les("\nNasjonens nye navn: ", fulltNavn, NVNLEN);
		cout << "\nNavnet er oppdatert. Det er nå: " << fulltNavn << endl;
		break;
	case 'K':		//Endre kontaktpersons navn
		les("\nKontaktpersonens nye navn: ", kontaktNavn, NVNLEN);
		cout << "\nNavnet er oppdatert. Det er nå: " << kontaktNavn << endl;
		break;
	case 'T':		//Endre kontaktpersons nummer
		kontaktNr = les("\nKontaktpersonens nye tlfnummer: ", MINTLF, MAXTLF);
		cout << "\nTlfnummeret er oppdatert. Det er nå: " << kontaktNr << endl;
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

void Nasjon::displayKontakt() {
	cout << "\nKontaktperson:\t\t" << kontaktNavn;
	cout << "\nTelefonnummer:\t\t" << kontaktNr;
}

void Nasjon::displayDeltagere() {
	deltagere->skrivDeltagerListe(text);
}

void Nasjon::displayAll() {  //Skriver all data om en gitt nasjon
	display();
	displayKontakt();
	displayDeltagere();
}

void Nasjon::leggTilDeltager() {
	antDeltagere++;
}

void Nasjon::fjernDeltager() {
	antDeltagere--;
}

int Nasjon::returnAntDeltagere() {
	return(antDeltagere);
}

void Nasjon::skrivTilFil(ofstream &utfil) {
	utfil << text << endl << fulltNavn << endl << antDeltagere
		<< endl << kontaktNavn << endl << kontaktNr;
}
#include "../Headers/Deltagere.h"
#include "../Headers/Deltager.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/main.h"
#include <iostream>
#include <fstream>

using namespace std;

void Deltagere::deltagermeny() {		//Menyen for deltagere
	char kommando;
	deltagerMeny();						//Skriver deltagermeny
	kommando = lesKommando();
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':
			nyDeltager();				//Lager en ny deltager
			break;
		case 'E':
			endreDeltager();			//Endrer en eksisterende deltager
			break;
		case 'A':
			skrivDeltagerliste();		//Skriver hoveddataene om alle deltagere
			break;
		case 'S':
			skrivDeltager();			//Skriver all data om en deltager
			break;
		default:
			break;
		}
		deltagerMeny();					//Skriver deltagermeny
		kommando = lesKommando();
	}
}

void Deltagere::nyDeltager() {			//Lager ny deltager
	char nasjonalitet[NASJKORTLEN];
	int nummer;
	cout << "\nHva er deltagerens nasjonalitet (forkortelse på 3 bokstaver)?\t";
	cin.getline(nasjonalitet, (NASJKORTLEN));		//Henter ønsket nasjonalitet på deltageren
	if (nasjoner->inList(nasjonalitet)) {			//Sjekker om nasjonen finnes
		nummer = les("\nHvilket nummer har deltageren?\t", DIVMIN, DIVMAX);	//Henter ønsket id på deltageren
		if (!deltagerliste->inList(nummer)) {		//Sjekker at id'en ikke er tatt
			Deltager* hjelpeobjekt = new Deltager(nummer, nasjonalitet);	//Lager deltageren
			deltagerliste->add(hjelpeobjekt);		//Legger til deltageren i lista
			nasjoner->leggTilDeltager(nasjonalitet);		//Legger til 1 i nasjonens antDeltagere
		}
		else										//Hvis id'en er i bruk allerede
			cout << "\nDeltager finnes allerede.";
	}
}

void Deltagere::endreDeltager() {		//Endrer en deltager
	char kommando = '0';
	int nummer;
	cout << "\nHva er nummeret til deltageren du vil endre på?\t";
	cin >> nummer;		//Henter ønsket deltagers id fra brukeren
	if (deltagerliste->inList(nummer)) {	//Om deltageren finnes
		Deltager* hjelpeobjekt = (Deltager*)deltagerliste->remove(nummer);		//Henter deltageren fra liste
		while (kommando != 'X') {		//Utføres til brukeren skriver 'X'
			endreDeltagerMeny();			//Endringsmeny
			kommando = lesKommando();		//Leser kommando
			hjelpeobjekt->endre(kommando);	//UtfÃ¸rer kommando
											//Looper til bruker skriver kommando 'X'
		}
		deltagerliste->add(hjelpeobjekt);	//Legger deltageren tilbake i deltagerlista
		kommando = 'V';		//Så bruker kan velge nye ting
	}
	else		//Hvis deltageren ikke blir funnet
		cout << "\nFant ikke deltageren.";
}

void Deltagere::skrivDeltagerListe(const char* t) {		//Skriver all info om deltagere i en viss nasjon
	if (deltagerliste->noOfElements() > 0) {			//Sjekker at det faktisk eksisterer deltagere
		for (int i = 1; i <= deltagerliste->noOfElements(); i++) {		//Går gjennom alle deltagere
			Deltager* hjelpeobjekt = (Deltager*)deltagerliste->removeNo(i);	//Henter deltager fra lista
			if (strcmp(t, hjelpeobjekt->returnKortNavn()) == 0) {	//Sjekker om deltageren er i valgt nasjon
				hjelpeobjekt->display();		//Viser deltagerens info
			}
			deltagerliste->add(hjelpeobjekt);	//Legger deltageren tilbake i lista
		}
	}
	else		//Hvis nasjonen ikke eksisterer
		cout << "\nNasjonen har ingen deltagere.";
}

void Deltagere::endreDeltagerMeny() {			//Skriver meny for endring av deltagere
	cout << "\nHva vil du endre på?" << endl
		<< "Navn:\t\t\tA" << endl
		<< "Nasjonalitet:\tB" << endl
		<< "Kjønn:\t\t\tC" << endl
		<< "Gå tilbake:\t\tX";
}
bool Deltagere::finnesDeltager(int id){			//Returnerer om en deltager eksisterer i den private lista deltagerliste
	if(deltagerliste->inList(id)){
		return true;
	}
	else{
		return false;
	}
}

void Deltagere::skrivDeltager() {				//Skriver all info om en gitt deltager
	int id;
	cout << "\nHva er nummeret til deltageren du vil se info om?: ";
	cin >> id;									//Henter brukerens ønskede deltager-id
	if (deltagerliste->inList(id)) {			//Sjekker at deltageren eksisterer i lista
		Deltager* hjelpeobjekt = (Deltager*) deltagerliste->remove(id);	//Henter deltageren fra lista
		hjelpeobjekt->display();										//Viser informasjonen
		cout << "\nNasjonalitet: " << hjelpeobjekt->returnKortNavn();	//Viser informasjonen
		deltagerliste->add(hjelpeobjekt);		//Legger deltageren tilbake i lista
	}
}

void Deltagere::skrivForOvelse(int id) {		//Skriver ut informasjonen om en deltager som er nødvendig i en øvelse
	if (deltagerliste->inList(id)) {			//Sjekker at deltageren eksisterer
		Deltager* hjelpeobjekt = (Deltager*) deltagerliste->remove(id);		//Henter deltageren fra lista
		hjelpeobjekt->ovelseDisplay();			//Viser informasjon
		deltagerliste->add(hjelpeobjekt);		//Legger deltageren tilbake i lista
	}
}

void Deltagere::skrivDeltagerliste() {			//Skriver ut hele deltagerlista
	deltagerliste->displayList();
}

Deltager* Deltagere::plsHelp(int id) {			//Returnerer et deltagerobjekt som kan brukes i ovelse
	Deltager* hjelpeobjekt = (Deltager*)deltagerliste->remove(id);		//Henter deltageren fra lista
	return (hjelpeobjekt);						//Returnerer objektet
}

void Deltagere::thankYou(Deltager* hjelpeobjekt) {		//Legger tilbake deltageren i lista
	deltagerliste->add(hjelpeobjekt);
}

void Deltagere::skrivTilFil() {
	ofstream utfil("DELTAGERE.DTA");
	if (utfil) {
		utfil << deltagerliste->noOfElements() << endl;
		for (int i = 1; i <= deltagerliste->noOfElements(); i++) {
			Deltager* hjelpeobjekt = (Deltager*)deltagerliste->removeNo(i);
			hjelpeobjekt->skrivTilFil(utfil);
			deltagerliste->add(hjelpeobjekt);
		}
	}
}

void Deltagere::lesFraFil() {
	ifstream innfil("DELTAGERE.DTA");
	if (innfil) {
		int antDeltagere;
		innfil >> antDeltagere;
		for(int i = 1; i <= antDeltagere; i++) {
			int id; innfil >> id; innfil.ignore();
			deltagerliste->add(new Deltager(id, innfil));
		}
	}
}
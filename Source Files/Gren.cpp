#include "../Headers/enumer.h"
#include "../Headers/Const.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Gren.h"
#include "../Headers/Ovelse.h"
#include <iostream>
#include <fstream>
using namespace std;

Gren::Gren(char* text, ifstream &innfil) : TextElement(text) {
	int tempEnum, tempId;					//Hjelpevariabler
	innfil >> tempEnum; innfil.ignore();	//leser inn enum
	pt = (poengSystem)tempEnum ;			//leser inn poengsystem
	innfil >> sisteBrukt; innfil.ignore();	//Leser inn siste brukt
	for (int i = 0; i <= sisteBrukt; i++) {	//Travasjerer
		innfil >> tempId;					//Leser inn id
		innfil.ignore();
		ovelser[i] = new Ovelse(tempId, innfil);	//Kopierer over id
	}
	innfil.ignore();
}
										//Constructor m/navn-parameter.
Gren::Gren(char tempNvn[NVNLEN]) : TextElement(tempNvn) {
	char svar;
	sisteBrukt = -1;
										//Spør om hvordan prestasjon måles.
	cout << "Hvordan måles prestasjon i grenen? 't'=tid, 'p'=poeng: ";
	
	do {
		svar = lesKommando();			//Leser inn og upcaser.
		switch (svar) {
			case'T':					//Valg for 'Tid'
				cout << "\nHvor nøye skal tiden måles? "
					 << "\n\t 1: Tideler."
					 << "\n\t 2: Hundredeler."
					 << "\n\t 3: Tusendeler.\n";
				do {
					svar = lesKommando();
					switch (svar) {
						case '1': pt = tidTi; break;	//Setter enum Tideler.
						case '2': pt = tidHu; break;	//Setter enum Hundredeler.
						case '3': pt = tidTu; break;	//Setter enum Tusendeler.
						default: cout << "Ukjent svar.";//Feilmeld.
					}
				} while (svar != '1' && svar != '2' && svar != '3');
				svar = 'X';				//Sender bruker tilbake til Grener meny.
				break;	
			
			case'P':
				cout << "\nHvor mange desimaler skal poengskalaen ha? "
					 << "\n\t 1: 1."
					 << "\n\t 2: 2.";
				do {
					svar = lesKommando();
					switch (svar) {			//Setter antall siffer i poengskala.
						case '1': pt = poengH;	break;			//En desimal.
						case '2': pt = poengK;	break;			//To desimaler.
						default: cout << "Ukjent svar!"; break; //Feilmeld. 
					}
				} while (svar != '1' && svar != '2');
				svar = 'X';				//Sender bruker tilbake til grener meny.
				break;	//Setter enum til poeng.

			default:					//Feilmelding.
				cout << "Ukjent svar, skriv 'T' for tid, eller 'P' for poeng.";
				break;
		}								//do-whie som looper til godkjent svar.
	} while (svar != 'T' && svar != 'P' && svar != 'X');
}

/*Gren::~Gren(){							//Destructor
	delete[]  pt;						//Sletter alle data.
	delete sisteBrukt;
}*/

										//Funksjon for å endre data i en gren.
void Gren :: endre() {
	cout << "\nSkriv inn nytt navn.\n";
	text = lesPrivat();					//Leser inn navnet som skal endres
	cout << "\nNavnet er endret, det er nå " << text << ".";	//Endrer navnet
}

void Gren::nyOvelse() {					//Lager ny øvelse
	int id;
	id = les("\nSkriv inn øvelsens ID: ", DIVMIN, DIVMAX);
	if(finnesAllerede(id) != -1) {		//Sjekker om øvelses-id'en allerede eksisterer
		cout << "\nDenne øvelsen finnes allerede!";
	}
	else if(sisteBrukt >= 19) {			//Hvis arrayen allerede er full
		cout << "\nDet er ikke plass til flere øvelser!";
	}
	else {								//Hvis det er plass
		sisteBrukt++;
		ovelser[sisteBrukt] = new Ovelse(id);	//Lager ny øvelse
	}
}

void Gren::endreOvelse(){			//Endrer en øvelse
	bool finnes = false;				//Starter som false, endres hvis den faktisk finnes
	int id;							//id som skal endres
	id = les("\nSrkiv inn øvelsens ID: ", DIVMIN, DIVMAX);
	for(int i = 0; i <= sisteBrukt; i++){	//Går gjennom øvelses-lista
		if(ovelser[i] && ovelser[i]->returnID() == id){		//Hvis id'en til ovelsen matcher
			ovelser[i]->endre();		//Øvelsen blir endret
			finnes = true;
		}
	}
	if(!finnes){		//Hvis ingen øvelser matchet id'en
		cout << "\nFant ikke ovelsen.";
	}
}

void Gren::slettOvelse(){
	int id = les("\nID til øvelsen du ønsker å fjerne: ", DIVMIN, DIVMAX);	//Leser inn hvilken id
	bool finnes = false;
	for(int i = 0; i <= sisteBrukt; i++) {							//Finner øvelse med tilsvarende id
		if(ovelser[i] && ovelser[i]->returnID() == id){				//Om den finnes
			finnes = true;											//Forteller at den finnes
			ovelser[i] = ovelser[sisteBrukt];						//Setter siste brukte lik ovelser[i]
			sisteBrukt--;											//Fjerner ett element
			cout << "Ovelsen er slettet.";							//Bekrefter at øvelsen er slettet
		}
	}
	if(!finnes) {													//Om øvelsen ikke finnes
		cout << "\nFant ikke ovelsen.";								//Git beskjed om at den ikke finnes
	}
}

void Gren::displayOvelser() {		//Displayer alle øvelser
	for(int i = 0; i <= sisteBrukt; i++) {
		if(ovelser[i] != nullptr)		//Om ikke nullpointer
			ovelser[i]->display();		//Viser øvelsen
	}
}

int Gren::finnesAllerede(int id) {		//Sjekker om id'en eksisterer, og hvis den gjør det, returnerer plassen dens i arrayen
	for(int i = 0; i <= sisteBrukt; i++) {
		if(ovelser[i] && ovelser[i]->returnID() == id){	//returnerer i
			return i;
		}
	}
	return -1;			//Returneres dersom ingen id'er matchet, tilsvarer return false
}

										//Skriver alle data om en gren.
void Gren::display() {
	cout << "\nNavn: \t\t" << text;		//Navn.

	cout << "\nTid/poeng: \t";			//Om prestasjonsmåling er tid/poeng.
	switch (pt) {						//Og hvilken type det er.
		case tidTi: cout << "Tid med tideler (Min:Sek:Tidel).";			break;
		case tidHu: cout << "Tid med hundredeler (Min:Sek:Hundredel)."; break;
		case tidTu: cout << "Tid med tusendeler (Min:Sek:Tusendel).";	break;
		case poengH: cout << "Poeng med en desimal.";					break;
		case poengK: cout << "Poeng med to desimaler.";					break;
		default: cout << "Finner ikke prestasjonsmåling!";				break;
	}

	cout << "\nAntall øvelser: " << sisteBrukt;		//Antall øvelser i grenen.
}

poengSystem Gren::returnPt() {		//Returnerer poeng-system
	return(pt);
}

void Gren::skrivTilFil(ofstream &utfil) {
	utfil << text << '\n'					//Skriver navnet på grenen.
		  << pt << '\n'						//Skriver enumen pt.
		  << sisteBrukt << '\n';			//Skriver sisteBrukt.
	for (int i = 0; i <= sisteBrukt; i++) {	//Går gjennom antallet ovelser.
		if(ovelser[i] != nullptr)			//Om ikke nullpointer
			ovelser[i]->skrivTilFil(utfil);	//Skriver ut til fil
	}
	utfil << '\n';							//Formatering
}

void Gren::startListe() {
	int id;															//ID
	char kommando;													//Kommando
	id = les("\nSkriv en øvelses-id.", DIVMIN, DIVMAX);				//Leser inn ID
	if (finnesAllerede(id) != -1) {									//Sjekker om ID finnes allerede
		ovelser[finnesAllerede(id)]->lesInnStartListe();			//Leser inn startlste
		ovelser[finnesAllerede(id)]->lesResFraFil();				//Leser inn resultatliste
		deltagerlisteMeny();										//Skriver meny
		kommando = lesKommando();									//Leser valg
		while (kommando != 'X') {	
			switch (kommando) {
			case 'S':												//Skriver liste
				ovelser[finnesAllerede(id)]->skrivStartListe();	
				break;
			case 'N':												//Legger til ny deltager
				ovelser[finnesAllerede(id)]->nyDeltager();
				break;
			case 'E':												//Endrer liste
				ovelser[finnesAllerede(id)]->endreListe();
				break;
			case 'F':												//Sletter startlisten
				ovelser[finnesAllerede(id)]->fjernStartliste();
				break;
			default:
				break;
			}
			deltagerlisteMeny();									//Skriver deltagerliste
			kommando = lesKommando();								//Leser inn brukers valg
		}
	}
	else
		cout << "\nId-en ble ikke funnet.";
}

void Gren::resultatListe() {										//Jobber på resultatliste
	int id;															//ID variabel
	char kommando;													//Brukers valg
	id = les("\nSkriv en øvelses-id.", DIVMIN, DIVMAX);				//Leser inn hvilken ID som skal endres
	if (finnesAllerede(id) != -1) {									//Sjekker om ID faktisk finnes
		ovelser[finnesAllerede(id)]->lesInnStartListe();			//Leser inn starliste
		ovelser[finnesAllerede(id)]->lesResFraFil();				//Leser inn resultatliste
		resultatlisteMeny();										//Viser resultatmeny
		kommando = lesKommando();									//Leser brukers valg
		while (kommando != 'X') {	
			switch (kommando) {
			case 'S':												//Viser resultatlisten
				ovelser[finnesAllerede(id)]->displayRes();
				break;
			case 'N':												//Ny resultatliste
				ovelser[finnesAllerede(id)]->finnes(id, pt);
				break;
			case 'F':												//Fjerner resultatliste
				ovelser[finnesAllerede(id)]->fjernRESlist();
				break;
			default:
				break;
			}
			resultatlisteMeny();									//Viser menyen på nytt
			kommando = lesKommando();								//leser brukerns valg
		}
	}
	else
		cout << "\nId-en ble ikke funnet.";
}
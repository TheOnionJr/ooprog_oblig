#include "../Headers/enumer.h"
#include "../Headers/Const.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Gren.h"
#include "../Headers/Ovelse.h"
#include <iostream>
#include <fstream>
using namespace std;


										//Constructor m/navn-parameter.
Gren::Gren(char tempNvn[NVNLEN]) : TextElement(tempNvn) {
	char svar;
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
				cout << "\nHvor mange siffer skal poengskalaen ha? "
					 << "\n\t 1: 1."
					 << "\n\t 2: 2.";
				do {
					svar = lesKommando();
					switch (svar) {			//Setter antall siffer i poengskala.
						case '1': pt = poengH;	break;			//Ett siffer.
						case '2': pt = poengK;	break;			//To siffer.
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
	text = lesPrivat();
	cout << "\nNavnet er endret, det er nå " << text << ".";
}

void Gren::nyOvelse() {					//Lager ny øvelse
	int id;
	id = les("\nSkriv inn øvelsens ID: ", DIVMIN, DIVMAX);
	if(finnesAllerede(id) != -1) {		//Sjekker om øvelses-id'en allerede eksisterer
		cout << "\nDenne øvelsen finnes allerede!";
	}
	else if(sisteBrukt > 20) {			//Hvis arrayen allerede er full
		cout << "\nDet er ikke plass til flere øvelser!";
	}
	else {								//Hvis det er plass
		ovelser[sisteBrukt++] = new Ovelse(id);	//Lager ny øvelse
	}
}

void Gren::endreOvelse(){			//Endrer en øvelse
	bool finnes = false;				//Starter som false, endres hvis den faktisk finnes
	int id;							//id som skal endres
	id = les("\nSrkiv inn øvelsens ID: ", DIVMIN, DIVMAX);
	for(int i = 0; i <= DIVMAX; i++){	//Går gjennom øvelses-lista
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
			cout << "Ovelsen er slettet."							//Bekrefter at øvelsen er slettet
		}
	}
	if(!finnes) {													//Om øvelsen ikke finnes
		cout << "\nFant ikke ovelsen.";								//Git beskjed om at den ikke finnes
	}
}

void Gren::displayOvelser() {		//Displayer alle øvelser
	for(int i = 0; i <= sisteBrukt; i++) {
		ovelser[i]->display();
	}
}

int Gren::finnesAllerede(int id) {		//Sjekker om id'en eksisterer, og hvis den gjør det, returnerer plassen dens i arrayen
	for(int i = 0; i <= sisteBrukt; i++) {
		if(ovelser[i] && ovelser[i]->returnID() == id){
			return i;
		}
	}
	return -1;			//Returneres dersom ingen id'er matchet, tilsvarer return false
}

										//Skriver alle data om en gren.
void Gren::display() {
	cout << "\nNavn: \t" << text;		//Navn.

	cout << "\nTid/poeng: \n";			//Om prestasjonsmåling er tid/poeng.
	switch (pt) {						//Og hvilken type det er.
		case tidTi: cout << "Tid med tideler (Min:Sek:Tidel).";			break;
		case tidHu: cout << "Tid med hundredeler (Min:Sek:Hundredel)."; break;
		case tidTu: cout << "Tid med tusendeler (Min:Sek:Tusendel).";	break;
		case poengH: cout << "Poeng med et siffer.";					break;
		case poengK: cout << "Poeng med to siffer.";					break;
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
	for (int i = 0; i >= sisteBrukt; i++) {	//Går gjennom antallet ovelser.
		utfil << ovelser[i] << '\n';		//Skriver ovelsen.
	}
	utfil << '\n';
}
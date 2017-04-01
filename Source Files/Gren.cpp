#include "../Headers/enumer.h"
#include "../Headers/Const.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Gren.h"
#include "../Headers/Ovelse.h"
#include <iostream>
using namespace std;


										//Constructor.
/*Gren::Gren() : TextElement {

}*/

										//Constructor m/navn-parameter.
Gren::Gren(char tempNvn[NVNLEN]) : TextElement(tempNvn) {
	char svar;
										//Sp�r om hvordan prestasjon m�les.
	cout << "Hvordan m�les prestasjon i grenen? 't'=tid, 'p'=poeng: ";
	
	do {
		svar = lesKommando();			//Leser inn og upcaser.
		switch (svar) {
			case'T':					//Valg for 'Tid'
				cout << "\nHvor n�ye skal tiden m�les? "
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

										//Funksjon for � endre data i en gren.
void Gren :: endre() {
	cout << "\nSkriv inn nytt navn.\n";
	text = lesPrivat();
	cout << "\nNavnet er endret, det er n� " << text << ".";
}

void Gren::nyOvelse() {
	int id;
	id = les("\nSkriv inn �velsens ID: ", DIVMIN, DIVMAX);
	if(finnesAllerede(id) != 0) {
		cout << "\nDenne �velsen finnes allerede!";
	}
	else if(sisteBrukt > 20) {
		cout << "\nDet er ikke plass til flere �velser!";
	}
	else {
		ovelser[sisteBrukt++] = new Ovelse(id);
	}
}

void Gren::endreOvelse(){
	bool fant = false;
	int id;
	id = les("\nSrkiv inn �velsens ID: ", DIVMIN, DIVMAX);
	for(int i = 0; i <= DIVMAX; i++){
		if(ovelser[i] && ovelser[i]->returnID() == id){
			ovelser[i]->endre();
			fant = true;
		}
	}
	if(fant = false){
		cout << "\nFant ikke ovelsen.";
	}
}

int Gren::finnesAllerede(int id) {
	for(int i = 0; i <= sisteBrukt; i++) {
		if(ovelser[i] && ovelser[i]->returnID() == id){
			return i;
		}
	}
	return 0;
}

										//Skriver alle data om en gren.
void Gren::display() {
	cout << "\nNavn: \t" << text;		//Navn.

	cout << "\nTid/poeng: \n";			//Om prestasjonsm�ling er tid/poeng.
	switch (pt) {						//Og hvilken type det er.
		case tidTi: cout << "Tid med tideler (Min:Sek:Tidel).";			break;
		case tidHu: cout << "Tid med hundredeler (Min:Sek:Hundredel)."; break;
		case tidTu: cout << "Tid med tusendeler (Min:Sek:Tusendel).";	break;
		case poengH: cout << "Poeng med et siffer.";					break;
		case poengK: cout << "Poeng med to siffer.";					break;
		default: cout << "Finner ikke prestasjonsm�ling!";				break;
	}

	cout << "\nAntall �velser: " << sisteBrukt;		//Antall �velser i grenen.
}
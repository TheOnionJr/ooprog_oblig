#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "../Headers/Nasjoner.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/Nasjon.h"
#include "../Headers/main.h"
#include "../Headers/Ovelse.h"
#include "../Headers/ListTool2B.h"
#include "../Headers/Deltagere.h"
#include "../Headers/Deltager.h"
#include "../Headers/Gren.h"
#include "../Headers/Grener.h"
#include <iostream>
#include <fstream>
#include <stdio.h>


using namespace std;
 

Ovelse::Ovelse(){
	cout << "\n\nERROR THIS IS NOT POSSIBLE";	//Error
}

Ovelse::Ovelse(int id) : NumElement(id) {
	char midNavn[NVNLEN];					//Temp navn
	cout << "\nVennligst skriv inn øvelsens fulle navn: ";
	cin.ignore(); cin.getline(midNavn, NVNLEN);	//leser inn temp navn
	fulltNavn = new char[strlen(midNavn) + 1];
	strcpy(fulltNavn, midNavn);				//string copyer navn

	filnavnRES(id);
	filnavnSTA(id);
	int ss, mm, tt;
	do{
		tt = les("\nTimer: ",0,24); 		//Leser timer
		mm = les("\nMinutt: ",0,60);		//Leser minutt
		ss = les("\nSekund: ",0,60);		//Leser sekund
		if(!checkTime(ss, mm, tt)){
			cout << "\nUgyldig tidspunkt!";
		}
		else {
			makeTime(ss, mm, tt);
			cout << "\nTidspunktet er registrert.";
		}
	}while(!checkTime(ss, mm, tt));

	int month, day, year;
	do{
		day = les("\nDag: ", 1,31);		    //Leser hvilken dag
		month = les("\nMåned: ",1,12);		//Leser hvilken måned
		year = les("\nÅr: ",0,9999);		//Leser hvilket år
		year = year % 100;				   //year ikke overskriver 2 karakterer
		if(!checkDate(month, day, year)) {	//Sjekker om datoen er gyldig
			cout << "\nUgyldig dato!";		//Gir beskjed om ugyldig
		}
		else {
			makeDate(day, month, year);		//Lagrer datoen om den er gyldig
			cout << "\nDato registrert.";	//Gir beskjed om registrert
		}
	} while (!checkDate(day, month, year));
}

Ovelse::Ovelse(int id, ifstream &innfil) : NumElement(id) {
	char midNavn[NVNLEN];						//Lager temp navn
	innfil.getline(tidspunkt, 8);				//Leser inn tidspunkt
	innfil.getline(dato, 8);					//Leser inn dato
	innfil >> antDeltagere;						//Leser inn antall deltagere
	innfil.ignore();							//ignore
	innfil.getline(midNavn, NVNLEN);			//Getliner navnet
	fulltNavn = new char[strlen(midNavn) + 1];	//Setter navnet
	strcpy(fulltNavn, midNavn);					//Stricopyer navnet
	filnavnRES(id);								//Leser inn hvilken RES fil som skal jobbes med
	filnavnSTA(id);								//Leser inn hvilken STA fil som skal jobbes med
}

Ovelse::~Ovelse() {
	fjernStartliste(); fjernRESlist();		//Sletter assosierte filer
	delete[] fulltNavn, grenNavn;			//Sletter arrays
}

void Ovelse::endre() {
	char midNavn[NVNLEN];					//Temp navn
	cout << "\nVennligst skriv inn øvelsens fulle navn: ";
	cin.ignore(); cin.getline(midNavn, NVNLEN);		//Leser inn temp navn
	fulltNavn = new char[strlen(midNavn) + 1];
	strcpy(fulltNavn, midNavn);						//Stringcopyer nytt navn

	int ss, mm, tt;							//Temp variabler for tid
	do{
		ss = les("\nSekund: ",0,60);		//Leser sekund
		mm = les("\nMinutt: ",0,60);		//Leser minutt
		tt = les("\nTimer: ",0,24); 		//Leser timer
		if(!checkTime(ss, mm, tt)){			//Om tidspunktet er ulovlig
			cout << "\nUgyldig tidspunkt!";
		}
		else {
			makeTime(ss, mm, tt);			//Lager dette om til et tidspunkt som kan skrives ut
			cout << "\nTidspunktet er registrert.";
		}
	}while(!checkTime(ss, mm, tt));

	int month, day, year;					//Temp variabler for dato
	do{
		day = les("\nDag: ", 1,31);		    //Leser hvilken dag
		month = les("\nMåned: ",1,12);		//Leser hvilken måned
		year = les("\nÅr: ",0,9999);		//Leser hvilket år
		year = year % 100;				   //year ikke overskriver 2 karakterer
		if(!checkDate(day, month, year)) {	//Sjekker om datoen er gyldig
			cout << "\nUgyldig dato!";		//Gir beskjed om ugyldig
		}
		else {
			makeDate(day, month, year);		//Lagrer datoen om den er gyldig
			cout << "\nDato registrert.";	//Gir beskjed om registrert
		}
	} while (!checkDate(day, month, year));
}

int Ovelse::returnID(){						// Returnerer id
	return number;
}

void Ovelse::display() {					//Skriver ut info om øvelsen
	cout << "\nID: " << number;				//Skriver ut id
	cout << "\nFullt Navn: " << fulltNavn;	//Skriver ut fullt navn
	cout << "\nTidspunkt: " << tidspunkt;	//Skriver ut tidspunkt
	cout << "\nDato: " << dato;				//Skriver ut dato
	cout << "\nAntall Deltagere: " << antDeltagere;	//Skriver ut antall deltagere
	displayRes();							//Skriver ut resultatlisten
}

void Ovelse::nyDeltager(){
	bool finnes = false;					//Bool for sjekk
	cout << "\nLag en ny deltagerliste:\n";
	ifstream innfil(filSTA);				//Leser inn fra fil
	if(!innfil) {							//Lager ny liste
		char kommando = 'N';				//Temp kommando for fortsettelse
		int i = 0;							//Hvor det jobbes i i arrayet
		while(kommando != 'Y'){					//Om bruker ikke vil avslutte
			if(antDeltagere == MAXDELTAGERE-1){				// Om listen er full
				cout << "\nListen er nå full";	//Gir beskjed om full liste
				kommando = 'Y';					//Exiter
			}
			do{									
				finnes = false;					//Resetter finnes bool
				int temp = les("\nSkriv deltagerens ID: ", DIVMIN, DIVMAX);	//Spør om deltagers id
				for(int k = 0; k <= MAXDELTAGERE; k++) {		//Sjekker om den finnes enda
					if(temp == startListe[k]){					//Om finnes
						finnes = true;							//Sier att det finnes
						cout << "\nDenne deltageren finnes allerede!";	//Gir beskjed
					}
				}
				if(!finnes){									//Om den ikke finnes
					startListe[i] = temp;						//Legger til deltageren
				}
			}while(finnes);
			while(!deltagere->finnesDeltager(startListe[i])){	//Om deltageren ikke finnes
				cout << "\nDenne deltageren finnes ikke!";
				startListe[i] = les("\nSkriv inn deltagerens ID: ",DIVMIN,DIVMAX);
			}
			if(kommando != 'Y'){											//Om listen ikke er full
				i++;														//Går til neste array
				antDeltagere++;												//Øker antall deltagere
				cout << "\nVil du avslutte? (y/n): ";						//Spør om bruker vil avslutte
				kommando = lesKommando();									//Leser inn kommando
			}
		}
		innfil.close();										//Lukker ifstream
		ofstream utfil(filSTA);								//Åpner ofstream
		for(int i = 0; i < antDeltagere; i++){				//Skriver ut for alle deltagere
			utfil << startListe[i] << "\n";					//Skriver ID til fil
		}
	}
	else{		//Gir beskjed om det allerede finnes en liste
		cout << "\nDet finnes allerede en startliste!";
	}
}

void Ovelse::fjernStartliste(){	//Fjerner den eksisterende startlisten
	antDeltagere = 0;			//Setter antall deltagere til null
	remove(filSTA);				//Sletter filen
}

void Ovelse::fjernRESlist(){				//Fjerner resultatlisten
	poeng->trekkFraPoeng(filRES);			
	medaljer->trekkFraMedaljer(filRES);
	sisteBrukt = (-1);
	remove(filRES);
}

void Ovelse::endreListe() {
	lesInnStartListe();										//Leser inn starlisten fra fil									
	ifstream innfil(filSTA);								//Åpner ifstream
	if(innfil){												//Om det er en ifstream
		if(startListe) {									//Om startlisten finnes
			cout << "\nDette er deltagerene som er i listen fra før: ";
			for(int i = 0; i < antDeltagere; i++) {			//Viser de deltagerne som er i listen
				cout << "\n" << startListe[i];
			}
			//Spør bruker om hva han/hun vil gjøre
			cout << "\nHva vil du gjøre?";
			cout << "\nN: Legge til ny deltager.";
			cout << "\nE: Endre eksisterende deltager";
			cout << "\nF: Fjerne en deltager";
			cout << "\nX: Gå ut";
			char kommando = lesKommando();		//Leser kommando
			while(kommando != 'X'){
				switch(kommando){				//Switch
					int temp;
					bool finnes;
					case 'N':					//legge til deltager
					while(kommando != 'Y'){					//Om bruker ikke vil avslutte
						if(antDeltagere == MAXDELTAGERE-1){				// Om listen er full
							cout << "\nListen er nå full";	//Gir beskjed om full liste
							kommando = 'Y';					//Exiter
						}
						do{									
							finnes = false;					//Resetter finnes bool
							int temp = les("\nSkriv deltagerens ID: ", DIVMIN, DIVMAX);	//Spør om deltagers id
							for(int k = 0; k <= antDeltagere; k++) {		//Sjekker om den finnes enda
								if(temp == startListe[k]){					//Om finnes
									finnes = true;							//Sier att det finnes
									cout << "\nDenne deltageren finnes allerede!";	//Gir beskjed
								}
							}
							if(!finnes){									//Om den ikke finnes
								startListe[antDeltagere] = temp;			//Legger til deltageren
							}
						}while(finnes);
						while(!deltagere->finnesDeltager(startListe[antDeltagere])){	//Om deltageren ikke finnes
							cout << "\nDenne deltageren finnes ikke!";
							startListe[antDeltagere] = les("\nSkriv inn deltagerens ID: ",DIVMIN,DIVMAX);
						}
						if(kommando != 'Y'){											//Om listen ikke er full														//Går til neste array
							antDeltagere++;												//Øker antall deltagere
							cout << "\nVil du avslutte? (y/n): ";						//Spør om bruker vil avslutte
							kommando = lesKommando();									//Leser inn kommando
						}
					}
					break;
					case 'E':
						temp = les("\nID til den du ønsker å endre: ", DIVMIN, DIVMAX);	//Leser deltagers ID
						finnes = false;													//resetter finnes
						for(int i = 0; i < antDeltagere; i++){							//Travasjerer for å finne evt match
							if(startListe[i] == temp){									//Om det finnes match
								finnes = true;											//Sier fra at det finnes en match
							}
						}
						while(!deltagere->finnesDeltager(temp) || !finnes){				//Om deltageren ikke finnes
								cout << "\nDenne deltageren finnes ikke!";				//Gir besked om at deltageren ikke finnes
								temp = les("\nSkriv inn deltagerens ID: ",DIVMIN,DIVMAX);//Leser inn deltager på nytt
						}
						for(int i = 0; i < antDeltagere; i++){							//Finner deltageren
							if(temp == startListe[i]){									//Endrer deltagerID
								temp = les("\nDen nye ID til deltager: ", DIVMIN, DIVMAX);
								startListe[i] = temp;
							}
						}
					break;
					case 'F':
						temp = les("\nID til den du ønsker å fjerne: ", DIVMIN, DIVMAX);//Leser inn deltager ID
						finnes = false;													//Resetter finnes bool
						int posisjon = 0;												//Hjelprevariabel for å holde styr på posisjon
						while(!deltagere->finnesDeltager(temp) || !finnes){				//Om deltageren ikke finnes
								for(int i = 0; i < antDeltagere; i++){
									if(startListe[i] == temp){							//Finner hvilken posisjon iden er i
										finnes = true;									//Om deltageren finnes i den posisjonen
										posisjon = i;									//Lagrer den posisjonen
									}
								}
								if(!deltagere->finnesDeltager(temp) || !finnes) {		//Sjekker om deltageren finnes
									cout << "\nDenne deltageren finnes ikke!";			//Gir beskjed om at deltageren ikke finnes
									temp = les("\nSkriv inn deltagerens ID: ",DIVMIN,DIVMAX);//Leser inn på nytt
								}
						}
						for (posisjon; posisjon < antDeltagere; posisjon++) {			//Sletter og sorterer listen
							startListe[posisjon] = startListe[posisjon+1];				//Sorterer idere
						}
						antDeltagere--;													//Sier at det nå finnes en mindre deltager
					break;
				}
				//Leser på nytt hva brukeren ønsker
				cout << "\nHva vil du gjøre?";
				cout << "\nN: Legge til ny deltager.";
				cout << "\nE: Endre eksisterende deltager";
				cout << "\nF: Fjerne en deltager";
				cout << "\nX: Gå ut";
				kommando = lesKommando();
			}
		}
		innfil.close();										//Lukker innstream
		ofstream utfil(filSTA);								//Åpner utstream
		for(int i = 0; i < antDeltagere; i++){				//Skriver ut alle ID'ene
			utfil << startListe[i] << "\n";					//Skriver ID til fil
		}
	}
}

void Ovelse::lesInnStartListe() {					//Leser inn starlisten
	ifstream innfil(filSTA);						//Inn-stream
	if(innfil){										//Om instream
		for(int i = 0; i < antDeltagere; i++){		//Leser inn alle verdiene
			innfil >> startListe[i];
		}
	}
}

void Ovelse::skrivStartListe() {					//SKRIVER ALLE DELTAGERE I STARTLISTE
	lesInnStartListe();								//Laster inn startlisten
	for(int i = 0; i < antDeltagere; i++){			//Går gjennom arrayen
		cout << "\nStartnummer: " << i+1;			//Skriver startnummeret
		deltagere->skrivForOvelse(startListe[i]);	//Skriver ut data om deltageren
	}
}

bool Ovelse::checkDate(int day, int month, int year){
	int maxDager;
	bool gyldigDato = true;
	if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
        (month = 8) || (month = 10) || (month = 12)) //Om måneden har 31 dager
    {
        maxDager = 31;
    }
    else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))	
    {												//Eller 30 dager
        maxDager = 30;
    }
    else if ((month = 2) && (year % 4 == 0))		//Eller februar og skuddår
    {
    	maxDager = 29;
    }
    else if ((month = 2) && (year % 4 != 0))		//Eller ikke
    {
        maxDager = 28;
    }
    if ((month < 1) || (month > 12))				//Om måneden finnes
    {
        gyldigDato = false;
    }
    else if((day > maxDager) || (day < 0)){			//Om ikke for mange dager
    	gyldigDato = false;
    }
    return gyldigDato;
}

bool Ovelse::checkTime(int ss, int mm, int tt) {
	bool gyldigTid = true;
	if((ss < 0) || (ss >= 60)) {					//Om !innenfor ett minutt
		gyldigTid = false;
	}
	else if((mm < 0) || (mm >= 60)){				//Om !innnenfor en time
		gyldigTid = false;
	}
	else if((tt < 0) || (tt >= 24)){				//Om !innenfor ett døgn
		gyldigTid = false;
	}
	return gyldigTid;
}

void Ovelse::makeDate(int day, int month, int year){ //Setter kolon mellom Short medium og long
	char buffer[3];					//Buffer

	if(day < 10) {
		strcpy(dato, "0");			//legger til '0' for å holde formatet
		_itoa(day, buffer, 10);		//int -> char
	}
	else if(day >= 10){
		_itoa(day, buffer, 10);		//Legger sekund til buffer
	}
	strcpy(dato, buffer);			//Legger over fra buffer til char array
	strcat(dato, ".");				//Legger til ':' for format SS:MM:TT
	if(month < 10) {
		strcat(dato, "0");			//legger til '0' for å holde formatet
		_itoa(month, buffer, 10);	//int -> char
	}
	else{
		_itoa(month, buffer, 10);	//Legger til minutt i buffer
	}
	strcat(dato, buffer);			//Legger over fra buffer til char array
	strcat(dato, ".");				//Legger til ':' for format SS:MM:TT
	if(year < 10) {
		strcat(dato, "0");			//Legger til '0' for å holde formatet
		_itoa(year, buffer, 10);	//int -> char
	}
	else{
		_itoa(year, buffer, 10);	//Legger til timer i buffer
	}
	strcat(dato, buffer);			//Legger over fra buffer til char array
}

void Ovelse::makeTime(int s, int m, int t){ //
	char buffer[3];		//Buffer

	if(s < 10) {
		strcpy(tidspunkt, "0");			//legger til '0' for å holde formatet
		_itoa(s, buffer, 10);			//int -> char
	}
	else if(s > 10){
		_itoa(s, buffer, 10);			//Legger sekund til buffer
	}
	strcpy(tidspunkt, buffer);			//Legger over fra buffer til char array
	strcat(tidspunkt, ":");				//Legger til ':' for format SS:MM:TT
	if(m < 10) {
		strcat(tidspunkt, "0");			//legger til '0' for å holde formatet
		_itoa(m, buffer, 10);			//int -> char
	}
	else{
		_itoa(m, buffer, 10);			//Legger til minutt i buffer
	}
	strcat(tidspunkt, buffer);			//Legger over fra buffer til char array
	strcat(tidspunkt, ":");				//Legger til ':' for format SS:MM:TT
	if(t < 10) {
		strcat(tidspunkt, "0");			//Legger til '0' for å holde formatet
		_itoa(t, buffer, 10);			//int -> char
	}
	else{
		_itoa(t, buffer, 10);			//Legger til timer i buffer
	}
	strcat(tidspunkt, buffer);			//Legger over fra buffer til char array
}


void Ovelse::filnavnSTA(int id) {			//Funksjon som genererer filnavn for en ovelse.
	char filnavn[FILLEN];					//Filnavnet.
	char buffer[FILLEN];					//Mellomlagring.

	_itoa(id, buffer, 10);					//Skriver om inten id til char-mellomlagringa.
	strcpy(filnavn, "OV");					//Kopierer OV i starten av filnavn.
	strcat(filnavn, buffer);				//appender nummeret til ovelsen bak 'OV' i filnavn.
	strcat(filnavn, ".STA");				//appender '.STA' på slutten av filnavn.
	filSTA = new char[strlen(filnavn) + 1];
	strcpy(filSTA, filnavn);				//Setter filnavnet.
}

void Ovelse::filnavnRES(int id) {			//Funksjon som genererer filnavn for en ovelse.
	char filnavn[FILLEN];					//Filnavnet.
	char buffer[FILLEN];					//Mellomlagring.

	_itoa(id, buffer, 10);					//Skriver om inten id til char-mellomlagringa.
	strcpy(filnavn, "OV");					//Kopierer OV i starten av filnavn.
	strcat(filnavn, buffer);				//appender nummeret til ovelsen bak 'OV' i filnavn.
	strcat(filnavn, ".RES");				//appender '.RES' på slutten av filnavn.
	filRES = new char[strlen(filnavn) + 1];
	strcpy(filRES, filnavn);				//Setter filnavnet.
}

void Ovelse::finnes(int id, poengSystem pd) {				//Funksjon som sjekker om fil finnes/er i bruk.
	int tempSiste;											//Mellomlagring.
	ifstream innfil(filRES);								//Henter inn riktig fil.
	if(innfil)
		innfil >> tempSiste;								//Leser inn sistebrukt.
	if ((innfil && (tempSiste <= 0)) || !innfil)			//Sjekker om filen finnes og  ikke er i bruk eller om den ikke finnes.
		nyResList(id, pd);									//Kaller funksjon for å lage ny liste.
	else
		cout << "Lista finnes allerede!";					//Feilmelding hvis lista finnes og er i bruk.
}

void Ovelse::nyResList(int id, poengSystem pt) {			//Lager ny resultatliste.
	ps = pt;												//Setter poengsystemet
	sisteBrukt = -1;

	for (int i = 0; i < antDeltagere; i++) {				//Teller gjennom antall deltagere.

		strcpy(nasj[i], deltagere->returnDeltakersKortNavn(startListe[i]));			//Henter ut nasjonaliteten til deltager nr i.
		strcpy(deltNavn[i], deltagere->returnDeltakersNavn(startListe[i]));			//Henter ut navnet til deltager i.

		switch(ps) {							//Switch etter hvilken enum som er i bruk.
			case(poengH):						//Poengtype: hopp. Form: x.
				cout << "\nHvor mange poeng fikk " << deltNavn[i] 
					 << " fra " << nasj[i] <<  " ? (xxx der den siste er desimal) ";	//Spør hvor mange poeng deltager fra land fikk.
				score[i] = les(" ", 0, 999); 							//Leser inn poeng.
				break;
			case(poengK):						//Poengtype: kunstløp. Form: xx.
				cout << "\nHvor mange poeng fikk " << deltNavn[i] 
					 << " fra " << nasj[i] << " ? (xxxx der de to siste er desimaler): ";//Spør hvor mange poeng deltager fra land fikk.
				score[i] = les("", 0, 9999);										//Leser inn poeng.
				break;
			case(tidTi):						//Tid med tideler.
				cout << "\nHvilken tid fikk " << deltNavn[i]			
					 << " fra " << nasj[i] << "? (på formen mmsst): ";	//Spør hvilken tid deltager fra land fikk.
				score[i] = les("",0,59599);								//Leser inn tid.
				break;
			case(tidHu):						//Tid med hundredeler.
				cout << "\nHvilken tid fikk " << deltNavn[i]			
					 << " fra " << nasj[i] << "? (på formen mmssth): ";	//Spør hvilken tid deltager fra land fikk.
				score[i] = les("",0,595999);							//Leser inn tid.
				break;
			case(tidTu):						//Tid med tusendeler.
				cout << "\nHvilken tid fikk " << deltNavn[i] 
					 << " fra " << nasj[i] << "? (på formen mmsstht): ";//Spør hvilken tid deltager fra land fikk.
				score[i] = les("",0,5959999);							//Leser inn tid.
				break;
			default:
				cout << "shit's fuck'd";		//Feilmelding
				break;
		}
		sisteBrukt++;								//Teller opp sisteBrukt.
		if(i != 0)
			sorter();								//Sorterer array.
	}
	skrivResTilFil();
	medaljer->leggTilMedaljer(filRES);
	poeng->leggTilPoeng(filRES);
}

void Ovelse::sorter() {			//Funksjon som går gjennom arrayen og sorterer etter medaljeverdi.
	if (ps == poengH || ps == poengK) {
		for (int i = sisteBrukt; i > 0; i--) {				//Går gjennom arrayen.	
			if (score[i] >= score[i - 1]) {					//Sjekker om i-1 er større.
				char temp[NASJKORTLEN];						//Mellomlagring nasjonsforkortelse.
				char tempNvn[NVNLEN];						//Mellomlagring navn.
				int tempi;									//Mellomlagring score.b

				strcpy(tempNvn, deltNavn[i]); strcpy(temp, nasj[i]); tempi = score[i];						//Kopierer i inn i mellomlagring.
				strcpy(deltNavn[i], deltNavn[i - 1]); strcpy(nasj[i], nasj[i - 1]); score[i] = score[i - 1];	//Setter i til i-1.
				strcpy(deltNavn[i - 1], tempNvn); strcpy(nasj[i - 1], temp); score[i - 1] = tempi;	//Kopierer fra mellomlagring til i.
			}
		}
	}
	else {
		for (int i = sisteBrukt; i > 0; i--) {				//Går gjennom arrayen.	
			if (score[i] <= score[i - 1]) {					//Sjekker om i-1 er større.
				char temp[NASJKORTLEN];						//Mellomlagring nasjonsforkortelse.
				char tempNvn[NVNLEN];						//Mellomlagring navn.
				int tempi;									//Mellomlagring score.b

				strcpy(tempNvn, deltNavn[i]); strcpy(temp, nasj[i]); tempi = score[i];						//Kopierer i inn i mellomlagring.
				strcpy(deltNavn[i], deltNavn[i - 1]); strcpy(nasj[i], nasj[i - 1]); score[i] = score[i - 1];	//Setter i til i-1.
				strcpy(deltNavn[i - 1], tempNvn); strcpy(nasj[i - 1], temp); score[i - 1] = tempi;	//Kopierer fra mellomlagring til i.
			}
		}
	}
}

void Ovelse::skrivResTilFil() {							//Funksjon som skriver resultatlista til fil.
	ofstream utfil(filRES);								//Finner filen.

	if (utfil) {										//Sjekker om filen finnes/blir opprettet.
		utfil << sisteBrukt << endl;					//Skriver sisteBrukt til starten av filen.
		for (int i = 0; i <= sisteBrukt; i++) {			//Teller gjennom antall entries i filen.
			utfil << nasj[i] << '\n';					//Skriver nasjon.
			utfil << score[i] << '\n';					//Skriver score.
			utfil << deltNavn[i] << "\n\n";				//Skriver deltagernavnet. + hopper over en linje.
		}
	}
}

void Ovelse::lesResFraFil() {							//Leser resultatliste fra fil.
	ifstream innfil(filRES);							//Finner filen.

	if (innfil) {										//Hvis filen finnes...
		innfil >> sisteBrukt; innfil.ignore();			//Leser inn sisteBrukt og hopper til neste linje.
		for (int i = 0; i <= sisteBrukt; i++) {			//Teller gjennom alle entries i filen.
			innfil.getline(nasj[i], NASJKORTLEN + 1);	//Leser inn nasjonen.
			innfil >> score[i]; innfil.ignore();		//Leser inn score.
			innfil.getline(deltNavn[i], NVNLEN + 1);	//Leser inn deltagernavnet.
			innfil.ignore();							//Ignorerer en linje.
		}
	}
}


void Ovelse::hentPs() {								//Henter enumen ps.
	Gren* hjelpeGren = grener->plsHelp(grenNavn);		//grenNavn = navnet som blir hentet inn når man kaller 'O'.
	ps = (hjelpeGren->returnPt());						//returnerer poengsystemet
	grener->thankYou(hjelpeGren);						//caller thank you
}

void Ovelse::displayRes() {								//Viser resultat
	for (int i = 0; i <= sisteBrukt; i++) {				//travasjerer
		cout << "\n Navn: " << deltNavn[i]				//Viser navn
		 	 << "\n Nasjon: " << nasj[i]				//Viser nasjon
			 << "\t Poeng/tid: "; displayScore(i);		//Viser poeng
		cout << "\n\n";
	}
}

void Ovelse::displayScore(int t) {
	int mm, ss, d;
	switch (ps) {
		case poengH:
			ss = score[t] / 10;
			d = score[t] % 10;
			cout << ss << "." << d; 
			break;
		case poengK: 
			ss = score[t] / 100;
			d = score[t] % 100;
			cout << ss << "." << d;
			break;
		case tidTi: 
			mm = score[t] / 1000;
			ss = (score[t] - (mm * 1000)) / 10;
			d = score[t] % 10;
			cout << mm << ":" << ss << "." << d;
			break;
		case tidHu:
			mm = score[t] / 10000;
			ss = (score[t] - (mm * 10000)) / 100;
			d = score[t] % 100;
			cout << mm << ":" << ss << "." << d;
			break;
		case tidTu:
			mm = score[t] / 100000;
			ss = (score[t] - (mm * 100000)) / 1000;
			d = score[t] % 1000;
			cout << mm << ":" << ss << "." << d;
			break;
	}
}

void Ovelse::skrivTilFil(ofstream &utfil) {
	utfil << number << endl << tidspunkt << endl << dato
		<< endl << antDeltagere << endl << fulltNavn << endl;
}
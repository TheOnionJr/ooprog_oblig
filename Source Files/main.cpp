#include "../Headers/headere.h"

using namespace std;

List* nasjoner;							//'Nasjoner' liste, sortert.
List* grener;							//'Grener' liste, sortert.
char kommando;

int main() {
	
	nasjoner = new List(Sorted);		// 'Nasjoner' liste,  sortert
						
	grener = new List(Sorted);			//'Grener' liste, sortert. 
	

	skrivMeny();                        //  Skriver brukermeny.

	kommando = lesKommando();           //  Får inn brukers ønske.
										//  Looper til 'x'/'X' tastes:
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':
			char id[NASJKORTLEN];				//Landets forkortelse
			nasjonerMeny();
			kommando = lesKommando();
			while (kommando != 'X') {
				switch (kommando)
				{
				case 'N':					//Legge til en ny nasjon
					les("\nVennligst skriv landets forkortelse: ", id, NASJKORTLEN);
					if (!nasjoner->inList(id)) {	//Om landet ikke finnes
						nasjoner->add(new Nasjon(id));//lager nytt land
					}
					else {	//Om landet finnes fra før
						cout << "\nNasjonen eksisterer allerede.";
					}
					break;
				case 'E': 					//Endre eksisterende nasjon
					les("\nForkortelsen til den nasjonen du vil endre: ", id, NASJKORTLEN);
					if (nasjoner->inList(id)) {	//Om landet finnes
						Nasjon* hjelpenasjon = (Nasjon*)nasjoner->remove(id);
						while (kommando != 'X') {
							endreNasjonerMeny();			//Endringsmeny
							kommando = lesKommando();		//Leser kommando
							hjelpenasjon->endre(kommando);	//Utfører kommando
							//Looper til bruker skriver kommando 'X'
						}
						nasjoner->add(hjelpenasjon);
						kommando = 'V';		//S� bruker kan velge nye ting
					}
					else
						cout << "\nFant ikke nasjonen.";
					break;			
				case 'A':					//Alle hoveddata om alle nasjoner
					nasjoner->displayList();
					break;
				case 'T': break;			//Skriv en nasjons deltagertropp
				case 'S': 					//Skriver alle data om en nasjon
					while(!nasjoner->inList(id)){ //Sjekker om nasjon finnes
						les("\nLandets forkortelse", id, NASJKORTLEN);
					}
					nasjoner->displayElement(id);	//Skriver ut data
					break;			
				case 'X': break;			//Gå tilbake
				default:
					nasjonerMeny();
					break;
				}
				kommando = lesKommando(); //Bruker skriver her kommando for nasjonsmeny
			}
			break;
		case 'D':	break;
		case 'G':							//Valg for Gren.
			grenMeny();						//Skriver undermeny for grener.
			kommando = lesKommando();		//Leser kommando.
			while (kommando != 'X') {		
				switch (kommando) {
					case 'N':				//Oppretter ny gren.
						char tempNvn[NVNLEN];

						les("Grenens navn", tempNvn, NVNLEN);	//Leser inn navnet til grenen.
						if (!grener->inList(tempNvn))			//Sjekker om finnes allerede.
							grener->add(new Gren(tempNvn));		//Legger til grenen.
						else                //Feilmelding.
							cout << "En gren med det navnet finnes allerede!";

						 break;
					case 'E':				//Endrer navnet på en gren.
						char grenNvn[NVNLEN];	//Temp. for sammenligning.
						Gren* hjelpeGren;		//Hjelpepeker.
										//Spør om navnet på gren som skal endres.
						les("Navnet på grenen du vil endre", grenNvn, NVNLEN);
											//Hvis grenen finnes...
						if (grener->inList(grenNvn)) {
							hjelpeGren = (Gren*)grener->remove(grenNvn);
							hjelpeGren->endre();	//Fjerner, endrer, og adder
							grener->add(hjelpeGren);//grenen i lista.
						}
						else {				//Feilmeld.
							cout << "\nFant ikke en gren med det navnet!\n";
						}
						break;
					case 'A': 
						grener->displayList();
						break;
					case 'S': break;
					default: 
						nasjonerMeny();	break;
				}
				kommando = lesKommando(); //Bruker skriver her kommando for gren-meny
			}
		case 'O':	break;
		case 'M':	break;
		case 'P':	break;
		case 'X':	break;
		default:	skrivMeny();        break;
		}
		kommando = lesKommando();		//  Får inn brukers ønske.
	}
	return 0;
}

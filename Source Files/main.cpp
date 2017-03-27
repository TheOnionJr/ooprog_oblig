#include "../Headers/headere.h"

using namespace std;

int main() {
	
	nasjoner = new List(Sorted);		// 'Nasjoner' liste,  sortert
						
	grener = new List(Sorted);			//'Grener' liste, sortert. 
	

	skrivMeny();                        //  Skriver brukermeny.

	kommando = lesKommando();           //  Får inn brukers ønske.
										//  Looper til 'x'/'X' tastes:
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':
			nasjonerMeny();
			kommando = lesKommando();
			while (kommando != 'X') {
				switch (kommando)
				{
				case 'N':					//Legge til en ny nasjon
					char tempNavn[NVNLEN];
					les("\nVennligst skriv landets fulle navn: ", tempNavn, NVNLEN);
					if (!nasjoner->inList(tempNavn)) {
						nasjoner->add(new Nasjon(tempNavn));
					}
					else {
						cout << "\nNasjonen eksisterer allerede.";
					}
					break;
				case 'E': break;			//Endre eksisterende nasjon
				case 'A':					//Alle hoveddata om alle nasjoner
					nasjoner->displayList();
					break;
				case 'T': break;			//Skriv en nasjons deltagertropp
				case 'S': 					//Skriver alle data om en nasjon
					char kort[3];			//Hjelpecariabel
					while(!nasjoner->inList(kort)){ //Sjekker om nasjon finnes
						les("\nLandets forkortelse", kort, 3);
					}
					nasjoner->displayElement(kort);	//Skriver ut data
					break;			
				case 'X': break;			//Gå tilbake
				default:
					nasjonerMeny();
					break;
				}
				kommando = 'V';				//Så bruker kan velge nye ting
			}
			break;
		case 'D':	break;
		case 'G':	break;					//Valg for Gren.
			grenMeny();						//Skriver undermeny for grener.
			kommando = lesKommando();		//Leser kommando.
			while (kommando != 'X') {		
				switch (kommando) {
					case 'N':				//Oppretter ny gren.
						char tempNvn[NVNLEN];

						les("Grenens navn", tempNvn, NVNLEN);	//Leser inn navnet til grenen.
						if (grener->inList(tempNvn))	//Sjekker om finnes allerede.
							grener->add(new Gren(tempNvn));	//Legger til grenen.
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
					case 'A': break;
					case 'S': break;
					default: 
						nasjonerMeny();	break;
				}
				kommando = 'V'; //Så bruker kan velge nye ting.
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
#include "../Headers/headere.h"

using namespace std;

int main() {
	List* nasjoner;						// 'Nasjoner' liste,  sortert
	nasjoner = new List(Sorted);
	List* grener;					
	grener = new List(Sorted);			//'Grener' liste, sortert. 
	char kommando;

	skrivMeny();                        //  Skriver brukermeny.

	kommando = lesKommando();           //  F�r inn brukers �nske.
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
					nasjoner->add(new Nasjon);
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
				case 'X': break;			//G� tilbake
				default:
					nasjonerMeny();
					break;
				}
				kommando = 'V'; //S� bruker kan velge nye ting
			}
			break;
		case 'D':	break;
		case 'G':	break;					//Valg for Gren.
			grenMeny();						//Skriver undermeny for grener.
			kommando = lesKommando();		//Leser kommando.
			while (kommando != 'X') {		
				switch (kommando) {
					case 'N':				//Oppretter ny gren.
						grener->add(new Gren); break;
					case 'E': break;
					case 'A': break;
					case 'S': break;
					default: 
						nasjonerMeny();	break;
				}
				kommando = 'V'; //S� bruker kan velge nye ting.
			}
		case 'O':	break;
		case 'M':	break;
		case 'P':	break;
		case 'X':	break;
		default:	skrivMeny();        break;
		}
		kommando = lesKommando();		//  F�r inn brukers �nske.
	}
	return 0;
}
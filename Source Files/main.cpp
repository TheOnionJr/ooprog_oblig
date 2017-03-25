#include "../Headers/headere.h"

using namespace std;

int main() {
	List* nasjoner;						// 'Nasjoner' liste,  sortert
	nasjoner = new List(Sorted);
	List* grener;					
	grener = new List(Sorted);			//'Grener' liste, sortert. 
	char kommando;

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
				case 'N':
					nasjoner->add(new Nasjon);
					break;
				case 'E': break;
				case 'A':
					nasjoner->displayList();
					break;
				case 'T': break;
				case 'S': break;
				case 'X': break;
				default:
					nasjonerMeny();
					break;
				}
				kommando = 'V'; //Så bruker kan velge nye ting
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
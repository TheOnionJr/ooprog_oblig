#include "../Headers/headere.h"

using namespace std;

int main() {
	List* nasjoner;						// 'Nasjoner' liste,  sortert
	nasjoner = new List(Sorted);
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
				case 'N':
					nasjoner->add(Nasjon* nasjon);
				case 'E':
				case 'A':
				case 'T':
				case 'S':
				case 'X':
				default:
					nasjonerMeny();
					break;
				}
				kommando = 'V'; //S� bruker kan velge nye ting
			}
			break;
		case 'D':	break;
		case 'G':	break;
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
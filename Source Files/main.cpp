#include "../Headers/headere.h"

using namespace std;

int main() {
	char kommando;

	skrivMeny();                        //  Skriver brukermeny.

	kommando = lesKommando();           //  F�r inn brukers �nske.
										//  Looper til 'x'/'X' tastes:
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':	break;
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
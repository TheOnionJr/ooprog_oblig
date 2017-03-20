#include "../Headers/Const.h"
#include "../Headers/ListTool2B.h"
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	char kommando;

	skrivMeny();                        //  Skriver brukermeny.

	kommando = lesKommando();           //  Får inn brukers ønske.
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
		default:   skrivMeny();        break;
		}
		kommando = lesKommando();                  //  Får inn brukers ønske.
	}
	return 0;
}
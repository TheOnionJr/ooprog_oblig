#include <iostream>
#include "../Headers/Const.h"
#include "../Headers/Deltagere.h"
#include "../Headers/Enumer.h"
#include "../Headers/Grener.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Gren.h"
#include "../Headers/ListTool2B.h"
#include "../Headers/main.h"
#include "../Headers/Medaljer.h"
#include "../Headers/Nasjon.h"
#include "../Headers/Nasjoner.h"
#include "../Headers/Poeng.h"
#include "../Headers/Statistikk.h"

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 


char kommando;
Nasjoner* nasjoner = new Nasjoner();
Deltagere* deltagere = new Deltagere();
Grener* grener = new Grener();
Medaljer* medaljer = new Medaljer();
Poeng* poeng = new Poeng();

int main() {						

	skrivMeny();                        //  Skriver brukermeny.

	kommando = lesKommando();           //  Får inn brukers ønske.
										//  Looper til 'x'/'X' tastes:
	while (kommando != 'X') {
		switch (kommando) {
		case 'N':						//Valg for nasjoner.
			nasjoner->nasjonsmeny();
			break;
		case 'D':						//Valg for deltagere.
			deltagere->deltagermeny();
			break;
		case 'G':						//Valg for Gren.
			grener->grenerMeny();
			break;
		case 'O':	break;
		case 'M':						//Skriver ut hele medaljestatistikken.
			medaljer->displayAll();
			break;
		case 'P':	break;
		case 'X':	break;
		default:	skrivMeny();        break;
		}
		skrivMeny();
		kommando = lesKommando();		//  Får inn brukers ønske.
	}
	return 0;
}

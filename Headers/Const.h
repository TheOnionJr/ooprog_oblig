#if !defined(Const_h)
#define Const_h

//Const.h - Header fil med alle const-er.

int const NVNLEN = 40;					//Navnlengde.
int const STRLEN = 80;					//Stringlengde.
int const NASJKORTLEN = 4;				//Max lengde, nasjonsforkortelse.
int const MAXNASJONER = 200;			//Max antall nasjoner.
int const MAXOVELSER = 50;				//Max antall ovelser.
int const MINDELTAGERE = 5;				//Min antall deltagere.
int const MAXDELTAGERE = 100;			//Max antall deltagere.
int const MINTLF = 10000000;			//Minste numeriske telefonnummer
int const MAXTLF = 99999999;			//Største numeriske telefonnummer
int const DIVMAX = 99999999;			//Høyeste div nummer.
int const DIVMIN = 0;					//Laveste div nummer.
int const FILLEN = 12;					//Lengden på filnavn.
int const PSKALALEN = 10;				//Poengskala lengde. (hvor mange som skal få poeng)
int const POENGSKALA[PSKALALEN] = { 7, 5, 4, 3, 2, 1, 1, 1, 1, 1 };	//Poengskala array.
int const ANTMED = 3;					//Antall medaljer. 
int const MEDVERD[ANTMED] = { 010000, 000100, 000001};				//Verdien for medaljer.
#endif
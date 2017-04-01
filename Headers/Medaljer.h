#if !defined(Medaljer_h)
#define Medaljer_h
#include "Statistikk.h"

class Medaljer : public Statistikk{
private:
	int medaljer[MAXNASJONER];			//Medaljer G,S,B, 010101. <- Eks på en av hver.
	int sisteBrukt;
public:
	Medaljer() {	};
	void display(int i);
	void displayAll();
	void leggTilMedaljer();
	void trekkFraMedaljer();
	void sorter();
	void lesArrayFraFil();
	void skrivArrayTilFil();
};
#endif
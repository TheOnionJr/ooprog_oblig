#if !defined(Poeng_h)
#define Poeng_h
#include "Statistikk.h"

class Poeng : public Statistikk {
private:
	int poeng[MAXNASJONER] = { 0 };			//Antall poeng en nasjon har.
	int sisteBrukt = (-1);
public:
	//Poeng();
	void leggTilPoeng(char* fil);
	void trekkFraPoeng(char* fil);
	void lesArrayFraFil();
	void skrivArrayTilFil();
	void sorter();
	void displayAll();
};
#endif
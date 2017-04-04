#if !defined(Poeng_h)
#define Poeng_h
#include "Statistikk.h"

class Poeng : public Statistikk {
private:
	int poeng[MAXNASJONER];			//Antall poeng en nasjon har.
	int sisteBrukt;
public:
	Poeng() { };
	void leggTilPoeng(char fil[FILLEN]);
	void trekkFraPoeng(char fil[FILLEN]);
	void lesArrayFraFil();
	void skrivArrayTilFil();
	void sorter();
	void displayAll();
	void finnNasjon(char nasjon[NASJKORTLEN]);
};
#endif
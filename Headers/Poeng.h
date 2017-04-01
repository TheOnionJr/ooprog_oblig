#if !defined(Poeng_h)
#define Poeng_h
#include "Statistikk.h"

class Poeng : public Statistikk {
private:
	int poeng;			//Antall poeng en nasjon har.
	int sisteBrukt;
public:
	Poeng() { };
	void leggTilPoeng();
	void trekkFraPoeng();
	void lesArrayFraFil();
	void skrivArrayTilFil();
};
#endif
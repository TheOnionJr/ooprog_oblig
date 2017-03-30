#if !defined(Medaljer_h)
#define Medaljer_h
#include "Statistikk.h"

class Medaljer : public Statistikk{
private:
	int medaljer;			//Medaljer G,S,B, 010101. <- Eks på en av hver.
public:
	Medaljer() {		
	};
	void display();
};
#endif
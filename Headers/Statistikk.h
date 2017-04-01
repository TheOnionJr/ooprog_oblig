#if !defined(Statistikk_h)
#define Statistikk_h
#include "Const.h"

class Statistikk {
	protected:
		char nasjKort[MAXNASJONER][NASJKORTLEN];
	public:
		//Statistikk();
		void displayMed();
};

#endif
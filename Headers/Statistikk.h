#if !defined(Statistikk_h)
#define Statistikk_h
#include "Const.h"

class Statistikk {
	protected:
		char* nasjonsforkortelse[MAXNASJONER];
		int sisteBruktMed;
	public:
		//Statistikk();
		void displayMed();
};

#endif
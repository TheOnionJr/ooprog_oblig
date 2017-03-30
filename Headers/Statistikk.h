#if !defined(Statistikk_h)
#define Statistikk_h
#include "Const.h"

class Statistikk {
	private:
	protected:
		char* nasjonsforkortelse[MAXNASJONER];
		int sisteBruktMed;
	public:
		//Statistikk();
		void displayMed();
};

#endif
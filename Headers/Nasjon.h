#define nasjon_h
#include "headere.h"

class Nasjon : TextElement {
	private:
		// Forkortelsen kommer i constructor til 'TextElement'o
		char* fulltNavn;
		//Deltagere* deltager;		// M� lages
		char* kontaktNavn;
		int kontaktNr;
	public:
		Nasjon();			//Constructor
		~Nasjon();			//Deconstructor
		void endre(int hva); // Valget f�lger med fra en meny
};


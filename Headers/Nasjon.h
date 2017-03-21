#ifndef najson.h
#define nasjon.h
#include "headere.h"

class Nasjon {
	private:
		char forkortelse[3];		//Forkortelse p� navnet
		char* fulltNavn;
		//Deltagere* deltager;		// M� lages
		char* kontaktNavn;
		int kontaktNr;
	public:
		Nasjon();			//Constructor
		~Nasjon();			//Deconstructor
		void endre(int hva); // Valget f�lger med fra en meny
};


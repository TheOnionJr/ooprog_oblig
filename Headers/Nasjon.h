#ifndef najson.h
#define nasjon.h
#include "headere.h"

class Nasjon {
	private:
		char forkortelse[3];		//Forkortelse på navnet
		char* fulltNavn;
		//Deltagere* deltager;		// Må lages
		char* kontaktNavn;
		int kontaktNr;
	public:
		Nasjon();			//Constructor
		~Nasjon();			//Deconstructor
		void endre(int hva); // Valget følger med fra en meny
};


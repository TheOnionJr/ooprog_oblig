#define nasjon_h
#include "../Headers/headere.h"

class Nasjon : public TextElement {
	private:
		char* fulltNavn;
		char forkortelse[NASJKORTLEN];
		List* deltagere;
		char* kontaktNavn;
		int kontaktNr;
	public:
		Nasjon();			//Constructor
		Nasjon(char* navn);
		~Nasjon();			//Deconstructor
		void endre(int hva); // Valget følger med fra en meny
		void display();
		void displayAll();
};


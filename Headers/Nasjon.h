#define nasjon_h
#include "../Headers/headere.h"

class Nasjon : public TextElement {
	private:
		char* fulltNavn;
		List* deltagere;
		char* kontaktNavn;
		int kontaktNr;
	public:
		Nasjon();			//Constructor
		Nasjon(char* navn);
		~Nasjon();			//Deconstructor
		void endre(char hva); // Valget følger med fra en meny
		void display();
		void displayAll();
		void diplayDeltagere();
};


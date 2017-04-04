#if !defined(nasjon_h)
#define nasjon_h
#include "ListTool2B.h"
#include <fstream>

using namespace std;

class Nasjon : public TextElement {
	private:
		char* fulltNavn;
		int antDeltagere;
		char* kontaktNavn;
		int kontaktNr;
	public:
		Nasjon();			//Constructor
		Nasjon(char* navn);
		~Nasjon();			//Deconstructor
		void endre(char hva); // Valget følger med fra en meny
		void display();
		void displayKontakt();
		void displayAll();
		void displayDeltagere();
		void leggTilDeltager();
		void fjernDeltager();
		int returnAntDeltagere();
		void skrivTilFil(ofstream &utfil);
};

#endif
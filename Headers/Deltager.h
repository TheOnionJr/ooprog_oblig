#if !defined(deltager_h)
#define deltager_h
#include "ListTool2B.h"
#include "../Headers/Const.h"
#include <fstream>
using namespace std;

class Deltager : public NumElement {
	private:
		char* dNavn;		// Deltagers navn
		char nasjonalitet[NASJKORTLEN];	// Deltagerens nasjonalitet
		char kjonn;			// m/k (trigger warning)
		
	public:
		Deltager(int id, char* nasj);
		~Deltager();
		void endre(char hva);
		void display();
		void ovelseDisplay();
		char* returnKortNavn();
		char* returnNavn();
		void skrivTilFil(ofstream &utfil);
};
#endif
#if !defined(gren_h)
#define gren_h
#include "enumer.h"
#include "ListTool2B.h"
#include "Ovelse.h"
#include <fstream>

using namespace std;

class Gren : public TextElement {
	private:
		poengSystem pt;
		Ovelse* ovelser[20];
		int sisteBrukt;
	public:
		Gren(char* text, ifstream &innfil);
		Gren(char tempNvn[NVNLEN]);
		//~Gren();
		void endre();
		void display();
		void nyOvelse();
		void endreOvelse();
		void displayOvelser();
		int finnesAllerede(int id);
		poengSystem returnPt();
		void skrivTilFil(ofstream &utfil);
		void slettOvelse();
};
#endif
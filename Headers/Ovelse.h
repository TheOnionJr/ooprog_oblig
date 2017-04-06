#if !defined(Ovelse_h)
#define Ovelse_h
#include "ListTool2B.h"
#include <fstream>
using namespace std;

class Ovelse : public NumElement {
	private:
		char* fulltNavn;
		char tidspunkt[8];
		char dato[8];
		int antDeltagere;
		int startListe[MAXDELTAGERE];
		char filRES[FILLEN];
		char filSTA[FILLEN];
		char* grenNavn;
		int sisteBrukt;
		poengSystem ps;
		int score[MAXDELTAGERE];
		char deltNavn[MAXDELTAGERE][NVNLEN];
		char nasj[MAXDELTAGERE][NASJKORTLEN];

	public:
		Ovelse();
		Ovelse(int id);
		Ovelse(int id, ifstream &innfil);
		~Ovelse();
		void endre();
		void display();
		bool checkDate(int month, int day, int year);
		bool checkTime(int ss, int mm, int tt);
		void makeDate(int month, int day, int year);
		void makeTime(int ss, int mm, int tt);
		int returnID();
		void nyDeltager();
		void endreListe();
		void lesInnStartListe();
		void skrivStartListe();
		void filnavnRES(int id);
		void filnavnSTA(int id);
		void finnes(int id, poengSystem pd);
		void nyResList(int id, poengSystem pt);
		void hentPs();
		void sorter();	
		void lesResFraFil();
		void skrivResTilFil();
		void fjernStartliste();
		void fjernRESlist();
		void displayRes();
		void displayScore(int t);
		void skrivTilFil(ofstream &utfil);
};
#endif
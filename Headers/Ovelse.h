#if !defined(Ovelse_h)
#define Ovelse_h
#include "ListTool2B.h"

class Ovelse : public NumElement {
	private:
		char* fulltNavn;
		char tidspunkt[8];
		char dato[8];
		int antDeltagere;
		int startListe[MAXDELTAGERE];
		// insert resultater liste
		char* grenNavn;
		int sisteBrukt;
		poengSystem ps;
		int score[MAXDELTAGERE];
		char deltNavn[MAXDELTAGERE][NVNLEN];
		char nasj[MAXDELTAGERE][NASJKORTLEN];

	public:
		Ovelse();
		Ovelse(int id);
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
<<<<<<< HEAD
		void lesInnStartListe();
		void skrivStartListe();
		char* filnavn(int id);
=======
		char* filnavnRES(int id);
		char* filnavnSTA(int id);
>>>>>>> 5d39ccbb380aeaa7e8554554841747d367d0f622
		void finnes(int id);
		void nyResList(int id);
		void hentPs();
		void sorter();
};
#endif
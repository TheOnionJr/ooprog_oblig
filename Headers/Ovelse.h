#if !defined(Ovelse_h)
#define Ovelse_h
#include "ListTool2B.h"

class Ovelse : public NumElement {
	private:
		char* fulltNavn;
		char tidspunkt[8];
		char dato[8];
		int antDeltagere;
		int deltagere[MAXDELTAGERE] = {0};
		// insert resultater liste

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
		void ovelseMeny();
		void nyDeltager();
};
#endif
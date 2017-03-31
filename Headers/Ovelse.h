#if !defined(Ovelse_h)
#define Ovelse_h
#include "ListTool2B.h"

class Ovelse : public NumElement {
	private:
		char* fulltNavn;
		int tidspunkt[6];
		char dato[8];
		int antDeltagere;
		// insert deltagere liste
		// insert resultater liste

	public:
		Ovelse();
		Ovelse(int id);
		~Ovelse();
		bool checkDate(int month, int day, int year);
};
#endif
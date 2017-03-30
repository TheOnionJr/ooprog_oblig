#if !defined(Ovelse_h)
#define Ovelse_h
#include "ListTool2B.h"

class Ovelse : public NumElement {
	private:
		char* fulltNavn;
		char tidspunkt[8];
		char dato[6];
		int antDeltagere;
		// insert deltagere liste
		// insert resultater liste

	public:
		Ovelse();
		Ovelse(int id);
		~Ovelse();
};
#endif
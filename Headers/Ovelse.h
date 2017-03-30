#if !defined(Ovelse_h)
#define Ovelse_h
#endif
#include "ListTool2B.h"

class Ovelse : public TextElement {
	private:
		char* fulltNavn;
		char tidspunkt[8];
		char dato[6];
		int antDeltagere;
		// insert deltagere liste
		// insert resultater liste

	public:
		Ovelse();
		Ovelse(char* id);
		~Ovelse();
}
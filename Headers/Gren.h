#define gren_h
#include "headere.h"

using namespace std;

class Gren : TextElement {
	private:
		char navn[NVNLEN];
		poengSystem pt;
		int ovelseNr[20];
		int sisteBrukt;
	public:
		Gren();
		~Gren();
		void endre();
		void skriv();
};
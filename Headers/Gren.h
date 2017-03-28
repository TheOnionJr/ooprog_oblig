#define gren_h
#include "../Headers/headere.h"

using namespace std;

class Gren : public TextElement {
	private:
		char* gNavn;
		poengSystem pt;
		int ovelseNr[20];
		int sisteBrukt;
	public:
		Gren();
		Gren(char tempNvn[NVNLEN]);
		~Gren();
		void endre();
		void display();
};
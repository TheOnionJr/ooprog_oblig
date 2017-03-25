#define gren_h
#include "../Headers/headere.h"

using namespace std;

class Gren : public TextElement {
	private:
		char navn[NVNLEN];
		poengSystem pt;
		int ovelseNr[20];
		int sisteBrukt;
	public:
		Gren();
		~Gren();
		void endre();
		void display();
};
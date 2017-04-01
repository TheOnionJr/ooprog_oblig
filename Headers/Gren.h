#if !defined(gren_h)
#define gren_h
#include "enumer.h"
#include "ListTool2B.h"

using namespace std;

class Gren : public TextElement {
	private:
		poengSystem pt;
		int Ovelser[20];
		int sisteBrukt;
	public:
		Gren();
		Gren(char tempNvn[NVNLEN]);
		~Gren();
		void endre();
		void display();
		void nyOvelse();
};
#endif
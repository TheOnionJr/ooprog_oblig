#if !defined(Grener_h)
#define Grener_h
#include "ListTool2B.h"
#include "Gren.h"

class Grener {
private:
	List* grenliste;
public:
	Grener() {
		grenliste = new List(Sorted);			//'Grener' liste, sortert.
	}
	void grenerMeny();
	void nyGren();
	void endreGren();
	void skrivHovedGren();
	void skrivGren();
	void ovelsemeny();
	Gren* plsHelp(char* id);
	void thankYou(Gren* hjelpeobjekt);
	void displayAllGren();
	void skrivTilFil();
	void lesFraFil();
};

#endif
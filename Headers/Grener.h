#if !defined(Grener_h)
#define Grener_h
#include "ListTool2B.h"

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
};

#endif
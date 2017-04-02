#if !defined(Deltagere_h)
#define Deltagere_h
#include "ListTool2B.h"
#include "Deltager.h"
class Deltagere {
private:
	List* deltagerliste;
public:
	Deltagere() {
		deltagerliste = new List(Sorted);
	}
	void deltagermeny();
	void nyDeltager();
	void endreDeltager();
	void skrivDeltagerListe(const char* t);
	void skrivDeltagerliste();
	void skrivDeltager();
	void endreDeltagerMeny();
	bool finnesDeltager(int id);
	Deltager* plsHelp(int id);
};

#endif
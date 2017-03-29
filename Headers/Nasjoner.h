#if !defined(Nasjoner_h)
#define Nasjoner_h
#include "ListTool2B.h"
						//'Nasjoner' liste, sortert.
class Nasjoner {
private:
	List* nasjonsliste;	
public:
	Nasjoner() {
		nasjonsliste = new List(Sorted);
	}
	void nasjonsmeny();
	void nyNasjon();
	void endreNasjon();
	void visNasjonsDeltagere();
	void visNasjonsInfo();
	bool inList(const char* t);
	void leggTilDeltager(const char* t);
	void fjernDeltager(const char* t);
};
#endif
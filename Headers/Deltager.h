#if !defined(deltager_h)
#define deltager_h
#include "ListTool2B.h"

class Deltager : public NumElement {
	private:
		char* dNavn;		// Deltagers navn
		char* nasjonalitet;	// Deltagerens nasjonalitet
		char kjonn;			// m/k (trigger warning)
		
	public:
		Deltager(int id);
		~Deltager();
		void endre(int hva);
		void display();
		char* returnKortNavn();
};
#endif
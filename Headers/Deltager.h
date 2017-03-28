#if !defined(deltager_h)
#define deltager_h
#include "../Headers/headere.h"

class Deltager : public NumElement {
	private:
		char* dNavn;		// Deltagers navn
		char kjonn;			// m/k (trigger warning)
		
	public:
		Deltager(int id);
		~Deltager();
		void endre(int hva);
		void display();
};
#endif
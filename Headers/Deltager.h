#define Deltager_h
#include "headere.h"

class Deltager : NumElement {
	private:
		char navn[NVNLEN];		// Deltagers navn
		char kjonn[1];			// m/k (trigger warning)
		
	public:
		Deltager();
		~Deltager();
		void endre(int hva);
		void skrivData();
};
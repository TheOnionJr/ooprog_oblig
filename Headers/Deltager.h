#define deltager_h
#include "../Headers/headere.h"

class Deltager : public NumElement {
	private:
		char navn[NVNLEN];		// Deltagers navn
		char kjonn[1];			// m/k (trigger warning)
		
	public:
		Deltager();
		~Deltager();
		void endre(int hva);
		void display();
};
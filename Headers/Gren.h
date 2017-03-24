#pragma once
#ifndef gren.h
#define gren.h
#include "headere.h"

using namespace std;

class Gren : TextElement {
	private:
		char navn[NVNLEN];
		poengSystem pt;
		int ovelseNr[20];
		int sisteBrukt;
	public:
		Gren();
		~Gren();
		void endre();
		void skriv();
};


#endif
#include "../Headers/Statistikk.h"
#include "../Headers/Medaljer.h"
#include <iostream>
using namespace std;

void Medaljer::display() {
	int gull, solv, bronse;
		gull = medaljer / 10000;					//Regner ut antall gull.
		solv = (medaljer - (gull * 10000)) / 100;	//Regner ut antall solv.
		bronse = medaljer % 100;					//Regner ut antall bronse.

		cout << "\nNasjon: " << nasjonsforkortelse	//Skriver ut nasjonen,
			 << "\n Medaljer: Gull: " <<  gull		//antall gull,
			 << "\t Solv: "	  << solv				//antall solv,
			 << "\t Bronse: " << bronse << '\n';	//antall bronse.		
}

void Medaljer::displayAll() {
//	for (int i = 1; i <= sisteBruktMed; i++) {
//		Medaljer[i].display();
}
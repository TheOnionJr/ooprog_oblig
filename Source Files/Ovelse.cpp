#include "../Headers/Nasjoner.h"
#include "../Headers/GlobaleFunksjoner.h"
#include "../Headers/Const.h"
#include "../Headers/Enumer.h"
#include "../Headers/Nasjon.h"
#include "../Headers/main.h"
#include "../Headers/Ovelse.h"
#include <iostream>

using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

Ovelse::Ovelse(){
	cout << "\n\nERROR THIS IS NOT POSSIBLE";
}

Ovelse::Ovelse(int id) : NumElement(id) {
	cout << "\nVenligst skriv inn øvelsens fulle navn: "
	fulltNavn = lesPrivat();

	cout << "\nVenligst skriv inn øvelsens tidspunkt(TTMMSS): "
	do{
		cin >> tidspunkt;
		if((tidspunkt > 240000) || (tidspunkt <= 0)) {
			cout << "\nUgyldig tidspunkt!";
		}
	}while((tidspunkt > 240000) || (tidspunkt <= 0));

	int month, day, year;
	do{
		cout << "\nDag: ";cin >> day;
		cout << "\nMåned: "; cin month;
		cout << "\nÅr: "; cin year;
		if(!checkDate(month, day, year));{
			cout << "\nUgyldig dato!";
		}
		else{
			cout << "\nDato registrert."
		}
	}while(!checkDate(month, day, year));
	strcpy(dato, makeDate(month, day, year));
}

Ovelse::~Ovelse() {

}

bool Ovelse::checkDate(int month, int day, int year){
	int maxDager;
	bool gyldigDato;
	if ((month = 1) || (month = 3) || (month = 5) || (month = 7) ||
        (month = 8) || (month = 10) || (month = 12))
    {
        maxDager = 31;
    }
    else if ((month = 4) || (month = 6) || (month = 9) || (month = 11))
    {
        maxDager = 30;
    }
    else if ((month = 2) && (year % 4 == 0))
    {
    	maxDager = 29;
    }
    else if ((month = 2) && (year % 4 != 0))
    {
        maxDager = 28;
    };
    
    if ((year < 999) || (year > 10000))
    {
        gyldigDato = FALSE;
    }
    else if ((month < 1) || (month > 12))
    {
        gyldigDato = FALSE;
    }
    else if((day > maxDager) || (day < 0)){
    	gyldigDato = FALSE;
    }
    else{
    	gyldigDato = TRUE;
    }
    return gyldigDato;
}

void Ovelse::makeDate(int month, int day, int year){
	char buffer[2];		//Buffer

	strcpy(buffer, day);		//Legger dag til buffer
	strcpy(dato, buffer);		//DD
	strcat(dato, ":");			//DD:
	strcpy(buffer, month);		//Legger måned til buffer
	strcat(dato, buffer);		//DD:MM
	strcat(dato, ":");			//DD:MM:
	strcpy(buffer, year);		//Legger år til buffer
	strcat(dato, buffer);		//DD:MM:YY
}

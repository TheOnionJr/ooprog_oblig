#pragma once
using namespace std;

//Headerfil for globale funksjonsdeklarasjoner.

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//Generelle funksjoner.
void skrivMeny();					//Skriver hovedmeny.
char lesKommando();					//Leser inn og upcaser en char.
int les(const char* t, const int min, const int max);	//Leser inn en int innenfor et intervall.
void les(const char t[], char s[], const int LEN);

//Nasjoner funksjoner.
void nasjonerMeny();				//Skriver undermeny for nasjoner.
void nyNasjon();					//Oppretter/registrerer en ny nasjon.
void endreNasjon();					//Endrer data i en nasjon.
void skrivHovedNasjon();			//Skriver hoveddata om alle nasjoner.
void skrivDeltagertropp();			//Skriver nasjonens deltagertropp.
void skrivNasjon();					//Skriver alle data om en nasjon. 

//Deltager-funksjoner
void deltagerMeny();				//Skriver delmenyen for deltagere.
void nyDeltager();					//Oppretter ny deltager.
void endreDeltager();				//Endre alle data om en deltager.
void skrivHovedDeltager();			//Skriver hoveddata om alle deltagere.
void skrivDeltager();				//Skriver alle data om en deltager.

//Gren-funksjoner
void grenMeny();					//Skriver delmeny for Grener.
void nyGren();						//Oppretter en ny gren.
void skrivHovedGren();				//Skriver hoveddata for alle grener.
void skrivGren();					//Skriver alle data om en gren.

//Ovelse-funksjoner
void ovelseMeny();					//Skriver undermeny for ovelser.
void nyOvelse();					//Oppretter en ny ovelse.
void endreOvelse();					//Endre alle data for en ovelse.
void fjernOvelse();					//Fjerner en ovelse.
void skrivOvelse();					//Skriver alle data om en ovelse.

	//Deltagerliste-funksjoner
	void deltagerlisteMeny();		//Skriver undermeny for deltagerlister.
	void skrivDeltagerliste();		//Leser lista fra fil dersom den finnes og skriver på skjermen.
	void nyDeltagerliste();			//Dersom listen ikke finnes allerede, leses en ny inn (fra tastatur) og skrives til fil.
	void endreDeltagerliste();		//Om *resultatliste* ikke finnes, tilbys brukeren å endre på deltagerlisten. (Først lest inn, så skrevet til fil etterpå).
	void fjernDeltagerliste();		//Om *resultatliste* ikke finnes, tilbys brukeren å slette hele deltager-/resultatlisten (altså dets fil).

	//Resultatliste-funksjoner
	void resultatlisteMeny();		//Skriver undermeny for resultatlister.
	void skrivResultatliste();		//Om resultatliste finnes, leses inn fra fil, skrives på skjerm.
	void nyResultatliste();			//Om resultatliste ikke finnes, så leses inn fra tastaturet, sorteres, skrives til skjerm, fil, og statistikkene oppdateres.
	void fjernResultatliste();		//Om filen finnes, slettes den. (Husk oppdater stats.)
 
//Andre funksjoner
void skrivMedaljeoversikt();		//Skriver hele medaljeoversikten/-statistikken.
void skrivPoengoversikt();			//Skriver hele poengoversikten/-statistikken.

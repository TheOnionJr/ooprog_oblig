using namespace std;

//Headerfil for globale funksjonsdeklarasjoner.


//Generelle funksjoner.
void skrivMeny();					//Skriver hovedmeny.
char lesKommando();					//Leser inn og upcaser en char.
int les(const char* t, const int min, const int max);	//Leser inn en int innenfor et intervall.
void les(const char t[], char s[], const int LEN);
char* lesPrivat();
void lesFraFiler();					//Leser inn all info som trengs fra filer.
void skrivTilFiler();				//Skriver all data til fil.

//Nasjoner funksjoner.
void nasjonerMeny();				//Skriver undermeny for nasjoner.
void endreNasjonerMeny();

//Deltager-funksjoner
void deltagerMeny();				//Skriver delmenyen for deltagere.

//Gren-funksjoner
void grenMeny();					//Skriver delmeny for Grener.

//Ovelse-funksjoner
void ovelseMeny();					//Skriver undermeny for ovelser.

	//Deltagerliste-funksjoner
	void deltagerlisteMeny();		//Skriver undermeny for deltagerlister.
	
	//Resultatliste-funksjoner
	void resultatlisteMeny();		//Skriver undermeny for resultatlister.

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
};
#endif
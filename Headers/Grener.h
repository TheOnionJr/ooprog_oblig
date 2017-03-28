#if !defined(Grener_h)
#define Grener_h
#include "ListTool2B.h"
class Grener {
private:
	List* grenliste;
public:
	Grener() {
		grenliste = new List(Sorted);					//'Grener' liste, sortert.
	}
};

#endif
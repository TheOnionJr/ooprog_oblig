#if !defined(Deltagere_h)
#define Deltagere_h
#include "ListTool2B.h"
class Deltagere {
private:
	List* deltagerliste;
public:
	Deltagere() {
		deltagerliste = new List(Sorted);
	}
};

#endif
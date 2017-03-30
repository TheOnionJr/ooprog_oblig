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

}

Ovelse::~Ovelse() {

}

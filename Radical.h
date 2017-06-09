#pragma once
#include "Real.h"
#include <string>
using namespace std;

class Radical : public Real{

protected:
	int Coeficiente;
	int Radicando;
	int Indice;

public:
	Radical(int, int, int);
	int getCoeficiente();
	int getRadicando();
	int getIndice();


};
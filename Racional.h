#pragma once
#include "Real.h"
#include <string>
using namespace std;

class Racional : Real{

protected:
	int Numerador;
	int Denominador;

public:
	Racional(int, int);
	int getNumerador();
	int getDenominador();

};

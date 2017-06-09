#pragma once
#include "Real.h"
#include <string>
using namespace std;

class Racional : public Real{

protected:
	int Numerador;
	int Denominador;

public:

	Racional(int, int);
	int getNumerador();
	int getDenominador();
	virtual string Sumar(Real*);
	virtual string SumarIntDou(int, double);
	//virtual int suma();

};

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
	virtual string Sumar(Real*);
	virtual string SumarIntDou(int, double);
	virtual string Restar(Real*);
	virtual string RestarInt(int num);
	virtual string Dividir(Real*);
	virtual string DividirInt(int num);


};
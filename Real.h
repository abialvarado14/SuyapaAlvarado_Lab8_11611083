#pragma once

#include <string>
using namespace std;

class Real{

public:
	Real();
	virtual string Sumar(Real*);
	virtual string SumarIntDou(int, double);
	virtual string Restar(Real*);
	virtual string RestarInt(int);
	virtual string Dividir(Real*);
	virtual string DividirInt(int);


};

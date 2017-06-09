#include "Racional.h"
#include "Radical.h"
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <math.h>

using namespace std;

Racional::Racional( int Numerador,  int Denominador) : Real() {

	this-> Numerador=Numerador;

	while (Denominador == 0){
		cout << "No se puede dividir entre 0..";
		cin >> Denominador;
	}
	this-> Denominador=Denominador;
}


int Racional::getNumerador(){

return Numerador;
}

int Racional::getDenominador(){

return Denominador;
}

string Racional::Sumar(Real* num){
	string tipo, respuesta;
	stringstream convert;
	stringstream ss;
	int numer, denom;
	 tipo=typeid(num).name();

            if (typeid(*num)==typeid(Racional)){
            	Racional* r= reinterpret_cast<Racional*>(num);

           		if (this->Denominador == r->getDenominador()){			
           			numer = this->Numerador + r->getNumerador();
           			convert << numer;
           			ss << r->getDenominador();
           			respuesta = convert.str() + "/" + ss.str();
           		}else{
           			numer = (this->Numerador*r->getDenominador())+(this->Denominador*r->getNumerador());
           			denom = this->getDenominador()*r->getDenominador();
           			convert << numer;
           			ss << denom;
           			respuesta = convert.str() + "/" + ss.str();
           		}
           }else if (typeid(*num)==typeid(Radical)){
           		Radical* rad= reinterpret_cast<Radical*>(num);
           		int num1;
           		num1 = pow(rad->getCoeficiente(), 1/rad->getRadicando())*rad->getIndice();
           		numer = (this->Numerador*1)+(this->Denominador*num1);
           		denom = this->getDenominador()*1;
           		convert << numer;
           		ss << denom;
           		respuesta = convert.str() + "/" + ss.str();
           }

           return respuesta;
                      
      }
string Racional::SumarIntDou(int num, double num1){
	//SOLO SUMA INT O DOUBLE
}


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
	stringstream s2;
	stringstream convert2, convert3, convert4;
	int numer, denom;
	 tipo=typeid(num).name();
	 		//SUMA DE FRACCIONES
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

           	//SUMA CON RADICALES	
           }else if (typeid(*num)==typeid(Radical)){
           		cout << "HOLAAAAAAAAAAAAAAAAAA";
           		Radical* rad= reinterpret_cast<Radical*>(num);
           		int num1, indice, radicando, coeficiente;
           		num1 = this->getNumerador();
           		numer = this->getDenominador()* rad->getCoeficiente();
           		denom = this->getDenominador();
           		indice = rad->getIndice();
           		radicando = rad->getRadicando();
           		convert << numer;//COEFICIENTE
           		ss << denom;//DENOMINADOR
           		s2 << num1;//NUMERADOR, 
           		convert2 << indice;
           		convert3 << radicando;
           		respuesta = "((" + convert.str() + ") " + " (" + convert3.str() + ") " + " ^" + " ( " + "1/" + convert2.str() + " ) " + " + " + s2.str() +") /" + ss.str();
           }

           return respuesta;
                      
      }
string Racional::SumarIntDou(int num, double num1){
	/*int numer, denom;
	stringstream ss;
	stringstream convert;
	string respuesta;

	numer = (this->Numerador*1)+(this->Denominador*num1);
    denom = this->getDenominador()*1;
    convert << numer;
    ss << denom;
    respuesta = convert.str() + "/" + ss.str();	

    return respuesta;*/

}


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
	int numer, denom;
	stringstream ss;
	stringstream convert;
	string respuesta;
	numer = (this->Numerador*1)+(this->Denominador*num);
    denom = this->getDenominador()*1;
    convert << numer;
    ss << denom;
    respuesta = convert.str() + "/" + ss.str();	

    return respuesta;

}

string Racional::Restar(Real* num){
	string tipo, respuesta;
	stringstream convert;
	stringstream ss;
	stringstream s2;
	stringstream convert2, convert3, convert4;
	int numer, denom;
	 		//RESTA DE FRACCIONES
            if (typeid(*num)==typeid(Racional)){
            	Racional* r= reinterpret_cast<Racional*>(num);

           		if (this->Denominador == r->getDenominador()){			
           			numer = this->Numerador - r->getNumerador();
           			convert << numer;
           			ss << r->getDenominador();
           			respuesta = convert.str() + "/" + ss.str();
           		}else{
           			numer = (this->Numerador*r->getDenominador())-(this->Denominador*r->getNumerador());
           			denom = this->getDenominador()*r->getDenominador();
           			convert << numer;
           			ss << denom;
           			respuesta = convert.str() + "/" + ss.str();
           		}
			}else if (typeid(*num)==typeid(Radical)){
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
           		respuesta = "((" + convert.str() + ") " + " (" + convert3.str() + ") " + " ^" + " ( " + "1/" + convert2.str() + " ) " + " - " + s2.str() +") /" + ss.str();
           }
		return respuesta;
}

string Racional::RestarInt(int num){
	int numer, denom;
	stringstream ss;
	stringstream convert;
	string respuesta;
	numer = (this->Numerador*1)-(this->Denominador*num);
    denom = this->getDenominador()*1;
    convert << numer;
    ss << denom;
    respuesta = convert.str() + "/" + ss.str();	

    return respuesta;
}

string Racional::Dividir(Real* num){
	string tipo, respuesta;
	stringstream convert;
	stringstream ss;
	stringstream s2;
	stringstream convert2, convert3, convert4;
	int numer, denom;

	if (typeid(*num)==typeid(Racional)){
         Racional* r= reinterpret_cast<Racional*>(num);

           		numer = this->Numerador * r->getDenominador();
           		convert << numer;
           		ss << r->getNumerador()*this->Denominador;
    	   		respuesta = convert.str() + "/" + ss.str();
           		
			}else if (typeid(*num)==typeid(Radical)){
           		Radical* rad= reinterpret_cast<Radical*>(num);
           		int num1, indice, radicando, coeficiente;
           		num1 = this->getNumerador();
           		numer = this->getNumerador();
           		denom = this->getDenominador()*rad->getCoeficiente();
           		indice = rad->getIndice();
           		radicando = rad->getRadicando();
           		convert << numer;//COEFICIENTE
           		ss << denom;//DENOMINADOR
           		s2 << num1;//NUMERADOR, 
           		convert2 << indice;
           		convert3 << radicando;
           		respuesta = "((" + convert.str() + ")/ " + " (" + convert3.str() + ") " + " ^" + " ( " + "1/" + convert2.str() + " ) " +")(" + ss.str() + ")";
           }
		return respuesta;
}

string Racional::DividirInt(int num){
	int numer, denom;
	stringstream ss;
	stringstream convert;
	string respuesta;
	numer = this->Numerador;
    denom = this->getDenominador()*num;
    convert << numer;
    ss << denom;
    respuesta = convert.str() + "/" + ss.str();	

    return respuesta;
}

string Racional::Multiplicar(Real* num,int digito){
  string tipo, respuesta;
  stringstream convert;
  stringstream ss;
  stringstream s2;
  stringstream convert2, convert3, convert4;
  int numer, denom;   



          if (typeid(*num)==typeid(Racional) && digito != 3){
              Racional* r= reinterpret_cast<Racional*>(num);                 
                numer = this->Numerador * r->getNumerador();
                denom = this->getDenominador() * r->getDenominador();
                convert << numer;
                ss << denom;
                respuesta = convert.str() + "/" + ss.str();
        
            //Multiplicacion CON RADICALES  
           }else if (typeid(*num)==typeid(Radical)){
              Radical* rad= reinterpret_cast<Radical*>(num);
              int num1, indice, radicando, coeficiente;
              num1 = this->getNumerador();
              numer = this->getNumerador() * rad->getCoeficiente();
              denom = this->getDenominador();
              indice = rad->getIndice();
              radicando = rad->getRadicando();
              convert << numer;//COEFICIENTE
              ss << denom;//DENOMINADOR
              s2 << num1;//NUMERADOR, 
              convert2 << indice;
              convert3 << radicando;
              respuesta = "((" + convert.str() + ") " + " (" + convert3.str() + ") " + " ^" + " ( " + "1/" + convert2.str() + " ) " + ") /" + ss.str();
           }else if(digito==3){
              int numero;
              cout << "Ingrese el entero con el que lo desea multiplicar: ";
              cin >> numero;
              numer = this->Numerador * numero;
              denom = this->getDenominador();
              convert << numer;
              ss << denom;
              respuesta = convert.str() + "/" + ss.str();
           }

           return respuesta;
}




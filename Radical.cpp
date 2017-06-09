#include "Radical.h"
#include "Racional.h"
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>


Radical::Radical( int Coeficiente,  int Radicando,  int Indice) : Real(){
	this-> Coeficiente=Coeficiente;
	this-> Radicando=Radicando;
	this-> Indice=Indice;
}


int Radical::getCoeficiente(){

return Coeficiente;
}

int Radical::getRadicando(){

return Radicando;
}

int Radical::getIndice(){

return Indice;
}

string Radical::Sumar(Real* num){
	int coef;
	string respuesta;
	stringstream ss, s1, s2, convert3, convert2, convert;
	if (typeid(*num)==typeid(Radical)){
		Radical* r= reinterpret_cast<Radical*>(num);
		if(this->Radicando == r->getRadicando() && this->Indice==r->getIndice()){
			coef = this->Coeficiente + r->getCoeficiente();
			ss << coef;
			s1 << this->Radicando;
			s2 << this->Indice;
			respuesta = " (" + ss.str() + ")(" + s1.str() + ")^(" + "1/" + s2.str() + ") ";  

		}else{
			cout << "No se puede sumar";
		}
	}else if (typeid(*num)==typeid(Racional)){
		Racional* rac= reinterpret_cast<Racional*>(num);
		int num1, indice, radicando, coeficiente, numer, denom;
           		num1 = rac->getNumerador();
           		numer = rac->getDenominador()* this->getCoeficiente();
           		denom = rac->getDenominador();
           		indice = this->getIndice();
           		radicando = this->getRadicando();
           		convert << numer;//COEFICIENTE
           		ss << denom;//DENOMINADOR
           		s2 << num1;//NUMERADOR, 
           		convert2 << indice;
           		convert3 << radicando;
           		respuesta = "((" + convert.str() + ") " + " (" + convert3.str() + ") " + " ^" + " ( " + "1/" + convert2.str() + " ) " + " + " + s2.str() +") /" + ss.str();
	}
	return respuesta;

}

string Radical::SumarIntDou(int num, double num1){
	stringstream ss;
	stringstream convert;
	stringstream convert2;
	stringstream convert3;
	ss << num;
	convert << this->getCoeficiente();
	convert2 << this->getRadicando();
	convert3 << this->getIndice();

	string respuesta;
	respuesta = "((" + convert.str() + ") " + " (" + convert2.str() + ") " + " ^" + " ( " + "1/" + convert3.str() + " ) " + " + " + ss.str() +") ";

	return respuesta;
	
}

string Radical::Restar(Real* num){
	int coef;
	string respuesta;
	stringstream ss, s1, s2, convert3, convert2, convert;
	if (typeid(*num)==typeid(Radical)){
		Radical* r= reinterpret_cast<Radical*>(num);
		if(this->Radicando == r->getRadicando() && this->Indice==r->getIndice()){
			coef = this->Coeficiente - r->getCoeficiente();
			ss << coef;
			s1 << this->Radicando;
			s2 << this->Indice;
			respuesta = " (" + ss.str() + ")(" + s1.str() + ")^(" + "1/" + s2.str() + ") ";  

		}else{
			cout << "No se puede sumar";
		}

		}else if (typeid(*num)==typeid(Racional)){
		Racional* rac= reinterpret_cast<Racional*>(num);
		int num1, indice, radicando, coeficiente, numer, denom;
           		num1 = rac->getNumerador();
           		numer = rac->getDenominador()* this->getCoeficiente();
           		denom = rac->getDenominador();
           		indice = this->getIndice();
           		radicando = this->getRadicando();
           		convert << numer;//COEFICIENTE
           		ss << denom;//DENOMINADOR
           		s2 << num1;//NUMERADOR, 
           		convert2 << indice;
           		convert3 << radicando;
           		respuesta = "((" + convert.str() + ") " + " (" + convert3.str() + ") " + " ^" + " ( " + "1/" + convert2.str() + " ) " + " - " + s2.str() +") /" + ss.str();
	}
	
	return respuesta;

}

string Radical::RestarInt(int num){
	stringstream ss;
	stringstream convert;
	stringstream convert2;
	stringstream convert3;
	ss << num;
	convert << this->getCoeficiente();
	convert2 << this->getRadicando();
	convert3 << this->getIndice();

	string respuesta;
	respuesta = "((" + convert.str() + ") " + " (" + convert2.str() + ") " + " ^" + " ( " + "1/" + convert3.str() + " ) " + " - " + ss.str() +") ";

	return respuesta;
}

string Radical::Dividir(Real* num){
	int coef;
	string respuesta;
	stringstream ss, s1, s2, convert3, convert2, convert;
	if (typeid(*num)==typeid(Radical)){
		Radical* r= reinterpret_cast<Radical*>(num);
		if (this->Indice==r->getIndice()){
		if(this->Radicando % r->getRadicando() == 0){
			coef = this->Coeficiente;
			ss << coef;
			s1 << this->Radicando/r->getRadicando();
			s2 << this->Indice;
			convert2 << r->getCoeficiente();
			respuesta = " (" + ss.str() +"/"+ convert2.str() + ")(" + s1.str() + ")^(" + "1/" + s2.str() + ") ";  

		}else{
			coef = this->Coeficiente;
			ss << coef;
			s1 << this->Radicando;
			convert3 << r->getRadicando();
			s2 << this->Indice;
			convert2 << r->getCoeficiente();
			respuesta = " (" + ss.str() + ")(" + s1.str() + ")^(" + "1/" + s2.str() + ") /((" + convert2.str() +") (" + convert3.str() + ")^ (1/ " + s2.str() + "))";  			
		}

		}else{
			cout << "Division invalida";
		}
	}

		else if (typeid(*num)==typeid(Racional)){
			Racional* rac= reinterpret_cast<Racional*>(num);
			int num1, indice, radicando, coeficiente, numer, denom;
           	num1 = rac->getNumerador();
           	numer = rac->getDenominador()* this->getCoeficiente();
           	//enom = rac->getDenominador();
           	indice = this->getIndice();
           	radicando = this->getRadicando();
           	convert << numer;//COEFICIENTE
           	ss << denom;//DENOMINADOR
           	s2 << num1;//NUMERADOR, 
           	convert2 << indice;
           	convert3 << radicando;
           	respuesta = "((" + convert.str() + ")/ " + " (" + convert3.str() + ") " + " ^" + " ( " + "1/" + convert2.str() + " ) " +") ";
	}
	
	return respuesta;

	}



string Radical::DividirInt(int num){
	int coef;
	string respuesta;
	stringstream ss, s1, s2, convert3;
	if (this->Coeficiente % num == 0){
		
		coef = this->Coeficiente / num;
		ss << coef;
		s1 << this->Radicando;
		s2 << this->Indice;
		convert3 << num;
		respuesta = " (" + ss.str() + ")(" + s1.str() + ")^(" + "1/" + s2.str() + ") ";  
	}else{
		ss << this->Coeficiente;
		convert3 << num;
		s1 << this->Radicando;
		s2 << this->Indice;
		respuesta = " (" + ss.str() +"/" +convert3.str() + ")(" + s1.str() + ")^(" + "1/" + s2.str() + ") ";  
	}

	return respuesta;

}



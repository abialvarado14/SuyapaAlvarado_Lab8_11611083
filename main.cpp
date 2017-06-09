#include "Real.h"
#include "Radical.h"
#include "Racional.h"
#include <iostream>
#include <string>
#include <vector>

int main (){
	char resp = 's';
	int radicando, coeficiente, indice, numerador, denominador;
	vector <Real*> numeros;

	cout << "------NUMEROS RADICALES Y RACIONALES----\n\n";

	while (resp =='s'){
		int opc;
		cout << "\nIngrese la opción que desea:\n1.Agregar Radical\n2.Agregar Racional\n3.Sumar\n4.Restar\n5.Multiplicar\n6.Dividir\n7.Archivos: ";
		cin >> opc;

		switch(opc){
			case 1:{

				cout << "\nIngrese Radicando: ";
				cin >> radicando;
				cout << "Ingrese Coeficiente: ";
				cin >> coeficiente;
				cout << "Ingrese indice: ";
				cin >> indice;
				Radical* rad = new Radical(coeficiente, radicando, indice);
				numeros.push_back(rad);

				cout << "RADICAL CREADO!!!" << endl;


			break;
			}//FIN CASE 1, AGREGAR RACIONAL

			case 2:{

				cout << "\nIngrese Numerador: ";
				cin >> numerador;
				cout << "\nIngrese Denominador: ";
				cin >> denominador;
				Racional* rac = new Racional(numerador, denominador);
				numeros.push_back(rac);
				Racional* rac2 = new Racional (3,4);
				rac->Sumar(rac2);
				cout << "RACIONAL AGREGADO!!!"<< endl;

			break;
			}//FIN CASE 2, AGREGAR RADICAL

			case 3:{
				int op, op2;

				cout << "Que tipo desea sumar?\n1.Racionales\n2.Radicales" << endl;
				cin >> op;
				if (op==1){
					cout << "Con que lo desea sumar? \n1.Elemento del vector\n2.Entero o Decimal: ";
					cin >> op2;

					if (op2==1){
						
					}//FIN OPERACION CON REALES
				}//FIN RACIONALES

			}

		}//FIN SWITCH



		cout << "El size es: " << numeros.size();
		cout << endl << "Desea continuar en el programa? (s/n): ";
		cin >> resp;
	}//fin while

	return 0;
}
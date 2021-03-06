#include "Real.h"
#include "Radical.h"
#include "Racional.h"
#include <iostream>
#include <string>
#include <vector>

int main (){
	char resp = 's';
	int radicando, coeficiente, indice, numerador, denominador;
	vector <Radical*> Radicales;
	vector <Racional*> Racionales;

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
				Radicales.push_back(rad);

				cout << "RADICAL CREADO!!!" << endl;


			break;
			}//FIN CASE 1, AGREGAR RACIONAL

			case 2:{

				cout << "\nIngrese Numerador: ";
				cin >> numerador;
				cout << "\nIngrese Denominador: ";
				cin >> denominador;
				Racional* rac = new Racional(numerador, denominador);
				Racionales.push_back(rac);
				cout << "RACIONAL AGREGADO!!!"<< endl;

			break;
			}//FIN CASE 2, AGREGAR RADICAL

			case 3:{
				int op, op2, pos1, pos2;
				string respuesta;

				cout << "\nQue tipo desea sumar?\n1.Racionales\n2.Radicales" << endl;
				cin >> op;
	
				if (op==1){
					for (int i = 0; i < Racionales.size(); ++i)
						{
							cout << i << " Numerador: " << Racionales[i]->getNumerador() << " Denominador: " << Racionales[i]->getDenominador() << endl;
						}

					cout << "\nQue posicion desea sumar?: ";
					cin >> pos1;

					cout << "\nCon que lo desea sumar? \n1.Elemento del vector de Radicales\n2.Elemento del vector de Racionales\n3.Entero o Decimal: ";
					cin >> op2;

					if (op2==1){
						for (int i = 0; i < Radicales.size(); ++i)
						{
							cout << "pos: " << i << " Coeficiente: " << Radicales[i]->getCoeficiente() << " Radicando: " << Radicales[i]->getRadicando() << " Indice: " << Radicales[i]->getIndice() << endl;
						}

						cout << "\nEscoja una posicion:";
						cin >> pos2;

						respuesta = Racionales[pos1]->Sumar(Radicales[pos2]);
						cout << "La respuesta es: " << respuesta;



					} else if (op2==2){
						for (int i = 0; i < Racionales.size(); ++i)
						{
							cout << i << " Numerador: " << Racionales[i]->getNumerador() << " Denominador: " << Racionales[i]->getDenominador() << endl;
						}

						cout << "\nEscoja una posicion:";
						cin >> pos2;

						respuesta = Racionales[pos1]->Sumar(Racionales[pos2]);
						cout << "La respuesta es: " << respuesta;
					}else if (op2==3){
						int entero;
						cout << "Ingrese el entero con el que lo desea sumar: ";
						cin >> entero;
						respuesta =  Racionales[pos1]->SumarIntDou(entero, 0.0);
						cout << "La respuesta es: " << respuesta;
						
					}else{
						cout << "OPCION INVALIDA";
					}
					//FIN OPERACION CON REALES
					//FIN RACIONALES
//**************************************SUMA RADICALES***********************************					
				}else if (op==2){
					cout << "------------RADICALES-------\n";
					for (int i = 0; i < Radicales.size(); ++i)
						{
							cout << "pos: " << i << " Coeficiente: " << Radicales[i]->getCoeficiente() << " Radicando: " << Radicales[i]->getRadicando() << " Indice: " << Radicales[i]->getIndice() << endl;
						}

						cout << "\nEscoja una posicion:";
						cin >> pos1;
						cout << "\nCon que lo desea sumar? \n1.Elemento del vector de Radicales\n2.Elemento del vector de Racionales\n3.Entero o Decimal: ";
						cin >> op2;

						if (op2==1){
							for (int i = 0; i < Radicales.size(); ++i)
							{
								cout << "pos: " << i << " Coeficiente: " << Radicales[i]->getCoeficiente() << " Radicando: " << Radicales[i]->getRadicando() << " Indice: " << Radicales[i]->getIndice() << endl;
							}

							cout << "\nEscoja una posicion:";
							cin >> pos2;

							respuesta = Radicales[pos1]->Sumar(Radicales[pos2]);
							cout << "La respuesta es: " << respuesta;



					} else if (op2==2){
						for (int i = 0; i < Racionales.size(); ++i)
						{
							cout << i << " Numerador: " << Racionales[i]->getNumerador() << " Denominador: " << Racionales[i]->getDenominador() << endl;
						}

						cout << "\nEscoja una posicion:";
						cin >> pos2;

						respuesta = Radicales[pos1]->Sumar(Racionales[pos2]);
						cout << "La respuesta es: " << respuesta;					
						
					}else{
						int entero;
						cout << "Ingrese el entero con el que lo desea sumar: ";
						cin >> entero;
						cout << Radicales.size();
						respuesta =  Radicales[pos1]->SumarIntDou(4, 0.0);
						cout << "La respuesta es: " << respuesta;
						
					}//FIN OPERACIÓN CON NUMEROS REALES RADICALES

				}//FIN RADICALES
				
			break;
			}

		}//FIN SWITCH



		cout << endl << "Desea continuar en el programa? (s/n): ";
		cin >> resp;
	}//fin while

	return 0;
}
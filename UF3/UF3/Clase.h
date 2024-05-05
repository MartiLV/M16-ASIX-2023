#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class Lanchas {

private:

	//Declaraci�n de variables
	int velocidad;
	int distancia;
	bool nitro;
	string nombre;

public:

	//Declaraci�n de getters
	int getVelocidad();
	int getDistancia();
	bool getNitro();
	string getNombre();

	//Declaraci�n de setters
	void setVelocidad(int pVel);
	void setDistancia(int pDis);
	void setNitro(bool pNitro);
	void setNombre(string pNom);

	//Constructor principal
	Lanchas(int pVel, int pDis, bool pNitro, string pNom);

	//Constructor Vacio
	Lanchas();

	//Metodos propios
	void printAll();
	void printVelDis();

};
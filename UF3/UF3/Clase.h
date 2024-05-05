#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class Lanchas {

private:

	//Declaración de variables
	int velocidad;
	int distancia;
	bool nitro;
	string nombre;

public:

	//Declaración de getters
	int getVelocidad();
	int getDistancia();
	bool getNitro();
	string getNombre();

	//Declaración de setters
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
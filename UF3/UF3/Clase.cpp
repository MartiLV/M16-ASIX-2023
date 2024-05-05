#pragma once
#include "Clase.h"

//Getters
int Lanchas::getVelocidad()
{
	return velocidad;
}

int Lanchas::getDistancia()
{
	return distancia;
}

bool Lanchas::getNitro()
{
	return nitro;
}

string Lanchas::getNombre()
{
	return nombre;
}

//Setters
void Lanchas::setVelocidad(int pVel)
{
	velocidad = pVel;
}

void Lanchas::setDistancia(int pDis)
{
	distancia = pDis;
}

void Lanchas::setNitro(bool pNitro)
{
	nitro = pNitro;
}

void Lanchas::setNombre(string pNom)
{
	nombre = pNom;
}

//Constructor principal
Lanchas::Lanchas(int pVelocidad, int pDistancia, bool pNitro, string pNombre)
{
	velocidad = pVelocidad;
	distancia = pDistancia;
	nitro = pNitro;
	nombre = pNombre;
}

//Constructor vacío
Lanchas::Lanchas()
{}

//Metodo propio
void Lanchas::printAll()
{
	//Printar todas las variables privadas
	cout << "Velocidad: " << velocidad << ", distancia: " << distancia << ", nitro: ";

	//Comprobar si el Nitro está activo
	if (nitro)
	{
		cout << "Sí ";
	}
	else cout << "No ";
	cout << "Nombre: " << nombre;
}

void Lanchas::printVelDis()
{
	cout << nombre << ": " << "Velocidad: " << velocidad << ", distancia: " << distancia << "\n";
}
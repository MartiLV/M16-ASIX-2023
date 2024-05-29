#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje // Declaraci�n de la clase EnemigoFinal que hereda p�blicamente de la clase Personaje
{
private:
	int megaAttack; // Creamos la variable megaAttack
	int hiperAttack; // Creamos la variable hiperAttack
	
public:

	// Constructor con elementos de la clase padre y propia
	EnemigoFinal(int pHp,
				std::string pName,
				int pAttack,
				int pPosicionX,
				int pPosicionY,
				int pMegaAttack,
				int pHiperAttack);

	EnemigoFinal(); // Constructor por defecto de la clase EnemigoFinal

	// Getters
	int getMegaAttack();
	int getHiperAttack();
	
	// Setters
	void setMegaAttack(int pMegaAttack);
	void setHiperAttack(int pHiperAttack);
	

	// M�todo propio
	void printAllStats(); // M�todo p�blico para imprimir todas las estad�sticas del enemigo final
};
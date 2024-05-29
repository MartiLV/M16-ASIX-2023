#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje // Declaración de la clase EnemigoFinal que hereda públicamente de la clase Personaje
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
	

	// Método propio
	void printAllStats(); // Método público para imprimir todas las estadísticas del enemigo final
};
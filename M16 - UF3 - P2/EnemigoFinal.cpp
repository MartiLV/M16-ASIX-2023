#include "EnemigoFinal.h"

// Conectamos el enemigos con el enemigo final para poder hacer la herencia de clases
// Para hacer la herencia, tomamos los valores ya definidos en la clase Enemigo y añadimos el ataque especial.
// Esto es el constructor de la clase EnemigoFinal
EnemigoFinal::EnemigoFinal(int pHp,
						   std::string pName,
						   int pAttack,
						   int pPosicionX,
						   int pPosicionY,
						   int pMegaAttack,
						   int pHiperAttack) : Personaje(pHp,
														pName,
														pAttack,
														pPosicionX,
														pPosicionY) { megaAttack = pMegaAttack;
																	hiperAttack = pHiperAttack;
																  }
// ARRIBA: Constructor de la clase EnemigoFinal.
// Inicializa los atributos heredados de la clase base Personaje con los valores proporcionados de EnemigoFinal.
// Además, inicializa los atributos específicos de EnemigoFinal (megaAttack y hiperAttack).

EnemigoFinal::EnemigoFinal()
{
}

//Getters y Setters
// Getter para megaAttack
int EnemigoFinal::getMegaAttack() {
	return megaAttack;
}

// Getter para hiperAttack
int EnemigoFinal::getHiperAttack()
{
	return hiperAttack;
}

// Setter para megaAttack
void EnemigoFinal::setMegaAttack(int pMegaAttack)
{
	megaAttack = pMegaAttack;
}

// Setter para hiperAttack
void EnemigoFinal::setHiperAttack(int pHiperAttack)
{
	hiperAttack = pHiperAttack;
}

// Método propio para imprimir todas las estadísticas del enemigo final
void EnemigoFinal::printAllStats() {
	cout << "El nombre del enemigo final es " << getName() << endl;
	cout << "La vida del enemigo final es " << getHp() << endl;
	cout << "El ataque normal del enemigo final es " << getAttack() << endl;
	cout << "La posicion es " << getPosicionX()<<","<<getPosicionY() << endl;
	cout << "El ataque final del enemigo es " << getMegaAttack() << endl;
	}
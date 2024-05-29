#pragma once
#include  <iostream>
class Personaje
{

private:
	int hp;
	std::string name;
	int attack;
	int posicionX;
	int posicionY;

public:
	// Constructores
	Personaje(int pHp, std::string pName, int pAttack, int pPosicionX, int pPosicionY); // Constructor de la clase Personaje que toma par�metros para inicializar los atributos
	Personaje(); // Constructor por defecto de la clase Personaje

	// Getters
	int getHp();

	std::string getName();

	int getAttack();

	int getPosicionX();
	int getPosicionY();

	// Setters
	void setHp(int php);

	void setName(std::string pname);

	void setAttack(int pattack);

	void setPosicionX(int pPosicionX);
	void setPosicionY(int pPosicionY);

	// M�todo Propio
	void printStatus(); // M�todo p�blico para imprimir el estado del personaje

};
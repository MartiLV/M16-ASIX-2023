#include <iostream>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib")

using namespace std;
//Creamos los arrays de las cartas disponibles
int corazon[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //1
int diamante[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //2
int pica[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //3
int trebol[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //4
//Función de cartas que tiene el jugador y cartas que tiene la banca
int cartasJugador;
int cartasBanca;
//Guarda el valor de la carta actual
int numero;
//Decide si el jugador quiere más cartas o menos
char si_no = 's';
//Indica si la carta se ha repartido al jugador
bool miCarta = false;
//Indica si la banca tiene 21 cartas
bool banca21 = false;
//Guarda el palo de la carta actual
string palo_cartas;

//La función numCarta muestra el valor y el palo de la carta
void numCarta(int& reparticionCartas, string& palo_cartas, int& numero, char si_no, int& cartasBanca) {
	//Si el valor de reparticionCartas es menor que 10 sumamos + 1
	if (reparticionCartas < 10 && reparticionCartas > 0)
	{
		numero = reparticionCartas + 1;
		cout << numero << " de " << palo_cartas << "\n";
	}
	//Si es mayor o igual a 10, el valor de la carta es 10 y se muestra una letra para indicar el tipo de figura (J, Q o K)
	else if (reparticionCartas >= 10) {

		numero = 10;
		if (reparticionCartas == 10) {

			cout << "J de " << palo_cartas << "\n";

		}
		else if (reparticionCartas == 11) {

			cout << "Q de " << palo_cartas << "\n";

		}
		else if (reparticionCartas == 12) {

			cout << "K de " << palo_cartas << "\n";

		}

	}
	//Si nos toca un AS, dejamos que el jugador decida qué hacer
	//Si se la queda, decide si es un 1 o un 11
	if (reparticionCartas == 0 && si_no == 's') {

		do {

			cout << "Tu as de " << palo_cartas << " es un 1 o un 11\n";
			cin >> numero;
			reparticionCartas == numero;
			cout << reparticionCartas << " de " << palo_cartas << "\n";

		} while (numero != 1 && numero != 11);

	}
	//Si no la quiere, dependiendo del valor de la carta le asignamos un valor y se la queda la banca
	if (reparticionCartas == 0 && si_no == 'n') {

		if (cartasBanca <= 10) {

			numero = 11;
			reparticionCartas = 11;

		}
		else if (cartasBanca > 10) {

			numero = 1;
			reparticionCartas = 1;

		}
		cout << "El as de " << palo_cartas << "\n";
		cout << reparticionCartas << " de " << palo_cartas << "\n";
	}

}

void repartirCartas(int& numero) {

	int reparticionPalo;
	int reparticionCarta;
	miCarta = false;
	do {

		//Generamos numero aleatorio para el palo y para la carta
		reparticionPalo = rand() % 4 + 1;
		reparticionCarta = rand() % 13;
		if (reparticionPalo == 1 && corazon[reparticionCarta] == 1) {

			corazon[reparticionCarta] = 0;
			miCarta = true;
			palo_cartas = "corazones";

		}
		if (reparticionPalo == 1 && diamante[reparticionCarta] == 1) {

			diamante[reparticionCarta] = 0;
			miCarta = true;
			palo_cartas = "diamantes";

		}
		if (reparticionPalo == 1 && pica[reparticionCarta] == 1) {

			trebol[reparticionCarta] = 0;
			miCarta = true;
			palo_cartas = "picas";
		}
		if (reparticionPalo == 1 && trebol[reparticionCarta] == 1) {

			pica[reparticionCarta] = 0;
			miCarta = true;
			palo_cartas = "trebol";

		}

	} while (miCarta = false);
	numCarta(reparticionCarta, palo_cartas, numero, si_no, cartasBanca);

}

int main() {
	setlocale(LC_ALL, "es_ES.UTF-8");
	srand(time(NULL));

	cout << "Bienvenido a mi BlackJack! :)\n";
	system("pause");
	system("cls");

	//Damos 2 cartas al jugador al inicio
	for (size_t i = 0; i < 2; i++) {

		repartirCartas(numero);
		cartasJugador += numero;


	}
	cout << "Tienes " << cartasJugador << " puntos\n";

	repartirCartas(numero);
	cartasBanca += numero;
	cout << "La banca tiene " << cartasBanca << " puntos\n";
	system("pause");

	do {

		cout << "Tienes " << cartasJugador << " puntos\n";
		cout << "Quieres otra carta?\ns/n\n";
		cin >> si_no;

	} while (si_no != 's' && si_no != 'n');

	while (si_no == 's') {

		repartirCartas(numero);
		cartasJugador += numero;
		if (cartasJugador > 21) {

			si_no = 'n';
			cout << "Tienes " << cartasJugador << " puntos\n";
			system("pause");
			system("cls");

		}
		else if (cartasJugador < 21) {

			do {

				cout << "Tienes " << cartasJugador << " puntos\n";
				cout << "Quieres otra carta?\ns/n\n";
				cin >> si_no;

			} while (si_no != 's' && si_no != 'n');

		}

	}
	system("cls");
	if (cartasJugador <= 21) {

		do {

			repartirCartas(numero);
			cartasBanca += numero;
			cout << "La banca tiene " << cartasBanca << " puntos\n";
			system("pause");

		} while (cartasBanca < cartasJugador && cartasBanca <= 21);

	}
	if (cartasBanca > 21) {

		system("cls");
		cout << "Has ganado!";
		system("pause");
		system("cls");

	}
	else {

		system("cls");
		cout << "Has perdido :(";
		system("pause");
		system("cls");

	}

}
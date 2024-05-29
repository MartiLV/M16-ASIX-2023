#include <iostream>
#include <time.h>
#include "Personaje.h"
#include "EnemigoFinal.h"

// Función para mostrar el tablero.
// Toma como parámetros un array de movimientos y un array bidimensional que representa el mapa.
void mostrarMapa(string moves[3], int mapa[5][5]) {

	// Recorre las filas del mapa
	for (size_t i = 0; i < 5; i++)
	{
		// Recorre las columnas del mapa
		for (size_t j = 0; j < 5; j++)
		{
			// Si el valor en la posición del mapa es 0, 1 o 2, imprime el primer movimiento.
			if (mapa[i][j] == 0 || mapa[i][j] == 2 || mapa[i][j] == 1)
			{
				cout << moves[0];
			}

			// Si el valor en la posición del mapa es 3, imprime el segundo movimiento.
			else if (mapa[i][j] == 3)
			{
				cout << moves[1];
			}

			// En cualquier otro caso, imprime el tercer movimiento.
			else 
			{
				cout << moves[2];
			}
		}
		// Imprime un salto de línea después de cada fila del mapa.
		cout << "\n";
	}
}

int main() {

	// Se utiliza para la generación de números aleatorios.
	srand(time(NULL));
	// Variable para almacenar un número aleatorio.
	int numeroAleatorio;
		
	// Array que representa el mapa del juego.
	int mapa[5][5];

	// Array de strings que contiene los diferentes tipos de movimiento en el tablero.
	// Espacio sin visitar o vacio: "?" espacio del jugador "*" espacio con montruo "!".
	string tiposPosiciones [3] = { " ? "," * "," ! "};

	// Creación de personajes y enemigos con sus respectivos Stats (HP, Nombre, Ataque, PosiciónX, PosiciónY y megaAttack e hyperAttack en el caso de bossFinal)
	Personaje heroe(1500,"Marti",150,4,0);
	Personaje enemigo1(150,"enemigo1",50,1,0);
	Personaje enemigo2(150,"enemigo2",30,2,0);
	Personaje enemigo3(160,"enemigo3",20,3,0);
	Personaje enemigo4(305,"enemigo4",15,4,0);
	EnemigoFinal boss(1000, "bossFinal", 150, 0, 0,300,400);

	// Los espacios vacíos son 0, los enemigos son 1 y el boss es 2
	// Primero rellenamos la array con todo 0 para luego añadir los enemigos
	// Al finalizar estos bucles anidados, todo el array mapa estará inicializada con ceros, lo que significa que
	// todas las posiciones del mapa estarán vacías y listas para ser ocupadas por personajes o enemigos.

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			mapa[i][j] = 0;
			
		}
	}

	// Colocamos un enemigo en cada fila, en una columna aleatoria
	
	// Enemigo 1
		numeroAleatorio = rand() % 5;
		mapa[1][numeroAleatorio] = 1;
		enemigo1.setPosicionY(numeroAleatorio);
	// Enemigo 2
		numeroAleatorio = rand() % 5;
		mapa[2][numeroAleatorio] = 1;
		enemigo2.setPosicionY(numeroAleatorio);
	// Enemigo 3
		numeroAleatorio = rand() % 5;
		mapa[3][numeroAleatorio] = 1;
		enemigo3.setPosicionY(numeroAleatorio);
	// Enemigo 4
		numeroAleatorio = rand() % 5;
		mapa[4][numeroAleatorio] = 1;
		enemigo4.setPosicionY(numeroAleatorio);
	
	// Para finalizar ponemos el jefe en la fila 5 que en la array es la 0
		numeroAleatorio = rand() % 5;
		mapa[0][numeroAleatorio] = 2;
		boss.setPosicionY(numeroAleatorio);
	
	// Colocamos al héroe en la primera fila, que es la última en el array usaremos el 3 como posicion inicial.
	do
	{
		if (true)
		{
			numeroAleatorio = rand() % 5;
			if (mapa[4][numeroAleatorio] ==0)
			{
				mapa[4][numeroAleatorio] = 3;
				heroe.setPosicionY(numeroAleatorio);
			}
		}
	} while (mapa[4][numeroAleatorio] !=3);
	
	bool finJuego = false;

	while (!finJuego)
	{

		for (size_t i = 0; i < 5; i++)
		{
			cout << "\n";
		}

		// Llamamos a la función para mostrar el tablero
		mostrarMapa(tiposPosiciones, mapa);
		cout << "Muevete con WASD\n";
		char letra;
		cin >>  letra;
		int x = heroe.getPosicionX();
		int y = heroe.getPosicionY();
		
		int anteriorX = x;
		int anteriorY = y;

		// Realiza el movimiento del jugador.
		if (letra == 's' && x !=4 )
		{
			x += 1;
		}
		else if (letra == 'w' && x!=0  )
		{
			x -= 1;
		}
		else if (letra == 'd'  && y !=4 )
		{
			y += 1;
		}
		else if (letra == 'a' && y!=0  )
		{
			y -= 1;
		}
		else
		{
			cout << "Movimiento incorrecto";
		}
		
		// Comprueba si hay algún enemigo en la casilla seleccionada.
		if (mapa[x][y]==0)
		{
			mapa[x][y] = 3;
			mapa[anteriorX][anteriorY] = 0;
		
		}
		else if (mapa[x][y] == 1 || mapa[x][y] == 2)
		{
			// Si hay un jefe final en la casilla, el juego termina.
			if (mapa[x][y] == 2) {
				finJuego = true;
			}
			mapa[x][y] = 4;
			mapa[anteriorX][anteriorY] = 0;
		}
				
		heroe.setPosicionX(x);
		heroe.setPosicionY(y);
		system("cls");
	}
}
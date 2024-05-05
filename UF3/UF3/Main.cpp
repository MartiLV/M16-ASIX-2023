#include "Clase.h"

//Todas las librerías están en la clase

using namespace std;

//Declaracion de variables del juego Main
int velocidad;
int distancia;
bool nitro;
string nombre;

int main()
{
	//Inicio juego 
	cout << "Estás en una competición entre dos lanchas. Vas a tirar un dado, que sumará puntos a tu velocidad. \n";

	//Nombre del primer jugador
	cout << "Introduce el nombre del primer jugador: \n";
	cin >> nombre;

	Lanchas lancha1(0, 0, true, nombre);

	//Nombre del segundo jugador
	cout << "Introduce el nombre de tu rival: \n";
	cin >> nombre;

	Lanchas lancha2(0, 0, true, nombre);

	//Iniciamos los 5 turnos
	for (int i = 0; i < 5; i++)
	{
		//Inicializacion random
		srand(time(NULL));

		//Condicional para saber si quiere usar nitro
		if (lancha1.getNitro() == true) {
			string nitro = "";

			//Preguntar si quiere el nitro en esta ronda
			while (nitro != "si" && nitro != "no")
			{
				cout << "Quieres usar el Nitro? (si/no) Recuerda: Solo puedes usarlo una vez!\n";
				cin >> nitro;

				if (nitro == "si")
				{

					//Declaramos setNitro como false, porque ya lo hemos usado
					lancha1.setNitro(false);

					//50% De probabilidad de acertar el Nitro
					int probabilidadNitro = rand() % 2;

					//Si la probabilidad sale 0, la velocidad se duplica y si sale 1 se divide por la mitad
					if (probabilidadNitro == 0)
					{
						cout << "¡Has usado y ganado el Nitro! Tu velocidad se ha multiplicado por dos :D\n";
						lancha1.setVelocidad(lancha1.getVelocidad() * 2);
					}
					else
					{
						cout << "¡Has perdido el Nitro! Tu velocidad se ha dividido a la mitad :(\n";
						lancha1.setVelocidad(lancha1.getVelocidad() / 2);
					}
				}

			}
		}

		//Con esto generamos un numero aleatorio entre 1 y 6 para un barco i el otro
		int dado1 = rand() % 6 + 1;
		int dado2 = rand() % 6 + 1;

		cout << "Pulsa enter para tirar el dado\n";
		system("pause");

		//Mostrar tu número, y el del rival
		cout << "Has sacado " << dado1 << " puntos," << " tu rival ha sacado " << dado2 << " puntos\n";

		system("pause");

		//Ajustamos velocidad
		lancha1.setVelocidad(dado1 + lancha1.getVelocidad());
		lancha2.setVelocidad(dado2 + lancha1.getVelocidad());

		//Ajustamos distancia
		lancha1.setDistancia(lancha1.getDistancia() + lancha1.getVelocidad()*100);
		lancha2.setDistancia(lancha2.getDistancia() + lancha2.getVelocidad()*100);

		//Printar estado
		lancha1.printVelDis();
		lancha2.printVelDis();
	}

	if (lancha1.getDistancia() < lancha2.getDistancia())
	{
		cout << "Has perdido :(\n";
	}
	else if (lancha1.getDistancia() > lancha2.getDistancia()) {
		cout << "Has ganado!\n";
	}
	else
	{
		cout << "Has empatado con tu rival!\n";
	}
}
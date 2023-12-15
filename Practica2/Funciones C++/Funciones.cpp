#include <iostream>
#include <time.h>
#include <locale.h>
#include<stdlib.h>
#include<windows.h>
#pragma comment(lib, "winmm.lib")

using namespace std;
// Character

int attackNumber;

int characterAttackSoplido;

int characterAttackPunetazo;

int characterAttackBastonazo;

int characterHP = 300;

// Boss 1
string boss1Name = "Gatito";

int boss1Attack;

int boss1HP = 250;

// Boss 2
string boss2Name = "Jefazo";

int boss2Attack;

int boss2HP = 250;

// Other

int bossNumber;

int ataqueUnico = 3;

//Booleano Jefe Válido
bool jefeValido = false;

// Booleano Ataque Válido
bool ataqueValido = false;

// Booleano Heroe Vivo
bool heroeVivo = true;

void introduccion() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	using namespace std;

	string characterName;

	cout << "Introduce el nombre de tu personaje: \n";

	cin >> characterName;

	system("cls");
}

void jefe1Ataque() {

	if (boss1HP > 0 && bossNumber == 1 && heroeVivo)
	{
		characterHP = characterHP - boss1Attack;

		if (characterHP < 0)
		{
			characterHP = 0;
			heroeVivo = false;
		}

		cout << boss1Name << " te acaba de zurrar, te ha quitado " << boss1Attack << " de vida y te queda " << characterHP << " de vida \n";
		system("pause");
		system("cls");
	}
}

void jefe2Ataque() {

	if (boss2HP > 0 && bossNumber == 2 && heroeVivo)
	{
		characterHP = characterHP - boss2Attack;

		if (characterHP < 0)
		{
			characterHP = 0;
			heroeVivo = false;
		}

		cout << boss2Name << " te acaba de zurrar, te ha quitado " << boss2Attack << " de vida y te queda " << characterHP << " de vida \n";
		system("pause");
		system("cls");
	}
}

void attackSelect() {
	do
	{

		cout << "Escoge un ataque:\n" << "1" << " : Soplido\n" << "2" << " : Bastonazo (te quedan " << ataqueUnico << " ataques de este tipo disponibles!\n" << "3" << " : Puñetazo\n";

		cin >> attackNumber;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}

		switch (attackNumber)
		{
		case 1:
		case 2:
		case 3:
			ataqueValido = true;
			break;
		default:
			ataqueValido = false;
			cout << "Has introducido un número de ataque incorrecto. Por favor, elige entre las opciones 1, 2 y 3\n";
			break;
		}
	} while (ataqueValido == false);

	system("cls");
}

int jefeSelect(int number) {

	do
	{
		cout << "Elige el jefe al que quieres atacar\n";

		cout << "1" << ": " << boss1Name << "\n" << "2" << ": " << boss2Name << "\n";

		cin >> number;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}

		switch (number)
		{
		case 1:
		case 2:
			jefeValido = true;
			break;
		default:
			jefeValido = false;
			cout << "Has introducido un número de jefe incorrecto. Por favor, elige entre las opciones 1 y 2\n";
			break;
		}
	} while (jefeValido == false);

	system("cls");
	return number;

}

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	PlaySound(TEXT("musica.wav"), NULL, SND_FILENAME);

	introduccion();
	system("cls");

	while ((boss1HP > 0 || boss2HP > 0) && characterHP > 0) {

		characterAttackSoplido = rand() % 80;

		characterAttackBastonazo = rand() % 150;

		characterAttackPunetazo = rand() % 50;

		boss1Attack = rand() % 6 + 20;

		boss2Attack = rand() % 16 + 40;

		cout << "Vida de Gatito: " << boss1HP << "\n";
		cout << "Vida de Jefazo: " << boss2HP << "\n";
		cout << "Tu vida: " << characterHP << "\n\n";

		bossNumber = jefeSelect(1 || 2);

		if (bossNumber == 1)

		{
			attackSelect();

			if (attackNumber == 1)

			{
				boss1HP = boss1HP - characterAttackSoplido;

				if (boss1HP < 0)
				{
					boss1HP = 0;
				}

				cout << "Has zurrado a " << boss1Name << ", y ha recibido un golpe de " << characterAttackSoplido << ". Le quedan " << boss1HP << " de vida\n";

				system("pause");
				system("cls");

			}

			if (attackNumber == 2 && ataqueUnico > 0)
			{
				boss1HP = boss1HP - characterAttackBastonazo;

				if (boss1HP < 0)
				{
					boss1HP = 0;
				}

				cout << "Has zurrado a " << boss1Name << ", y ha recibido un golpe de " << characterAttackBastonazo << ". Le quedan " << boss1HP << " de vida\n";
				ataqueUnico = ataqueUnico - 1;
				cout << "Te quedan " << ataqueUnico << " ataques de este tipo, cuidado!\n";

				system("pause");
				system("cls");
			}
			if (ataqueUnico == 0)
			{
				cout << "Recuerda! Ya no te quedan ataques de tipo 2 disponibles!\n";
				system("pause");
				system("cls");
			}
			if (attackNumber == 3)

			{
				boss1HP = boss1HP - characterAttackPunetazo;

				if (boss1HP < 0)
				{
					boss1HP = 0;
				}

				cout << "Has zurrado a " << boss1Name << ", y ha recibido un golpe de " << characterAttackPunetazo << ". Le quedan " << boss1HP << " de vida\n";

				system("pause");
				system("cls");
			}
			jefe1Ataque();
			jefe2Ataque();
		}
		else if (bossNumber == 2)
		{

			attackSelect();

			if (attackNumber == 1)

			{
				boss2HP = boss2HP - characterAttackSoplido;

				if (boss2HP < 0)
				{
					boss2HP = 0;
				}

				cout << "Has zurrado a " << boss2Name << ", y ha recibido un golpe de " << characterAttackSoplido << ". Le quedan " << boss2HP << " de vida\n";

				system("pause");
				system("cls");

			}

			if (attackNumber == 2 && ataqueUnico > 0)
			{
				boss2HP = boss2HP - characterAttackBastonazo;

				if (boss2HP < 0)
				{
					boss2HP = 0;
				}

				cout << "Has zurrado a " << boss2Name << ", y ha recibido un golpe de " << characterAttackBastonazo << ". Le quedan " << boss2HP << " de vida\n";
				ataqueUnico = ataqueUnico - 1;
				cout << "Te quedan " << ataqueUnico << " ataques de este tipo, cuidado!\n";

				system("pause");
				system("cls");
			}
			if (ataqueUnico == 0)
			{
				cout << "Recuerda! Ya no te quedan ataques de tipo 2 disponibles!\n";
				system("pause");
				system("cls");
			}
			if (attackNumber == 3)

			{
				boss2HP = boss2HP - characterAttackPunetazo;

				if (boss2HP < 0)
				{
					boss2HP = 0;
				}

				cout << "Has zurrado a " << boss2Name << ", y ha recibido un golpe de " << characterAttackPunetazo << ". Le quedan " << boss2HP << " de vida\n";

				system("pause");
				system("cls");
			}
			jefe1Ataque();
			jefe2Ataque();

		}
	}
	if (heroeVivo)
	{
		cout << "Has derrotado a los dos jefes y eres el mejor!!\n";
	}

	else if (boss1HP > 0 || boss2HP > 0)
	{
		cout << "Te han dejado frito :(, has perdido!\n";
	}
}
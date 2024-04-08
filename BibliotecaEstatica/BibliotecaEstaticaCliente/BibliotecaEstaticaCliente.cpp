#include <iostream>
#include <string>
#include <unordered_map>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");

    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> inventario;

    mostrarMenu();

    int opcion = obtenerOpcion();
    while (opcion != 4) {
        if (opcion == 1) {
            agregarObjeto(inventario);
        }
        if (opcion == 2) {
            eliminarObjeto(inventario);
        }
        else if (opcion == 3) {
            mostrarInventario(inventario);
        }

        mostrarMenu();
        opcion = obtenerOpcion();
    }

    return 0;
}
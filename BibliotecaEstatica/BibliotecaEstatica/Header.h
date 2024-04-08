#include <iostream>
#include <string>
#include <unordered_map>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

void mostrarMenu() {
    std::cout << "1. Agregar un objeto al inventario" << std::endl;
    std::cout << "2. Eliminar un objeto del inventario" << std::endl;
    std::cout << "3. Mostrar el inventario" << std::endl;
    std::cout << "4. Terminar programa" << std::endl;
}

int obtenerOpcion() {
    int opcion;
    std::cout << "Introduce tu opción (1, 2, 3 y 4): ";
    std::cin >> opcion;
    return opcion;
}

void agregarObjeto(std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& inventario) {
    std::string nombreObjeto;
    int cantidadObjeto;
    std::string categoriaObjeto;

    std::cout << "Introduce el nombre del objeto: ";
    std::cin >> nombreObjeto;
    std::cout << "Introduce la cantidad del objeto: ";
    std::cin >> cantidadObjeto;
    std::cout << "Introduce la categoría del objeto: ";
    std::cin >> categoriaObjeto;

    std::unordered_map<std::string, std::string> objeto = { {"nombre", nombreObjeto}, {"cantidad", std::to_string(cantidadObjeto)}, {"categoría", categoriaObjeto} };
    inventario.insert({ nombreObjeto, objeto });

    std::cout << "El objeto " << nombreObjeto << " ha sido agregado al inventario." << std::endl;
}

void eliminarObjeto(std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& inventario) {
    std::string nombreObjeto;
    std::cout << "Introduce el nombre del objeto: ";
    std::cin >> nombreObjeto;

    inventario.erase(nombreObjeto);

    std::cout << "El objeto " << nombreObjeto << " ha sido eliminado del inventario." << std::endl;
    std::cout << "Tu inventario es: ";
    for (const auto& item : inventario) {
        std::cout << item.first << ": ";
        for (const auto& subitem : item.second) {
            std::cout << subitem.first << " - " << subitem.second << ", ";
        }
        std::cout << std::endl;
    }
}

void mostrarInventario(const std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& inventario) {
    std::cout << "Tu inventario es: ";
    for (const auto& item : inventario) {
        std::cout << item.first << ": ";
        for (const auto& subitem : item.second) {
            std::cout << subitem.first << " - " << subitem.second << std::endl;
        }
    }
}
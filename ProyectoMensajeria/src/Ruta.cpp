#include "Ruta.h"
#include <iostream>

Ruta::Ruta() : cabeza(nullptr), tamano(0) {}

Ruta::~Ruta() {
    Ciudad* actual = cabeza;
    while (actual) {
        Ciudad* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void Ruta::agregarCiudad(const std::string& nombre, const std::string& codigo) {
    Ciudad* nueva = new Ciudad(nombre, codigo);
    if (!cabeza) {
        cabeza = nueva;
    } else {
        Ciudad* actual = cabeza;
        while (actual->siguiente) actual = actual->siguiente;
        actual->siguiente = nueva;
    }
    tamano++;
    std::cout << "  [+] Ciudad '" << nombre << "' (" << codigo << ") agregada a la ruta.\n";
}

bool Ruta::eliminarPorNombre(const std::string& nombre) {
    if (!cabeza) return false;
    if (cabeza->nombre == nombre) {
        Ciudad* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        tamano--;
        std::cout << "  [-] Ciudad '" << nombre << "' eliminada.\n";
        return true;
    }
    Ciudad* actual = cabeza;
    while (actual->siguiente && actual->siguiente->nombre != nombre)
        actual = actual->siguiente;
    if (!actual->siguiente) return false;
    Ciudad* temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    delete temp;
    tamano--;
    std::cout << "  [-] Ciudad '" << nombre << "' eliminada.\n";
    return true;
}

bool Ruta::eliminarPorPosicion(int posicion) {
    if (posicion < 0 || posicion >= tamano) return false;
    if (posicion == 0) {
        Ciudad* temp = cabeza;
        cabeza = cabeza->siguiente;
        std::cout << "  [-] Ciudad '" << temp->nombre << "' eliminada (pos " << posicion << ").\n";
        delete temp;
        tamano--;
        return true;
    }
    Ciudad* actual = cabeza;
    for (int i = 0; i < posicion - 1; i++) actual = actual->siguiente;
    Ciudad* temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    std::cout << "  [-] Ciudad '" << temp->nombre << "' eliminada (pos " << posicion << ").\n";
    delete temp;
    tamano--;
    return true;
}

void Ruta::mostrarRuta() const {
    if (!cabeza) {
        std::cout << "  La ruta está vacía.\n";
        return;
    }
    std::cout << "  Ruta (" << tamano << " ciudades): ";
    Ciudad* actual = cabeza;
    while (actual) {
        std::cout << actual->nombre << " [" << actual->codigo << "]";
        if (actual->siguiente) std::cout << " --> ";
        actual = actual->siguiente;
    }
    std::cout << "\n";
}

int Ruta::getTamano() const { return tamano; }
Ciudad* Ruta::getCabeza() const { return cabeza; }
bool Ruta::estaVacia() const { return cabeza == nullptr; }

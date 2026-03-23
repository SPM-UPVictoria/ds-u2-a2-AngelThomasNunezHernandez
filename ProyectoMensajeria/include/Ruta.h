#pragma once
#include "Ciudad.h"
#include <string>

class Ruta {
private:
    Ciudad* cabeza;
    int tamano;

public:
    Ruta();
    ~Ruta();

    void agregarCiudad(const std::string& nombre, const std::string& codigo);
    bool eliminarPorNombre(const std::string& nombre);
    bool eliminarPorPosicion(int posicion);
    void mostrarRuta() const;
    int getTamano() const;
    Ciudad* getCabeza() const;
    bool estaVacia() const;
};

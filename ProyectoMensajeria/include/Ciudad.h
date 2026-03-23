#pragma once
#include <string>

class Ciudad {
public:
    std::string nombre;
    std::string codigo;
    Ciudad* siguiente;

    Ciudad(const std::string& nombre, const std::string& codigo);
};

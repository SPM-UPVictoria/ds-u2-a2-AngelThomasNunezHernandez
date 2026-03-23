#include "Ciudad.h"

Ciudad::Ciudad(const std::string& nombre, const std::string& codigo)
    : nombre(nombre), codigo(codigo), siguiente(nullptr) {}

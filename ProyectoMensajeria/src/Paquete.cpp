#include "Paquete.h"

Paquete::Paquete(int id, const std::string& descripcion, const std::string& destino, bool urgente)
    : id(id), descripcion(descripcion), destino(destino), urgente(urgente), siguiente(nullptr) {}

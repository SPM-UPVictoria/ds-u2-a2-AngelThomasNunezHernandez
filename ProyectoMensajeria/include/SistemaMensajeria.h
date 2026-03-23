#pragma once
#include "GestorRutas.h"
#include "GestorPaquetes.h"

class SistemaMensajeria {
private:
    GestorRutas gestorRutas;
    GestorPaquetes gestorPaquetes;

    void menuRutas();
    void menuPaquetes();
    void menuMatrices();
    void menuSimulacion();
    void mostrarResumen() const;

public:
    SistemaMensajeria();
    void inicializarDatosEjemplo();
    void ejecutar();
};

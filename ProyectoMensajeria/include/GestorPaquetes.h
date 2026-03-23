#pragma once
#include "Paquete.h"
#include <string>
#include <vector>

// Cola simple (FIFO) para paquetes pendientes
class ColaPaquetes {
private:
    Paquete* frente;
    Paquete* fin;
    int tamano;
public:
    ColaPaquetes();
    ~ColaPaquetes();
    void encolar(int id, const std::string& desc, const std::string& destino);
    Paquete* desencolar();
    void mostrar() const;
    bool estaVacia() const;
    int getTamano() const;
};

// Pila (LIFO) para paquetes urgentes
class PilaPaquetes {
private:
    Paquete* tope;
    int tamano;
public:
    PilaPaquetes();
    ~PilaPaquetes();
    void apilar(int id, const std::string& desc, const std::string& destino);
    Paquete* desapilar();
    void mostrar() const;
    bool estaVacia() const;
    int getTamano() const;
};

// Cola circular para puntos de control del camión
class ColaCircular {
private:
    std::vector<std::string> puntos;
    int capacidad;
    int inicio;
    int fin;
    int tamano;
public:
    ColaCircular(int capacidad = 10);
    bool agregar(const std::string& punto);
    std::string avanzar();
    std::string actual() const;
    void mostrar() const;
    bool estaVacia() const;
    bool estaLlena() const;
    int getTamano() const;
};

class GestorPaquetes {
private:
    ColaPaquetes colaPendientes;
    PilaPaquetes pilaUrgentes;
    ColaCircular colaCircular;
    int contadorId;

public:
    GestorPaquetes();

    // Cola pendientes
    void agregarPendiente(const std::string& desc, const std::string& destino);
    void procesarPendiente();
    void mostrarPendientes() const;

    // Pila urgentes
    void agregarUrgente(const std::string& desc, const std::string& destino);
    void procesarUrgente();
    void mostrarUrgentes() const;

    // Cola circular
    void cargarPuntoControl(const std::string& punto);
    void simularDesplazamiento();
    void mostrarPosicion() const;
    void mostrarColaCircular() const;
};

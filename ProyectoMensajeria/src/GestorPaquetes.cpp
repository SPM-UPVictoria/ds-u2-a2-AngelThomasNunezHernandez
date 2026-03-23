#include "GestorPaquetes.h"
#include <iostream>

//  ColaPaquetes 
ColaPaquetes::ColaPaquetes() : frente(nullptr), fin(nullptr), tamano(0) {}

ColaPaquetes::~ColaPaquetes() {
    while (frente) {
        Paquete* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }
}

void ColaPaquetes::encolar(int id, const std::string& desc, const std::string& destino) {
    Paquete* nuevo = new Paquete(id, desc, destino, false);
    if (!fin) { frente = fin = nuevo; }
    else { fin->siguiente = nuevo; fin = nuevo; }
    tamano++;
}

Paquete* ColaPaquetes::desencolar() {
    if (!frente) return nullptr;
    Paquete* temp = frente;
    frente = frente->siguiente;
    if (!frente) fin = nullptr;
    temp->siguiente = nullptr;
    tamano--;
    return temp;
}

void ColaPaquetes::mostrar() const {
    if (!frente) { std::cout << "  Cola vacía.\n"; return; }
    Paquete* actual = frente;
    int i = 1;
    while (actual) {
        std::cout << "  [" << i++ << "] ID:" << actual->id
                  << " | " << actual->descripcion
                  << " --> " << actual->destino << "\n";
        actual = actual->siguiente;
    }
}

bool ColaPaquetes::estaVacia() const { return frente == nullptr; }
int ColaPaquetes::getTamano() const { return tamano; }

// PilaPaquetes 
PilaPaquetes::PilaPaquetes() : tope(nullptr), tamano(0) {}

PilaPaquetes::~PilaPaquetes() {
    while (tope) {
        Paquete* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
}

void PilaPaquetes::apilar(int id, const std::string& desc, const std::string& destino) {
    Paquete* nuevo = new Paquete(id, desc, destino, true);
    nuevo->siguiente = tope;
    tope = nuevo;
    tamano++;
}

Paquete* PilaPaquetes::desapilar() {
    if (!tope) return nullptr;
    Paquete* temp = tope;
    tope = tope->siguiente;
    temp->siguiente = nullptr;
    tamano--;
    return temp;
}

void PilaPaquetes::mostrar() const {
    if (!tope) { std::cout << "  Pila vacía.\n"; return; }
    Paquete* actual = tope;
    int i = 1;
    std::cout << "  [TOPE]\n";
    while (actual) {
        std::cout << "  [" << i++ << "] ID:" << actual->id
                  << " | " << actual->descripcion
                  << " --> " << actual->destino << " [URGENTE]\n";
        actual = actual->siguiente;
    }
}

bool PilaPaquetes::estaVacia() const { return tope == nullptr; }
int PilaPaquetes::getTamano() const { return tamano; }

//  ColaCircular
ColaCircular::ColaCircular(int cap)
    : capacidad(cap), inicio(0), fin(0), tamano(0) {
    puntos.resize(cap);
}

bool ColaCircular::agregar(const std::string& punto) {
    if (estaLlena()) return false;
    puntos[fin] = punto;
    fin = (fin + 1) % capacidad;
    tamano++;
    return true;
}

std::string ColaCircular::avanzar() {
    if (estaVacia()) return "";
    std::string actual = puntos[inicio];
    inicio = (inicio + 1) % capacidad;
    // Re-insertar al final para ciclo continuo
    puntos[fin] = actual;
    fin = (fin + 1) % capacidad;
    return actual;
}

std::string ColaCircular::actual() const {
    if (estaVacia()) return "Sin puntos";
    return puntos[inicio];
}

void ColaCircular::mostrar() const {
    if (estaVacia()) { std::cout << "  Cola circular vacía.\n"; return; }
    std::cout << "  Puntos de control (" << tamano << "): ";
    for (int i = 0; i < tamano; i++) {
        int idx = (inicio + i) % capacidad;
        if (i == 0) std::cout << "[ACTUAL] ";
        std::cout << puntos[idx];
        if (i < tamano - 1) std::cout << " -> ";
    }
    std::cout << " -> (regresa al inicio)\n";
}

bool ColaCircular::estaVacia() const { return tamano == 0; }
bool ColaCircular::estaLlena() const { return tamano == capacidad; }
int ColaCircular::getTamano() const { return tamano; }

// GestorPaquetes
GestorPaquetes::GestorPaquetes() : contadorId(1), colaCircular(10) {}

void GestorPaquetes::agregarPendiente(const std::string& desc, const std::string& destino) {
    colaPendientes.encolar(contadorId++, desc, destino);
    std::cout << "  [+] Paquete pendiente agregado (ID " << contadorId - 1 << ").\n";
}

void GestorPaquetes::procesarPendiente() {
    if (colaPendientes.estaVacia()) {
        std::cout << "  No hay paquetes pendientes.\n"; return;
    }
    Paquete* p = colaPendientes.desencolar();
    std::cout << "  [>>] Procesando paquete ID:" << p->id
              << " | " << p->descripcion << " --> " << p->destino << "\n";
    delete p;
}

void GestorPaquetes::mostrarPendientes() const {
    std::cout << "  === Cola de Paquetes Pendientes ===\n";
    colaPendientes.mostrar();
}

void GestorPaquetes::agregarUrgente(const std::string& desc, const std::string& destino) {
    pilaUrgentes.apilar(contadorId++, desc, destino);
    std::cout << "  [!] Paquete urgente agregado (ID " << contadorId - 1 << ").\n";
}

void GestorPaquetes::procesarUrgente() {
    if (pilaUrgentes.estaVacia()) {
        std::cout << "  No hay paquetes urgentes.\n"; return;
    }
    Paquete* p = pilaUrgentes.desapilar();
    std::cout << "  [>>] Procesando URGENTE ID:" << p->id
              << " | " << p->descripcion << " --> " << p->destino << "\n";
    delete p;
}

void GestorPaquetes::mostrarUrgentes() const {
    std::cout << "  === Pila de Paquetes Urgentes ===\n";
    pilaUrgentes.mostrar();
}

void GestorPaquetes::cargarPuntoControl(const std::string& punto) {
    if (colaCircular.agregar(punto))
        std::cout << "  [+] Punto de control '" << punto << "' cargado.\n";
    else
        std::cout << "  Cola circular llena.\n";
}

void GestorPaquetes::simularDesplazamiento() {
    if (colaCircular.estaVacia()) {
        std::cout << "  Sin puntos de control cargados.\n"; return;
    }
    std::string pos = colaCircular.avanzar();
    std::cout << "  [>>] Camion avanzó. Posición anterior: " << pos << "\n";
    std::cout << "  [>>] Posición actual: " << colaCircular.actual() << "\n";
}

void GestorPaquetes::mostrarPosicion() const {
    std::cout << "  Posición actual del camión: " << colaCircular.actual() << "\n";
}

void GestorPaquetes::mostrarColaCircular() const {
    std::cout << "  === Cola Circular (Puntos de Control) ===\n";
    colaCircular.mostrar();
}

#include "SistemaMensajeria.h"
#include <iostream>
#include <limits>

static void pausar() {
    std::cout << "\n  Presione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

static void limpiar() {
    std::cout << "\n" << std::string(55, '=') << "\n";
}

SistemaMensajeria::SistemaMensajeria() {}

void SistemaMensajeria::inicializarDatosEjemplo() {
    std::cout << "\n  Cargando datos de ejemplo...\n";
    gestorRutas.agregarCiudad("Cd. Victoria", "CDVIC");
    gestorRutas.agregarCiudad("Monterrey",    "MTY");
    gestorRutas.agregarCiudad("Saltillo",     "SLT");
    gestorRutas.agregarCiudad("Torreon",      "TRC");

    gestorPaquetes.agregarPendiente("Electrodomésticos", "Monterrey");
    gestorPaquetes.agregarPendiente("Ropa deportiva",    "Saltillo");
    gestorPaquetes.agregarUrgente("Medicamentos",        "Cd. Victoria");

    gestorPaquetes.cargarPuntoControl("Base Central");
    gestorPaquetes.cargarPuntoControl("Cd. Victoria");
    gestorPaquetes.cargarPuntoControl("Linares");
    gestorPaquetes.cargarPuntoControl("Monterrey");
    gestorPaquetes.cargarPuntoControl("Saltillo");

    gestorRutas.inicializarDistanciasEjemplo();
    gestorRutas.inicializarTiemposEjemplo();
    gestorRutas.inicializarDispersaEjemplo();
    std::cout << "  Datos cargados correctamente.\n";
}

void SistemaMensajeria::menuRutas() {
    int op;
    do {
        limpiar();
        std::cout << "  GESTION DE RUTAS (Lista Enlazada)\n";
        std::cout << "  1. Agregar ciudad al final\n";
        std::cout << "  2. Eliminar ciudad por nombre\n";
        std::cout << "  3. Eliminar ciudad por posicion\n";
        std::cout << "  4. Mostrar ruta completa\n";
        std::cout << "  0. Volver\n";
        std::cout << "  Opcion: "; std::cin >> op;
        std::cin.ignore();
        if (op == 1) {
            std::string nom, cod;
            std::cout << "  Nombre de la ciudad: "; std::getline(std::cin, nom);
            std::cout << "  Codigo: "; std::getline(std::cin, cod);
            gestorRutas.agregarCiudad(nom, cod);
        } else if (op == 2) {
            std::string nom;
            std::cout << "  Nombre a eliminar: "; std::getline(std::cin, nom);
            gestorRutas.eliminarCiudadNombre(nom);
        } else if (op == 3) {
            int pos;
            std::cout << "  Posicion (0-based): "; std::cin >> pos;
            gestorRutas.eliminarCiudadPosicion(pos);
        } else if (op == 4) {
            gestorRutas.mostrarRuta();
        }
        if (op != 0) pausar();
    } while (op != 0);
}

void SistemaMensajeria::menuPaquetes() {
    int op;
    do {
        limpiar();
        std::cout << "  GESTION DE PAQUETES\n";
        std::cout << "  -- Cola Pendientes --\n";
        std::cout << "  1. Agregar paquete pendiente\n";
        std::cout << "  2. Procesar paquete pendiente\n";
        std::cout << "  3. Mostrar pendientes\n";
        std::cout << "  -- Pila Urgentes --\n";
        std::cout << "  4. Agregar paquete urgente\n";
        std::cout << "  5. Procesar paquete urgente\n";
        std::cout << "  6. Mostrar urgentes\n";
        std::cout << "  0. Volver\n";
        std::cout << "  Opcion: "; std::cin >> op;
        std::cin.ignore();
        if (op == 1) {
            std::string d, dest;
            std::cout << "  Descripcion: "; std::getline(std::cin, d);
            std::cout << "  Destino: "; std::getline(std::cin, dest);
            gestorPaquetes.agregarPendiente(d, dest);
        } else if (op == 2) {
            gestorPaquetes.procesarPendiente();
        } else if (op == 3) {
            gestorPaquetes.mostrarPendientes();
        } else if (op == 4) {
            std::string d, dest;
            std::cout << "  Descripcion: "; std::getline(std::cin, d);
            std::cout << "  Destino: "; std::getline(std::cin, dest);
            gestorPaquetes.agregarUrgente(d, dest);
        } else if (op == 5) {
            gestorPaquetes.procesarUrgente();
        } else if (op == 6) {
            gestorPaquetes.mostrarUrgentes();
        }
        if (op != 0) pausar();
    } while (op != 0);
}

void SistemaMensajeria::menuSimulacion() {
    int op;
    do {
        limpiar();
        std::cout << "  SIMULACION: COLA CIRCULAR (Camion)\n";
        std::cout << "  1. Cargar punto de control\n";
        std::cout << "  2. Simular desplazamiento (avanzar)\n";
        std::cout << "  3. Mostrar posicion actual\n";
        std::cout << "  4. Mostrar todos los puntos\n";
        std::cout << "  0. Volver\n";
        std::cout << "  Opcion: "; std::cin >> op;
        std::cin.ignore();
        if (op == 1) {
            std::string p;
            std::cout << "  Nombre del punto: "; std::getline(std::cin, p);
            gestorPaquetes.cargarPuntoControl(p);
        } else if (op == 2) {
            gestorPaquetes.simularDesplazamiento();
        } else if (op == 3) {
            gestorPaquetes.mostrarPosicion();
        } else if (op == 4) {
            gestorPaquetes.mostrarColaCircular();
        }
        if (op != 0) pausar();
    } while (op != 0);
}

void SistemaMensajeria::menuMatrices() {
    int op;
    do {
        limpiar();
        std::cout << "  MATRICES\n";
        std::cout << "  1. Ver Matriz 1D (Distancias)\n";
        std::cout << "  2. Ver Matriz 2D (Tiempos)\n";
        std::cout << "  3. Ver Matriz Dispersa (Prioridades)\n";
        std::cout << "  0. Volver\n";
        std::cout << "  Opcion: "; std::cin >> op;
        std::cin.ignore();
        if (op == 1) gestorRutas.mostrarDistancias();
        else if (op == 2) gestorRutas.mostrarTiempos();
        else if (op == 3) gestorRutas.mostrarMatrizDispersa();
        if (op != 0) pausar();
    } while (op != 0);
}

void SistemaMensajeria::mostrarResumen() const {
    limpiar();
    std::cout << "  ========== RESUMEN GENERAL ==========\n\n";
    std::cout << "  [RUTA ACTUAL]\n";
    gestorRutas.mostrarRuta();
    std::cout << "\n  [PAQUETES PENDIENTES]\n";
    gestorPaquetes.mostrarPendientes();
    std::cout << "\n  [PAQUETES URGENTES]\n";
    gestorPaquetes.mostrarUrgentes();
    std::cout << "\n  [CAMION - COLA CIRCULAR]\n";
    gestorPaquetes.mostrarColaCircular();
    std::cout << "\n  [DISTANCIAS - MATRIZ 1D]\n";
    gestorRutas.mostrarDistancias();
    std::cout << "\n  [TIEMPOS - MATRIZ 2D]\n";
    gestorRutas.mostrarTiempos();
    std::cout << "\n  [PRIORIDADES - MATRIZ DISPERSA]\n";
    gestorRutas.mostrarMatrizDispersa();
}

void SistemaMensajeria::ejecutar() {
    inicializarDatosEjemplo();
    int op;
    do {
        limpiar();
        std::cout << "\n";
        std::cout << "  ==========================================\n";
        std::cout << "     SISTEMA DE MENSAJERIA Y RUTAS v1.0\n";
        std::cout << "  ==========================================\n";
        std::cout << "  1. Gestion de Rutas (Lista Enlazada)\n";
        std::cout << "  2. Gestion de Paquetes (Cola / Pila)\n";
        std::cout << "  3. Simulacion Camion (Cola Circular)\n";
        std::cout << "  4. Matrices (1D, 2D, Dispersa)\n";
        std::cout << "  5. Resumen General\n";
        std::cout << "  0. Salir\n";
        std::cout << "  Opcion: "; std::cin >> op;
        std::cin.ignore();
        switch(op) {
            case 1: menuRutas(); break;
            case 2: menuPaquetes(); break;
            case 3: menuSimulacion(); break;
            case 4: menuMatrices(); break;
            case 5: mostrarResumen(); pausar(); break;
            case 0: std::cout << "\n  Hasta luego!\n\n"; break;
            default: std::cout << "  Opcion invalida.\n";
        }
    } while (op != 0);
}

#pragma once
#include "Ruta.h"
#include <vector>
#include <string>
#include <map>
#include <tuple>

class GestorRutas {
private:
    Ruta ruta;

    // Matriz 1D: distancias entre puntos relevantes
    std::vector<double> distancias1D;
    std::vector<std::string> etiquetas1D;

    // Matriz 2D: tiempos estimados entre ciudades (NxN)
    std::vector<std::vector<double>> tiempos2D;
    std::vector<std::string> ciudades2D;

    // Matriz dispersa: rutas prioritarias (solo almacena valores no-cero)
    // Clave: (fila, columna), Valor: prioridad
    std::map<std::pair<int,int>, double> matrizDispersa;
    int filasMD, columnasMD;
    std::vector<std::string> etiquetasMD;

public:
    GestorRutas();

    // Gestión de ruta (lista enlazada)
    void agregarCiudad(const std::string& nombre, const std::string& codigo);
    void eliminarCiudadNombre(const std::string& nombre);
    void eliminarCiudadPosicion(int pos);
    void mostrarRuta() const;

    // Matriz 1D
    void agregarDistancia(const std::string& etiqueta, double distancia);
    void mostrarDistancias() const;
    void inicializarDistanciasEjemplo();

    // Matriz 2D
    void inicializarTiempos(const std::vector<std::string>& ciudades);
    void setTiempo(int i, int j, double tiempo);
    void mostrarTiempos() const;
    void inicializarTiemposEjemplo();

    // Matriz dispersa
    void inicializarMatrizDispersa(int filas, int columnas, const std::vector<std::string>& etiquetas);
    void setPrioridad(int fila, int columna, double valor);
    void mostrarMatrizDispersa() const;
    void inicializarDispersaEjemplo();

    Ruta& getRuta();
};

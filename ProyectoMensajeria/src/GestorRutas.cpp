#include "GestorRutas.h"
#include <iostream>
#include <iomanip>

GestorRutas::GestorRutas() : filasMD(0), columnasMD(0) {}

void GestorRutas::agregarCiudad(const std::string& nombre, const std::string& codigo) {
    ruta.agregarCiudad(nombre, codigo);
}

void GestorRutas::eliminarCiudadNombre(const std::string& nombre) {
    if (!ruta.eliminarPorNombre(nombre))
        std::cout << "  Ciudad '" << nombre << "' no encontrada.\n";
}

void GestorRutas::eliminarCiudadPosicion(int pos) {
    if (!ruta.eliminarPorPosicion(pos))
        std::cout << "  Posición " << pos << " inválida.\n";
}

void GestorRutas::mostrarRuta() const {
    ruta.mostrarRuta();
}

void GestorRutas::agregarDistancia(const std::string& etiqueta, double distancia) {
    etiquetas1D.push_back(etiqueta);
    distancias1D.push_back(distancia);
}

void GestorRutas::mostrarDistancias() const {
    std::cout << "  === Matriz 1D: Distancias ===\n";
    if (distancias1D.empty()) { std::cout << "  Sin datos.\n"; return; }
    for (size_t i = 0; i < distancias1D.size(); i++) {
        std::cout << "  [" << i << "] " << std::setw(20) << std::left
                  << etiquetas1D[i] << " : " << distancias1D[i] << " km\n";
    }
}

void GestorRutas::inicializarDistanciasEjemplo() {
    distancias1D.clear(); etiquetas1D.clear();
    agregarDistancia("CdVictoria -> Monterrey", 300.0);
    agregarDistancia("Monterrey -> Saltillo",    87.0);
    agregarDistancia("Saltillo -> Torreon",      285.0);
    agregarDistancia("Torreon -> Durango",       195.0);
    agregarDistancia("Durango -> Mazatlan",      320.0);
}

void GestorRutas::inicializarTiempos(const std::vector<std::string>& ciudades) {
    ciudades2D = ciudades;
    int n = ciudades.size();
    tiempos2D.assign(n, std::vector<double>(n, 0.0));
}

void GestorRutas::setTiempo(int i, int j, double tiempo) {
    if (i >= 0 && j >= 0 && i < (int)tiempos2D.size() && j < (int)tiempos2D[0].size()) {
        tiempos2D[i][j] = tiempo;
        tiempos2D[j][i] = tiempo;
    }
}

void GestorRutas::mostrarTiempos() const {
    std::cout << "  === Matriz 2D: Tiempos Estimados (horas) ===\n";
    if (tiempos2D.empty()) { std::cout << "  Sin datos.\n"; return; }
    int n = ciudades2D.size();
    std::cout << "  " << std::setw(14) << " ";
    for (auto& c : ciudades2D) std::cout << std::setw(10) << c.substr(0,8);
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << "  " << std::setw(14) << std::left << ciudades2D[i].substr(0,12);
        for (int j = 0; j < n; j++)
            std::cout << std::setw(10) << std::fixed << std::setprecision(1) << tiempos2D[i][j];
        std::cout << "\n";
    }
}

void GestorRutas::inicializarTiemposEjemplo() {
    std::vector<std::string> ciudades = {"CdVictoria","Monterrey","Saltillo","Torreon","Durango"};
    inicializarTiempos(ciudades);
    setTiempo(0,1, 3.5); setTiempo(0,2, 4.2); setTiempo(0,3, 7.0); setTiempo(0,4, 9.5);
    setTiempo(1,2, 1.0); setTiempo(1,3, 3.5); setTiempo(1,4, 6.0);
    setTiempo(2,3, 3.0); setTiempo(2,4, 5.5);
    setTiempo(3,4, 2.5);
}

void GestorRutas::inicializarMatrizDispersa(int filas, int columnas, const std::vector<std::string>& etiquetas) {
    filasMD = filas; columnasMD = columnas;
    etiquetasMD = etiquetas;
    matrizDispersa.clear();
}

void GestorRutas::setPrioridad(int fila, int columna, double valor) {
    if (fila < 0 || columna < 0 || fila >= filasMD || columna >= columnasMD) return;
    if (valor != 0.0)
        matrizDispersa[{fila, columna}] = valor;
    else
        matrizDispersa.erase({fila, columna});
}

void GestorRutas::mostrarMatrizDispersa() const {
    std::cout << "  === Matriz Dispersa: Rutas Prioritarias ===\n";
    if (matrizDispersa.empty()) { std::cout << "  Sin rutas prioritarias registradas.\n"; return; }
    std::cout << "  Dimensión: " << filasMD << " x " << columnasMD << "\n";
    std::cout << "  Elementos no-cero (" << matrizDispersa.size() << "):\n";
    for (auto& [key, val] : matrizDispersa) {
        std::string org = (key.first < (int)etiquetasMD.size()) ? etiquetasMD[key.first] : "?";
        std::string dst = (key.second < (int)etiquetasMD.size()) ? etiquetasMD[key.second] : "?";
        std::cout << "  [" << key.first << "," << key.second << "] "
                  << org << " -> " << dst
                  << "  | Prioridad: " << val << "\n";
    }
}

void GestorRutas::inicializarDispersaEjemplo() {
    std::vector<std::string> nodos = {"CdVictoria","Monterrey","Saltillo","Torreon","Durango","Mazatlan"};
    inicializarMatrizDispersa(6, 6, nodos);
    setPrioridad(0, 1, 9.5);  // CdVictoria -> Monterrey, alta prioridad
    setPrioridad(1, 3, 7.0);  // Monterrey -> Torreon
    setPrioridad(3, 4, 8.0);  // Torreon -> Durango
    setPrioridad(4, 5, 9.0);  // Durango -> Mazatlan
}

Ruta& GestorRutas::getRuta() { return ruta; }

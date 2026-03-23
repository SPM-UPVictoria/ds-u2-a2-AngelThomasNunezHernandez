cmake_minimum_required(VERSION 3.10)
project(SistemaMensajeria VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/Ciudad.cpp
    src/Ruta.cpp
    src/Paquete.cpp
    src/GestorRutas.cpp
    src/GestorPaquetes.cpp
    src/SistemaMensajeria.cpp
    src/main.cpp
)

add_executable(SistemaMensajeria ${SOURCES})

target_include_directories(SistemaMensajeria PRIVATE include)

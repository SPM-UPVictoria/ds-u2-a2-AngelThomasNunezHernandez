[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/hVWui5Ed)
## **Sistema de Gestión de Rutas y Paquetes de una Empresa de Mensajería**

## **1. Planteamiento del Problema**

Una empresa de mensajería requiere un sistema modular para gestionar **rutas**, **paquetes** y **procesos internos de entrega**. La empresa necesita automatizar:

* El registro de ciudades en una ruta (lista enlazada).
* La administración de paquetes pendientes de asignar (cola).
* La organización de paquetes urgentes (pila).
* La simulación del desplazamiento de un camión mediante puntos de control (cola circular).
* El almacenamiento interno de datos de distancias (matriz 1D) y tiempos aproximados entre ciudades (matriz 2D).
* El registro de rutas prioritarias mediante una **matriz poco densa (dispersa)**.

Todo el sistema debe construirse utilizando **Programación Orientada a Objetos en C++**, de manera modular y organizada, y deberá compilarse mediante **CMake**.

### **El sistema debe incluir las siguientes clases mínimas:**

* `Ciudad`
* `Ruta` (implementada con una lista enlazada)
* `Paquete`
* `GestorRutas`
* `GestorPaquetes`
* `SistemaMensajeria` (clase principal que integra todo)

---

## **2. Funcionalidades que debe permitir el sistema**

El programa deberá ofrecer un menú en consola que permita:

### **Gestión de Rutas (Lista Enlazada)**

* Agregar ciudad al final de la ruta.
* Eliminar una ciudad por nombre o posición.
* Mostrar ruta completa (recorrido).

### **Gestión de Paquetes**

**Cola (pendientes):**

* Agregar paquete pendiente.
* Procesar paquete pendiente (extraerlo de la cola y asignarlo a la ruta).

**Pila (urgentes):**

* Agregar paquete urgente.
* Procesar paquete urgente (LIFO).

### **Simulación con Cola Circular**

* Cargar puntos de control del camión.
* Simular desplazamiento (avance circular continuo).
* Mostrar posición actual.

### **Manejo de Matrices**

* Matriz 1D → Distancias aproximadas entre puntos relevantes.
* Matriz 2D → Tiempos estimados entre ciudades.
* Matriz dispersa → Rutas de alta prioridad.

### **Resumen General**

* Mostrar estado de paquetes, rutas, matrices y camión.

---

## **3. Temas y conocimientos a aplicar**

### **Programación Orientada a Objetos en C++**

* Composición de clases.
* Múltiples archivos `.h` y `.cpp`.

### **CMake**

* Proyecto modular.
* Archivos organizados dentro de `/src` y `/include`.
* Generación de ejecutable con `CMakeLists.txt`.

### **Estructuras de Datos**

* Lista enlazada.
* Pila.
* Cola.
* Cola circular.
* Matrices 1D y 2D.
* Matriz dispersa (poco densa).

### **Reporte Técnico en PDF**

* Documentación clara.
* Explicación del diseño.
* Diagramas de clases.
* Evidencias de funcionamiento.

---

## **4. Estructura recomendada del proyecto**

```
/ProyectoMensajeria
│
├── CMakeLists.txt
├── /src
│   ├── Ciudad.cpp
│   ├── Ruta.cpp
│   ├── Paquete.cpp
│   ├── GestorRutas.cpp
│   ├── GestorPaquetes.cpp
│   ├── SistemaMensajeria.cpp
│   └── main.cpp
│
├── /include
│   ├── Ciudad.h
│   ├── Ruta.h
│   ├── Paquete.h
│   ├── GestorRutas.h
│   ├── GestorPaquetes.h
│   └── SistemaMensajeria.h
```

---

## **5. Entregables**

Se deberán entregar:

### **1. Código fuente completo en C++**

Debe compilar sin errores y estar ordenado según la estructura sugerida.

### **2. Proyecto completo en CMake**

Incluyendo:

* `CMakeLists.txt` funcional.
* Organización modular.

### **3. Reporte en PDF**

El reporte se subirá al apartado en google classroom debe incluir:

* Portada, introducción y explicación del problema.
* Diseño de clases (diagramas UML sugeridos).
* Explicación de las estructuras de datos utilizadas y su justificación.
* Resultados y capturas de pantalla del programa en ejecución.
* Conclusiones.


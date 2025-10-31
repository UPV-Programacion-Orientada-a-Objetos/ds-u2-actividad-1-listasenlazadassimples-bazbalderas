#include "SensorPresion.h"
#include <iostream>

SensorPresion::SensorPresion(const char* nombre) : SensorBase(nombre) {}

SensorPresion::~SensorPresion() {
    std::cout << "  [Destructor Sensor " << nombre << "] Liberando Lista Interna...\n";
}

void SensorPresion::agregarLectura(int valor) {
    historial.insertar(valor);
    std::cout << "[Log] Insertando Nodo<int> en " << nombre << "\n";
}

void SensorPresion::procesarLectura() {
    std::cout << "[" << nombre << "] (Presion): ";
    if (historial.getCantidad() > 0) {
        int promedio = historial.calcularPromedio();
        std::cout << "Promedio de lecturas: " << promedio << ".\n";
    } else {
        std::cout << "No hay lecturas para procesar.\n";
    }
}

void SensorPresion::imprimirInfo() const {
    std::cout << nombre << " (Presion)\n";
}

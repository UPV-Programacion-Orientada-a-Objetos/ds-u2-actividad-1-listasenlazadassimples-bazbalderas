#include "SensorTemperatura.h"
#include <iostream>

SensorTemperatura::SensorTemperatura(const char* nombre) : SensorBase(nombre) {}

SensorTemperatura::~SensorTemperatura() {
    std::cout << "  [Destructor Sensor " << nombre << "] Liberando Lista Interna...\n";
}

void SensorTemperatura::agregarLectura(float valor) {
    historial.insertar(valor);
    std::cout << "[Log] Insertando Nodo<float> en " << nombre << "\n";
}

void SensorTemperatura::procesarLectura() {
    std::cout << "[" << nombre << "] (Temperatura): ";
    if (historial.getCantidad() > 0) {
        float eliminado = historial.eliminarValorMasBajo();
        float promedio = historial.calcularPromedio();
        std::cout << "Lectura más baja (" << eliminado << ") eliminada. ";
        std::cout << "Promedio restante: " << promedio << ".\n";
    } else {
        std::cout << "No hay lecturas para procesar.\n";
    }
}

void SensorTemperatura::imprimirInfo() const {
    std::cout << nombre << " (Temperatura)\n";
}

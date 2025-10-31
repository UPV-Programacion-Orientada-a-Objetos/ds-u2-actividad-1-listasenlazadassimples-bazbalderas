#include "GestorSensores.h"
#include "SensorTemperatura.h"
#include "SensorPresion.h"
#include <iostream>
#include <cstring>

GestorSensores::~GestorSensores() {
    while (primero) {
        NodoGestor* temp = primero;
        primero = primero->siguiente;
        std::cout << "[Destructor General] Liberando Nodo: ";
        temp->sensor->imprimirInfo();
        delete temp->sensor;
        delete temp;
    }
}

bool GestorSensores::existeSensor(const char* id) const {
    NodoGestor* actual = primero;
    while (actual) {
        if (strcmp(actual->sensor->getNombre(), id) == 0) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void GestorSensores::agregarSensorTemp(const char* id) {
    if (existeSensor(id)) {
        std::cout << "[Error] Ya existe un sensor con ID " << id << std::endl;
        return;
    }
    SensorTemperatura* sensor = new SensorTemperatura(id);
    NodoGestor* nodo = new NodoGestor(sensor);
    nodo->siguiente = primero;
    primero = nodo;
    std::cout << "[Log] Sensor '" << id << "' (Temp) creado e insertado en la lista de gestión.\n";
}

void GestorSensores::agregarSensorPresion(const char* id) {
    if (existeSensor(id)) {
        std::cout << "[Error] Ya existe un sensor con ID " << id << std::endl;
        return;
    }
    SensorPresion* sensor = new SensorPresion(id);
    NodoGestor* nodo = new NodoGestor(sensor);
    nodo->siguiente = primero;
    primero = nodo;
    std::cout << "[Log] Sensor '" << id << "' (Presion) creado e insertado en la lista de gestión.\n";
}

SensorBase* GestorSensores::buscarSensor(const char* id) {
    NodoGestor* actual = primero;
    while (actual) {
        if (strcmp(actual->sensor->getNombre(), id) == 0) {
            return actual->sensor;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void GestorSensores::registrarLecturaTemp(const char* id, float valor) {
    SensorBase* sensor = buscarSensor(id);
    if (sensor && sensor->esTemperatura()) {
        ((SensorTemperatura*)sensor)->agregarLectura(valor);
    }
}

void GestorSensores::registrarLecturaPresion(const char* id, int valor) {
    SensorBase* sensor = buscarSensor(id);
    if (sensor && !sensor->esTemperatura()) {
        ((SensorPresion*)sensor)->agregarLectura(valor);
    }
}

void GestorSensores::procesarTodos() {
    NodoGestor* actual = primero;
    while (actual) {
        actual->sensor->procesarLectura();
        actual = actual->siguiente;
    }
}
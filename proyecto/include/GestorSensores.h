#ifndef GESTORSENSORES_H
#define GESTORSENSORES_H

#include "SensorBase.h"

/// @brief Nodo para la lista de gestión de sensores
struct NodoGestor {
    SensorBase* sensor;
    NodoGestor* siguiente;
    NodoGestor(SensorBase* s) : sensor(s), siguiente(nullptr) {}
};

/// @brief Gestor principal de sensores
class GestorSensores {
private:
    NodoGestor* primero;
    bool existeSensor(const char* id) const;  // Nuevo método

public:
    GestorSensores() : primero(nullptr) {}
    ~GestorSensores();
    
    void agregarSensorTemp(const char* id);
    void agregarSensorPresion(const char* id);
    SensorBase* buscarSensor(const char* id);
    void registrarLecturaTemp(const char* id, float valor);
    void registrarLecturaPresion(const char* id, int valor);
    void procesarTodos();
};

#endif
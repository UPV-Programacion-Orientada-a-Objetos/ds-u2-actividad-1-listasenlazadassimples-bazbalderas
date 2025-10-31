#ifndef LISTASENSOR_H
#define LISTASENSOR_H

#include <iostream>

template <typename T>
class ListaSensor {
private:
    /// @brief Nodo genérico para lista de lecturas
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
    };
    
    Nodo* primero;
    int cantidad;

public:
    // Constructor y destructor
    ListaSensor() : primero(nullptr), cantidad(0) {}
    
    ~ListaSensor() {
        while (primero) {
            Nodo* temp = primero;
            primero = primero->siguiente;
            std::cout << "    [Log] Nodo liberado: " << temp->dato << std::endl;
            delete temp;
            cantidad--;
        }
    }
    
    // Constructor de copia
    ListaSensor(const ListaSensor& otra) : primero(nullptr), cantidad(0) {
        Nodo* actual = otra.primero;
        while (actual) {
            insertar(actual->dato);
            actual = actual->siguiente;
        }
    }
    
    // Operador de asignación
    ListaSensor& operator=(const ListaSensor& otra) {
        if (this != &otra) {
            // Limpiamos la lista actual
            while (primero) {
                Nodo* temp = primero;
                primero = primero->siguiente;
                delete temp;
            }
            cantidad = 0;
            
            // Copiamos la otra lista
            Nodo* actual = otra.primero;
            while (actual) {
                insertar(actual->dato);
                actual = actual->siguiente;
            }
        }
        return *this;
    }
    
    void insertar(const T& valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!primero) {
            primero = nuevo;
        } else {
            Nodo* actual = primero;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        cantidad++;
    }
    
    T calcularPromedio() const {
        if (!primero) return T();
        T suma = T();
        Nodo* actual = primero;
        while (actual) {
            suma += actual->dato;
            actual = actual->siguiente;
        }
        return suma / cantidad;
    }
    
    int getCantidad() const { return cantidad; }
    
    T eliminarValorMasBajo() {
        if (!primero) return T();
        
        Nodo* actual = primero;
        Nodo* minNodo = primero;
        T minValor = primero->dato;
        
        // Encontrar el valor más bajo
        while (actual) {
            if (actual->dato < minValor) {
                minValor = actual->dato;
                minNodo = actual;
            }
            actual = actual->siguiente;
        }
        
        // Eliminar el nodo con el valor más bajo
        if (minNodo == primero) {
            primero = primero->siguiente;
        } else {
            actual = primero;
            while (actual->siguiente != minNodo) {
                actual = actual->siguiente;
            }
            actual->siguiente = minNodo->siguiente;
        }
        
        delete minNodo;
        cantidad--;
        std::cout << "    [Log] Valor más bajo eliminado: " << minValor << std::endl;
        return minValor;
    }
};

#endif
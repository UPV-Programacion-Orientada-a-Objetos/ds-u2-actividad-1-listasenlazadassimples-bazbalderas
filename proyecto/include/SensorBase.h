/**
 * @file SensorBase.h
 * @brief Clase base abstracta para todos los tipos de sensores
 * @author Ricardo Sebastián Balderas González
 */

#pragma once

/**
 * @class SensorBase
 * @brief Define la interfaz común para todos los sensores
 */
class SensorBase {
protected:
    char nombre[50];  ///< Identificador único del sensor

public:
    /**
     * @brief Constructor que inicializa el nombre del sensor
     * @param nombre Identificador único del sensor
     */
    SensorBase(const char* nombre);
    
    /**
     * @brief Destructor virtual puro
     */
    virtual ~SensorBase() = 0;
    
    /**
     * @brief Procesa las lecturas del sensor
     */
    virtual void procesarLectura() = 0;
    
    virtual void imprimirInfo() const = 0;
    virtual bool esTemperatura() const = 0;
    
    const char* getNombre() const { return nombre; }
};
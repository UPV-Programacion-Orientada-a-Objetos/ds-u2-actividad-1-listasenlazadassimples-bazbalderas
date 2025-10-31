#ifndef SENSORTEMPERATURA_H
#define SENSORTEMPERATURA_H

#include "SensorBase.h"
#include "ListaSensor.h"

/// @brief Sensor de Temperatura (float)
class SensorTemperatura : public SensorBase {
private:
    ListaSensor<float> historial;

public:
    SensorTemperatura(const char* nombre);
    ~SensorTemperatura() override;
    void agregarLectura(float valor);
    void procesarLectura() override;
    void imprimirInfo() const override;
    bool esTemperatura() const override { return true; }
};

#endif
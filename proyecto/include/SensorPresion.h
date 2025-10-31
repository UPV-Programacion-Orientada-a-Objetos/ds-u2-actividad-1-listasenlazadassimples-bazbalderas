#ifndef SENSORPRESION_H
#define SENSORPRESION_H

#include "SensorBase.h"
#include "ListaSensor.h"

/// @brief Sensor de Presión (int)
class SensorPresion : public SensorBase {
private:
    ListaSensor<int> historial;

public:
    SensorPresion(const char* nombre);
    ~SensorPresion() override;
    void agregarLectura(int valor);
    void procesarLectura() override;
    void imprimirInfo() const override;
    bool esTemperatura() const override { return false; }
};

#endif
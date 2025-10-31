#include "SensorBase.h"
#include <cstring>

SensorBase::SensorBase(const char* nombre) {
    strncpy(this->nombre, nombre, 49);
    this->nombre[49] = '\0';
}

SensorBase::~SensorBase() {}

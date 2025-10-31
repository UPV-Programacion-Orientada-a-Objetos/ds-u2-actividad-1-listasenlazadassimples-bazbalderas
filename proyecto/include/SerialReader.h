#pragma once
#include <iostream>

class SerialReader {
private:
    const char* portName;
    bool isConnected;

public:
    SerialReader(const char* port = "COM3");
    ~SerialReader();
    bool conectar();
    bool leerDato(char& tipo, float& valor);
    void desconectar();
};

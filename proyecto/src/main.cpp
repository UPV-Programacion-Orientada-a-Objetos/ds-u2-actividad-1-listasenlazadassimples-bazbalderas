#include <iostream>
#include "GestorSensores.h"
using namespace std;

int main() {
    try {
        GestorSensores gestor;
        int opcion;
        char id[50];
        float valorF;
        int valorI;

        cout << "--- Sistema IoT de Monitoreo Polimórfico ---" << endl;
        
        do {
            cout << "\n1. Crear Sensor (Temp - FLOAT)" << endl;
            cout << "2. Crear Sensor (Presion - INT)" << endl;
            cout << "3. Registrar Lectura" << endl;
            cout << "4. Ejecutar Procesamiento Polimórfico" << endl;
            cout << "5. Leer desde Arduino" << endl;
            cout << "6. Salir (Liberar Memoria)" << endl;
            cout << "\nOpción: ";
            
            if (!(cin >> opcion)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Error] Entrada inválida\n";
                continue;
            }
            cin.ignore();

            switch(opcion) {
                case 1:
                    cout << "Ingrese ID del sensor: ";
                    cin.getline(id, 50);
                    gestor.agregarSensorTemp(id);
                    break;
                
                case 2:
                    cout << "Ingrese ID del sensor: ";
                    cin.getline(id, 50);
                    gestor.agregarSensorPresion(id);
                    break;
                
                case 3: {
                    cout << "Buscar ID de sensor: ";
                    cin.getline(id, 50);
                    SensorBase* sensor = gestor.buscarSensor(id);
                    if (!sensor) {
                        cout << "[Error] Sensor no encontrado.\n";
                        break;
                    }
                    
                    try {
                        if (sensor->esTemperatura()) {
                            cout << "Ingrese valor (float): ";
                            while (!(cin >> valorF)) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "[Error] Ingrese un número válido: ";
                            }
                            cin.ignore();
                            gestor.registrarLecturaTemp(id, valorF);
                        } else {
                            cout << "Ingrese valor (int): ";
                            while (!(cin >> valorI)) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "[Error] Ingrese un número válido: ";
                            }
                            cin.ignore();
                            gestor.registrarLecturaPresion(id, valorI);
                        }
                    } catch (const std::bad_alloc& e) {
                        cout << "[Error] No hay memoria disponible\n";
                    }
                    break;
                }
                
                case 4:
                    cout << "\n--- Ejecutando Procesamiento Polimórfico ---\n";
                    gestor.procesarTodos();
                    break;
                
                case 5: {
                    SerialReader serial;
                    if (serial.conectar()) {
                        cout << "Leyendo datos del Arduino..." << endl;
                        char tipo;
                        float valor;
                        while (serial.leerDato(tipo, valor)) {
                            if (tipo == 'T') {
                                gestor.registrarLecturaTemp("T-001", valor);
                            } else if (tipo == 'P') {
                                gestor.registrarLecturaPresion("P-105", (int)valor);
                            }
                        }
                        serial.desconectar();
                    }
                    break;
                }
                
                case 6:
                    cout << "\n--- Liberación de Memoria en Cascada ---\n";
                    break;
                
                default:
                    cout << "[Error] Opción inválida\n";
            }
        } while(opcion != 6);

        cout << "Sistema cerrado. Memoria limpia.\n";
    } catch (const std::exception& e) {
        cout << "[Error Fatal] " << e.what() << endl;
        return 1;
    }
    return 0;
}
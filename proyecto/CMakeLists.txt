# CMakeLists.txt básico para el proyecto de sensores
cmake_minimum_required(VERSION 3.10)
project(SistemaMonitoreo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(monitor 
    src/main.cpp
    src/SensorBase.cpp
    src/SensorTemperatura.cpp
    src/SensorPresion.cpp
    src/GestorSensores.cpp
    src/SerialReader.cpp
)

if(WIN32)
    target_link_libraries(monitor winmm)
endif()
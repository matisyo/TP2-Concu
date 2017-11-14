cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Queue.cpp Queue.h Cliente.cpp Cliente.h Servidor.cpp Servidor.h Identificadores.h cerrate.cpp Clima.cpp Clima.h EstadoDelClima.cpp EstadoDelClima.h EstadoDelClimaSerializer.cpp EstadoDelClimaSerializer.h)
add_executable(untitled ${SOURCE_FILES})
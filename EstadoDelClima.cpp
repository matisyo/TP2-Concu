//
// Created by navent on 14/11/17.
//

#include "EstadoDelClima.h"



EstadoDelClima::EstadoDelClima(std::string ciudad, int temperatura, int presion, int humedad) {

    this->ciudad = ciudad;
    this->temperatura = temperatura;
    this->presion = presion;
    this->humedad;
}


std::string EstadoDelClima::getCiudad() {

    return this->ciudad;
}

int EstadoDelClima::getTemperatura() {

    return this->temperatura;

}

int EstadoDelClima::getPresion() {

    return this->presion;
}

int EstadoDelClima::getHumedad() {

    return this->humedad;
}

EstadoDelClima::~EstadoDelClima() {

}
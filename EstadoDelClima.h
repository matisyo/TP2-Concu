//
// Created by navent on 14/11/17.
//

#ifndef UNTITLED_ESTADODELCLIMA_H
#define UNTITLED_ESTADODELCLIMA_H
#include <cstring>
#include <iostream>


class EstadoDelClima {

private:

    std::string ciudad;
    int temperatura;
    int presion;
    int humedad;

public:

    EstadoDelClima(std::string ciudad, int temperatura, int presion, int humedad);


    std::string getCiudad();

    int getTemperatura();
    int getPresion();
    int getHumedad();

    ~EstadoDelClima();

};


#endif //UNTITLED_ESTADODELCLIMA_H

//
// Created by navent on 14/11/17.
//

#ifndef UNTITLED_CLIMA_H
#define UNTITLED_CLIMA_H


#include "EstadoDelClima.h"
#include <vector>

class Clima {

private:

    std::vector<EstadoDelClima*> *climas;

public:

    Clima(std::vector<EstadoDelClima*> *climas);


    EstadoDelClima*  getEstadoByCiudad(std::string ciudad);


    int run();

};


#endif //UNTITLED_CLIMA_H

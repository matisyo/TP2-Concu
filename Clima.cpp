//
// Created by navent on 14/11/17.
//

#include <iostream>
#include "Clima.h"
#include "Queue.h"
#include "Identificadores.h"
#include <unistd.h>
#include <cstring>
#include "EstadoDelClimaSerializer.h"


int Clima::run() {

    EstadoDelClima *estado = getEstadoByCiudad("Buenos Aires");

    Queue clima(Identificadores::ID_CLIMA);
    Queue servidor(Identificadores::ID_SERVIDOR);

    bool salir = false;
    std::cout << "Weather service starting" << std::endl;
    while (not salir) {
        msj pop;
        clima.recive(&pop, Identificadores::MSJ_CLIMA);
        switch (pop.mtype) {
            case Identificadores::MSJ_CLIMA: {

                std::cout << "Weather service received petition" << std::endl;


                pop.from = getpid();

                char *ciudad = pop.mensaje;
                std::cout << "Query for " << ciudad << std::endl;


                std::string result = std::EstadoDelClimaSerializer::serializar(getEstadoByCiudad(ciudad));

                std::cout << result << std::endl;


                strcpy(pop.mensaje, result.c_str());
                servidor.send(&pop);
                salir = true;

                break;
            }
            case Identificadores::MSJ_CERRAR: {
                pop.mtype = pop.from;
                pop.from = getpid();
                std::cout << pop.mensaje << std::endl;
                strcpy(pop.mensaje, "Success");
                servidor.send(&pop);
                salir = true;
                break;
            }
            default: {
                break;
            }
        }

    }


}

Clima::Clima(std::vector<EstadoDelClima *> *climas) {

    this->climas = climas;
}


EstadoDelClima *Clima::getEstadoByCiudad(std::string ciudad) {

    for (int i = 0; i < this->climas->size(); i++) {

        std::string estadoActual = this->climas->at(i)->getCiudad();


        int compr = estadoActual.compare(ciudad);

        if (compr == 0) {
            return this->climas->at(i);
        }

    }

    return new EstadoDelClima("Not found", -1, -1, -1);

}
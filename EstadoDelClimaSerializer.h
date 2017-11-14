//
// Created by navent on 14/11/17.
//

#ifndef UNTITLED_ESTADODELCLIMASERIALIZER_H
#define UNTITLED_ESTADODELCLIMASERIALIZER_H

#endif //UNTITLED_ESTADODELCLIMASERIALIZER_H

#include <string>

#include "EstadoDelClima.h"

namespace std {

    class EstadoDelClimaSerializer {
    private:

        static string intToString(int i);

        static string doubleToString(double d);

    public:

        static const char SEPARADOR = ',';


        EstadoDelClimaSerializer();

        static string serializar(EstadoDelClima *pedido);

        static EstadoDelClima deserializarEstadoDelClima(string estadoDelClimaString);

        virtual ~EstadoDelClimaSerializer();
    };
}
//
// Created by navent on 14/11/17.
//


#include "EstadoDelClimaSerializer.h"

#include <sstream>


namespace std {

    EstadoDelClimaSerializer::EstadoDelClimaSerializer() {

    }

    string EstadoDelClimaSerializer::serializar(EstadoDelClima *estadoDelClima) {

        string estadoClimaStr = estadoDelClima->getCiudad() + SEPARADOR + intToString(estadoDelClima->getHumedad()) + SEPARADOR +
                                intToString(estadoDelClima->getPresion()) + SEPARADOR +
                                intToString(estadoDelClima->getTemperatura());


        return estadoClimaStr;

    }

    string std::EstadoDelClimaSerializer::intToString(int i) {
        stringstream stream;
        stream << i;
        return stream.str();
    }


    EstadoDelClima EstadoDelClimaSerializer::deserializarEstadoDelClima(string estadoDelClimaString) {

        istringstream ss(estadoDelClimaString);
        string ciudad;
        string humedad;
        string presion;
        string temperatura;


        getline(ss, ciudad, SEPARADOR);
        getline(ss, humedad, SEPARADOR);
        getline(ss, presion, SEPARADOR);
        getline(ss, temperatura, SEPARADOR);



        EstadoDelClima estadoDelClima(ciudad, stoi(humedad), stoi(presion), stoi(temperatura));


        return estadoDelClima;

    }


    EstadoDelClimaSerializer::~EstadoDelClimaSerializer() {
        // TODO Auto-generated destructor stub
    }

} /* namespace std */
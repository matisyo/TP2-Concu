#include <iostream>
#include <unistd.h>
#include "Servidor.h"
#include "Cliente.h"
#include "Clima.h"

int main() {
    std::cout << "Hello, World!" << std::endl;



    pid_t serverId = fork();

    if(serverId == 0){

        Servidor::run();

        return 0;
    }

    pid_t weatherSercviceId = fork();


    if(weatherSercviceId != 0){

        EstadoDelClima* estado1 = new EstadoDelClima("Buenos Aires", 10, 10, 10);

        std::vector<EstadoDelClima*> *climas = new std::vector<EstadoDelClima*>();

        climas->push_back(estado1);

        Clima climaService(climas);

        climaService.run();

        return 0;
    }

    sleep(2);

    pid_t cliente1Id = fork();

    if(cliente1Id == 0){

        Cliente::run();

        return 0;
    }




    sleep(60);


    std::cout << "Cierro" << std::endl;




    return 0;
}
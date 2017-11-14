#include <iostream>
#include <unistd.h>
#include "Servidor.h"
#include "Cliente.h"

int main() {
    std::cout << "Hello, World!" << std::endl;



    pid_t serverId = fork();

    if(serverId == 0){

        Servidor::run();

        return 0;
    }

    sleep(10);

    pid_t cliente1Id = fork();

    if(cliente1Id == 0){

        Cliente::run();

        return 0;
    }




    sleep(60);


    std::cout << "Cierro" << std::endl;




    return 0;
}
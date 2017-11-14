#include <iostream>

using namespace std;

#include "Queue.h"
#include "Identificadores.h"
#include "Servidor.h"
#include <string.h>
#include <unistd.h>


int Servidor::run() {

    //PASAR ESTO A CONSTANTES

    Queue clients(Identificadores::ID_SERVIDOR);
    Queue weatherService(Identificadores::ID_CLIMA);
    bool salir = false;
    std::cout << "Server starting" << std::endl;
    while (not salir) {
        msj pop;
        clients.recive(&pop, Identificadores::MSJ_CERRAR * -1);
        switch (pop.mtype) {
            case Identificadores::MSJ_ADMIN:
                break;
            case Identificadores::MSJ_CLIENTE:
                break;
            case Identificadores::MSJ_CLIMA: {
                long mtype_client = pop.from;

                pop.from = getpid();
                std::cout << pop.mensaje << std::endl;
                std::cout << "Mando el mensaje al service" << std::endl;

                weatherService.send(&pop);

                msj wResponse;



                weatherService.recive(&wResponse, Identificadores::MSJ_CLIMA * -1);
                std::cout << "Recibo del service" << std::endl;

                wResponse.from = getpid();
                wResponse.mtype = mtype_client;


                std::cout << wResponse.mensaje << std::endl;


                clients.send(&wResponse);
                salir = true;
                break;
            }
            case Identificadores::MSJ_CERRAR:
                pop.mtype = pop.from;
                pop.from = getpid();
                std::cout << pop.mensaje << std::endl;
                strcpy(pop.mensaje, "Success");
                clients.send(&pop);
                salir = true;
                break;
            default:
                break;
        }

    }


    return 0;
}
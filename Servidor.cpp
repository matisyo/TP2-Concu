#include <iostream>
using namespace std;
#include "Queue.h"
#include "Identificadores.h"
#include "Servidor.h"
#include <string.h>
#include <unistd.h>


int Servidor::run() {

    //PASAR ESTO A CONSTANTES

    Queue c(Identificadores::ID_SERVIDOR);
    bool salir=false;
    std::cout << "Server starting" << std::endl;
    while(not salir){
        msj pop;
        c.recive(&pop,Identificadores::MSJ_CERRAR*-1);
        switch(pop.mtype){
            case Identificadores::MSJ_ADMIN:
                break;
            case Identificadores::MSJ_CLIENTE:
                break;
            case Identificadores::MSJ_CERRAR:
                pop.mtype = pop.from;
                pop.from = getpid();
                std::cout << pop.mensaje << std::endl;
                strcpy(pop.mensaje, "Success");
                c.send(&pop);
                salir=true;
                break;
            default:
                break;
        }

    }


    return 0;
}
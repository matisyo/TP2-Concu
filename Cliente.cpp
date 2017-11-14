#include <iostream>
using namespace std;
#include "Queue.h"
#include <string.h>
#include <unistd.h>
#include "Identificadores.h"
#include "Cliente.h"

int Cliente::run() {


    Queue c(Identificadores::ID_SERVIDOR);

    msj aux;

    aux.mtype = Identificadores::MSJ_CLIMA;
    aux.from = getpid();

    strcpy(aux.mensaje, "Buenos Aires");
    std::cout << "Client sending" << std::endl;

    c.send(&aux);

    msj resp;
    c.recive(&resp,getpid()*-1);
    std::cout << "CLIENT GETS " << resp.mensaje << std::endl;

//    aux.mtype = Identificadores::MSJ_CERRAR;
//    aux.from = getpid();
//    strcpy(aux.mensaje, "Cerrate");
//
//    std::cout << "Client sending" << std::endl;
//
//    c.send(&aux);
//
//    msj aux2;
//    c.recive(&aux2,aux.from);
//    std::cout << aux2.mensaje << std::endl;



    return 0;
}
#include <iostream>
using namespace std;
#include "Queue.h"
#include "Identificadores.h"
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int run() {


    Queue c(Identificadores::ID_SERVIDOR);

    msj aux;
    aux.mtype = Identificadores::MSJ_CERRAR;
    aux.from = getpid();
    strcpy(aux.mensaje, "Cerrate");
    c.send(&aux);

    msj aux2;
    c.recive(&aux2,aux.from);
    std::cout << aux2.mensaje << std::endl;

    return 0;
}
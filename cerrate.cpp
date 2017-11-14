#include <iostream>
using namespace std;
#include "Queue.h"
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int main() {

	//PASAR ESTO A CONSTANTES
	int ID_SERVIDOR = 1225;	
	int ID_COTIZADOR = 1226;
	int ID_CLIMA = 1227;
	int MSJ_ADMIN = 1;
	int MSJ_CLIENTE = 2;
	int MSJ_CERRAR = 3;
		
	Queue c(ID_SERVIDOR);

	msj aux;
	aux.mtype = MSJ_CERRAR;
	aux.from = getpid();
	strcpy(aux.mensaje, "Cerrate");
	c.send(&aux);
	
	msj aux2;	
	c.recive(&aux2,aux.from);
	std::cout << aux2.mensaje << std::endl;
   
    return 0;
}


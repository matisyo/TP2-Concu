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
	const int ID_SERVIDOR = 1225;	
	const int ID_COTIZADOR = 1226;
	const int ID_CLIMA = 1227;
	const int MSJ_ADMIN = 1;
	const int MSJ_CLIENTE = 2;
	const int MSJ_CERRAR = 3;
		
	Queue c(ID_SERVIDOR);
	bool salir=false;
	while(not salir){
		msj pop;
		c.recive(&pop,MSJ_CERRAR*-1);
		switch(pop.mtype){
		case MSJ_ADMIN:
			break;
		case MSJ_CLIENTE:
			break;			
		case MSJ_CERRAR:			
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

#include "Queue.h"
#include <sys/ipc.h>
#include <sys/msg.h>


Queue::Queue(int id){
    qid = msgget(id,IPC_CREAT | 0666);
}
void Queue::send(const msj* mensaje){
    msgsnd(qid,&(*mensaje), sizeof(msj)-sizeof(long),0);
}
void Queue::recive(msj *mensaje,long from){
    msgrcv(qid,&(*mensaje),sizeof(msj)- sizeof(long),from,0);
}
Queue::~Queue(){
    msgctl(qid,IPC_RMID,0);
}
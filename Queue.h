#ifndef TP2_QUEUE_H
#define TP2_QUEUE_H


struct msj{
    long mtype;
    long from;    
    char mensaje[255];
};

class Queue {
private:
	int qid ;
public:	
	Queue(int id);
    ~Queue();
    void send(const msj* mensaje);
	void recive(msj *mensaje,long from);
};


#endif //TP2_QUEUE_H

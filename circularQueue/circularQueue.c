#include "circularQueue.h"

Queue* create (int typeSize, int length){
	Queue* queue = calloc(1,sizeof(Queue));
	queue->elements=calloc(length,typeSize); 
 	queue->typeSize=typeSize;
 	queue->length=length;
	queue->start=-1;
	queue->end=-1;
	return queue;
};

int isEmpty(Queue* queue){  
	return -2 == queue->end+queue->start;
};

int isFull(Queue* queue){
	return (queue->end==queue->length-1 && queue->start==-1 )||queue->start-queue->end==1;
};

void* givesRear(Queue* queue){
	if(isEmpty(queue)) return NULL;	
	return queue->elements+(queue->end*queue->typeSize); 
};

int enqueue(Queue* queue, void* element){
	if(isFull(queue)) return 0;
		if(queue->end==queue->length-1) queue->end=-1;
	memcpy(queue->elements+(++queue->end*queue->typeSize),element,queue->typeSize);
	return 1;
};

void* dequeue(Queue* queue){
	if(isEmpty(queue)) return NULL;	
	queue->start++;
	return queue->elements;
};

#include "queueLib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Queue* create (int typeSize, int length){
	Queue* queue = calloc(1,sizeof(Queue)); 
	queue->elements =calloc(length,typeSize); 
	queue->typeSize=typeSize;
 	queue->rare=-1;
 	queue->length=length;
	return queue;
}

int enQueue(Queue* queue,void* element){
	if(isFull(queue)) 
		return 0;
	memcpy(queue->elements+(++queue->rare*queue->typeSize), element,queue->typeSize);
	return 1;
}

void* deQueue(Queue* queue){
	void* poppedElement = malloc(queue->typeSize);	
	memcpy(poppedElement,queue->elements,queue->typeSize);
	if(isEmpty(queue)) return NULL;	
	memmove(queue->elements,queue->elements+queue->typeSize,(queue->length-1)*queue->typeSize);
	queue->rare--;
	return poppedElement;
}

int isEmpty(Queue* queue){
	if(0 > queue->rare)
		return 1;
	return 0;
}				

int isFull(Queue* queue){
	if(queue->length-1 <= queue->rare)
		return 1;
	return 0;
}
void* givesRare(Queue* queue){
	void* element;
	memcpy( element,queue->elements+(queue->rare*queue->typeSize),queue->typeSize);
	return element;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char String[256];
typedef struct {
	int rare;
	int length;
	int typeSize;	 
	void* elements;
}Queue;


Queue*	create(int typesize,int length);						
int	enQueue(Queue* queue,void* element);				
void* 	deQueue(Queue* queue);							

bool   	isEmpty(Queue* queue);			
bool 	isFull(Queue* queue);
void* 	givesRare(Queue* queue);

#include "priorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

Node* createNode(int priority,void* data){
	Node* node = calloc(1,sizeof(Node));
	node->data = data;
	node->priority = priority;
	node->next = NULL;
	return node;
}

Queue* createQueue(){
	Queue* queue = calloc(1,sizeof(Queue));
	queue->noOfElements = 0;
	queue->head = NULL;
	return queue; 
}

int isEmpty(Queue* queue){
	return NULL == queue->head;
}
int enqueue(Queue *queue, int priority, void *data){
	Node* node = createNode(priority,data);
	Node* tempNode = queue->head;
	if(isEmpty(queue)){
		node->next = queue->head;
		queue->head = node;
		queue->noOfElements++;
		return 1;
	}
	if(node->priority >= queue->head->priority){
		node->next = queue->head;
		queue->head->previous = node;
		queue->head = node;
		queue->noOfElements++;
		return 1;
	}
	else{
		while(node->priority < tempNode->priority && tempNode->next !=NULL)
			tempNode = tempNode->next;
		node->previous = tempNode;
		node->next = tempNode->next;
	}
	queue->noOfElements++;
	return 1;
}

void* dequeue(Queue* queue){
    Node* poppedElement = queue->head;  
    if(isEmpty(queue)) return NULL;
    queue->head = queue->head->next;
    queue->noOfElements--;
    return poppedElement->data; //ask prakash how to free poppedElement
};

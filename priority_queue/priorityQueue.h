#include <stdlib.h>
typedef struct Node{
	void* data;
	int priority;
	struct Node* previous;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
	int noOfElements;
} Queue;

Queue* createQueue();
Node* createNode(int priority,void* data);
int enqueue(Queue* queue, int priority,void* data);
void* dequeue(Queue* Queue);
int isEmpty(Queue* queue);

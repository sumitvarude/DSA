#include "iterator.h"
typedef struct Node{
	void* data;
	struct Node* previous;
	struct Node* next;
} Node;
typedef struct {
	Node* head;
	int noOfElements;
} List;

typedef int (*Compare)(void* element1,void* element2);
List* createList();
int insertNode(List* list , int index , void* data);
Node* traverseTill(List* list,int index);
int search(List* list , void* element , Compare compare);
void dispose(List* list);
int removeElement(List* list, int index);
int getLength(List* list);

Iterator getIterator(List* list);
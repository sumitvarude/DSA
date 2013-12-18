#include <stdlib.h>
typedef struct Node{
	void* data;
	struct Node* previous;
	struct Node* next;
} Node;
typedef struct {
	Node* head;
	int noOfElements;
} List;

List* createList();
int insertAtStart(List* list,void* data);
int insertAtLast(List* list,void* data);
int insertAtMiddle(List* list,int index,void* data);

Node* traverseTill(List* list,int index);

int removeElement(List* list, int index);
int getLength(List* list);
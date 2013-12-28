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
int insertAtStart(List* list,void* data);
int insertAtLast(List* list,void* data);
int insertAtMiddle(List* list,int index,void* data);
int insertNode(List* list , int index , void* data);
Node* traverseTill(List* list,int index);
int search(List* list , void* element , Compare compare);

int removeElement(List* list, int index);
int getLength(List* list);
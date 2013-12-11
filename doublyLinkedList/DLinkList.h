typedef struct Node{
	void* data;
	struct Node* previous;
	struct Node* next;
} Node;
typedef struct {
	Node* head;
	Node* tail;
	int noOfElements;
} List;

List* createList();
int insert(List* list, int index, void* data);
int insertAtStart(List* list,Node* node,void* data);

int insertAtLast(List* list,Node* node,void* data);
int removeElement(List* list, int index);
int findIndex(List* list, void* data);
int getLength(List* list);
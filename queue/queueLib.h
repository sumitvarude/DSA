typedef struct {
	int rare;
	int length;
	int typeSize;	 
	void* elements;
}Queue;


Queue*	create(int typesize,int length);						
int	enQueue(Queue* queue,void* element);				
void* 	deQueue(Queue* queue);							

int   	isEmpty(Queue* queue);			
int 	isFull(Queue* queue);
void* 	givesRare(Queue* queue);

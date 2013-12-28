typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int (*Compare)(void* element1,void* element2);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);
int add(ArrayList *list,void* data);
int remove(ArrayList *list,int index);
int search(ArrayList *list,void* data,Compare compare);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);
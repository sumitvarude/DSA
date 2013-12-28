
typedef char String[256];

void* create( int length);
int push(void* stack,void* InsertElement);
void* pop(void* stack);
void* top(void* stack);
void dispose();
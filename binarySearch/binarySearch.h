#include <stdbool.h>
typedef char String[50];
typedef int compareFunction(void* a, void* b);
void* search(void* array,void* key,int length,int elementSize,compareFunction* compare);
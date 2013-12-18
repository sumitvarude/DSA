#include <stdbool.h>
typedef int compareFunction(void* key, void* element);
void* search(void* array,void* key,int length,int elementSize,compareFunction* compare);
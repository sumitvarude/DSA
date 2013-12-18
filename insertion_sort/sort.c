#include "sort.h"
#include <stdlib.h>
#include <string.h>
void sort(void* base, int length, int typeSize,compare comp) {
    int i, j,result;
    void *element,*temp = calloc(1, typeSize);

    for (i = 1; i < length; i++) {
    	memcpy(temp, base + (i * typeSize), typeSize);
    	for (j = i - 1; j >= 0; j--) {
    		element = base + j*typeSize;
    		result = comp(temp, element);
    		if (result >= 0) break; 
			memcpy(element + typeSize,element, typeSize);
		} 
    	memcpy(base + (j + 1)*typeSize, temp, typeSize); 					    	
    }
    free(temp);
}

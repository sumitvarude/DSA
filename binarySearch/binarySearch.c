#include "binarySearch.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void* search(void* array,void* key,int length,int elementSize,compareFunction* compare){
	int mid,result,start = 0;
	int end = length - 1;
	while(start <= end ){
		mid = (start+end)/2;
		result = compare(key,array+(mid*elementSize));
		if(result == 0)
 			return (array+(mid*elementSize));
		if(result < 0)
			end = mid-1;
		else 
			start = mid+1;
	}
	return 0; 
} 
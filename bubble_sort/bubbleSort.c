#include "bubbleSort.h"
#include <stdlib.h>
#include <memory.h>


void swap(void *element1,void *element2,int typeSize){
	void* temp = calloc(1,sizeof(void*)); 
	memcpy(temp,element1,typeSize);
	memcpy(element1,element2,typeSize);
	memcpy(element2,temp,typeSize);
}
void performSort(void* array, int noOfElements,int typeSize,Compare compare){
	int result,i = 0,index ;
	if(noOfElements == 1) return;
	for(index = 0;index < noOfElements; index++){
		for(i = index+1;i < noOfElements; i++){
			result = compare(array+(typeSize*index),array+(typeSize*(index+1)));
			if(result > 0)
				swap(array+index,array+(index+1),typeSize);
	
		}
		
	}
}

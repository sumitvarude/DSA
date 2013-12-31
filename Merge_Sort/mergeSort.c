#include "mergeSort.h"
#include <memory.h>
#include <stdlib.h>
int merge(void* destination, void* left, void* right, size_t leftLength, size_t rightLength,size_t typesize, CompareFunc cmp){
    int i=0,j=0,k=0;
    while(i < leftLength && j < rightLength){
        if(cmp(left+(i*typesize), right+(j*typesize))){
            memmove(destination+(k*typesize), left+(i*typesize), typesize);
            i++;
        }
        else{
            memmove(destination+(k*typesize), right+(j*typesize), typesize);
            j++;
        }
        k++;
    }
    while( j < rightLength){
        memmove(destination+(k*typesize), right+(j*typesize), typesize);
        j++;
        k++;
    }
    while(i < leftLength){
        memmove(destination+(k*typesize), left+(i*typesize), typesize);
        i++;
        k++;
    }
    return 1;
}

void performMergeSort(void* base, int numberOfElements, int typesize, CompareFunc comp){
    int mid = numberOfElements/2,i,j,leftLength,rightLength;
    void* left = calloc(mid,typesize);
    void* right = calloc((numberOfElements-mid),typesize);
    if(numberOfElements < 2) return;
    leftLength = mid;
    rightLength = numberOfElements-mid;
    for(i=0;i<mid;i++)
            memmove(left+i*typesize,base+i*typesize,typesize);
    for(i=mid;i<numberOfElements;i++)
            memmove(right+typesize*(i-mid),base+typesize*i,typesize);
    performMergeSort(left,leftLength,typesize,comp);
    performMergeSort(right,rightLength,typesize,comp);
    merge(base, left, right, leftLength, rightLength, typesize, comp);
    free(left);
    free(right);
}
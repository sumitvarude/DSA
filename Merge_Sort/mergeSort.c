#include "mergeSort.h"
#include <memory.h>
#include <stdlib.h>
int merge(void* destination, void* left, void* right, int lALength, int rALength,int typesize, CompareFunc cmp){
    int leftCounter = 0,rightCounter =0,k=0;
    while(leftCounter < lALength && rightCounter < rALength){
        if(cmp(left + (leftCounter * typesize), right + (rightCounter * typesize))){
            memmove(destination + (k * typesize), left + (leftCounter*typesize), typesize);
            leftCounter++;
        }
        else{
            memmove(destination + (k*typesize), right + (rightCounter*typesize), typesize);
            rightCounter++;
        }
        k++;
    }
    while( rightCounter < rALength){
        memmove(destination + (k*typesize), right + (rightCounter*typesize), typesize);
        rightCounter++;
        k++;
    }
    while(leftCounter < lALength){
        memmove(destination + (k*typesize), left + (leftCounter*typesize), typesize);
        leftCounter++;
        k++;
    }
    return 1;
}

void performMergeSort(void* base, int numberOfElements, int typesize, CompareFunc comp){
    int mid = numberOfElements/2,i,j,lALength,rALength;
    void* left = calloc(mid,typesize);
    void* right = calloc((numberOfElements-mid),typesize);
    if(numberOfElements < 2) return;
    lALength = mid;
    rALength = numberOfElements-mid;
    for(i = 0;i < mid; i++)
        memmove(left + (i*typesize),base + (i*typesize), typesize);
    for(i = mid;i < numberOfElements; i++)
        memmove(right + (typesize*(i-mid)),base + (typesize*i), typesize);
    performMergeSort(left, lALength, typesize, comp);
    performMergeSort(right, rALength, typesize, comp);
    merge(base, left, right, lALength, rALength, typesize, comp);
    free(left);
    free(right);
}
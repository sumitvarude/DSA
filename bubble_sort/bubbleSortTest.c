#include "testUtils.h"
#include "bubbleSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareInts(void *element1,void *element2){
	return (*(int*)element1)-(*(int*)element2);
}
int compareDoubles(void *element1,void *element2){
	return (*(double*)element1)-(*(double*)element2);
}
int compareFloats(void *element1,void *element2){
	return (*(double*)element1)-(*(double*)element2);
}
int compareChars(void *element1,void *element2){
	return (*(char*)element1)-(*(char*)element2);
}
int isSorted(void* array,int noOfElements,int typeSize,Compare compare){
	int index,result;
	for(index = 0;index < noOfElements;index++){
		result = compare(array+(typeSize*index),array+(typeSize*(index+1)));
		if(result > 0)
			return 0;
	}
	return 1;
}
void test_gives_one_if_array_is_sorted(){
	void *sortedArray;
	int data[] = {1,2,3};
	ASSERT(1 == isSorted(data, 2,sizeof(int), compareInts));	
}
void test_gives_zero_if_array_is_not_sorted(){
	void *sortedArray; 
	int data[] = {3,2,1};
	ASSERT(0 == isSorted(data, 2,sizeof(int), compareInts));	
}
void test_sorts_array_with_only_two_elements(){
	int data[] = {2,1};
	performSort(data, 2,sizeof(int),compareInts);
	ASSERT(0 == isSorted(data, 2,sizeof(int), compareInts));	
}
void test_sorts_array_with_multiple_elements(){
	int data[] = {10,4,9,9,2,3,5,1};
	performSort(data, 8,sizeof(int),compareInts);
	ASSERT(0 == isSorted(data, 8,sizeof(int), compareInts));	
}
void test_sorts_array_of_double_elements(){
	double data[] = {3.0,2.0,1.0};
	performSort(data, 3,sizeof(double), compareDoubles);
	ASSERT(0 == isSorted(data, 3,sizeof(double), compareDoubles));
}
void test_sorts_array_of_float_elements(){
	float data[] = {3.0,2.0,1.0};
	performSort(data, 3,sizeof(float), compareFloats);
	ASSERT(0 == isSorted(data, 3,sizeof(float), compareFloats));
}
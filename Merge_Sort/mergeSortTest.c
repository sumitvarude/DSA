#include "testUtils.h"
#include "mergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* prev, void* next){
        return *(int*)prev < *(int*)next;
}

int compareFloat (void* prev, void* next){
        return *(float*)prev <
         *(float*)next;
}

int compareChar (void* prev, void* next){
        return *(char*)prev < *(char*)next;
}

void test_sorts_integer_elements(){
    int count;
    int data[] = {6,5,8,4};
    performMergeSort(&data,4,sizeof(int),compareInt);
   	ASSERT(data[0]==4);
   	ASSERT(data[1]==5);
   	ASSERT(data[2]==6);
   	ASSERT(data[3]==8);
}

void test_sorts_integer_when_no_of_elements_is_odd(){
    int count;
    int data[] = {6,5,8,4,3};
    performMergeSort(&data,5,sizeof(int),compareInt);
    ASSERT(data[0]==3);
    ASSERT(data[1]==4);
   	ASSERT(data[2]==5);
   	ASSERT(data[3]==6);
   	ASSERT(data[4]==8);
}

void test_sorts_float_elements(){
    int count;
    float data[] = {6.0f,5.0f,8.0f,4.0f};
    float expected[] = {4.0f,5.0f,6.0f,8.0f};
    performMergeSort(&data,4,sizeof(float),compareFloat);
        ASSERT(data[0]==expected[0]);
        ASSERT(data[1]==expected[1]);
        ASSERT(data[2]==expected[2]);
        ASSERT(data[3]==expected[3]);
}

void test_sorts_characters(){
    char arr[] = {'e','d','c','b','a'};
    performMergeSort(arr, 5, sizeof(char), compareChar );
    ASSERT(arr[0] == 'a');
    ASSERT(arr[1] == 'b');
    ASSERT(arr[2] == 'c');
    ASSERT(arr[3] == 'd');
    ASSERT(arr[4] == 'e');
}




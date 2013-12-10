#include "testUtils.h"
#include "binarySearch.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble (void* a, void* b){
    return (*(double*)a - *(double*)b);
}
int compareString(void *a, void *b){ 
         return (strcmp(*(String*)a,*(String*)b));
}
int compareChar(void* a, void* b){
        return (*(char*)a - *(char*)b);
}
void test_searches_element_from_char_array(){
    char values[5] = {'p','q','r','s','t'};
    char key = 'q';
    char* result = search(values,&key, 5, sizeof(char), compareChar);
    ASSERT('q' == *result);
    ASSERT(&values[1] == result);
};
void test_give_null_if_the_element_is_not_present_in_array_for_char(){
    char values[5] = {'p','q','r','s','t'};
    char key = 'k';
    char* result = search(values,&key, 5, sizeof(char), compareChar);
    ASSERT(NULL == (char*)result);
};

void test_gives_first_occurance_if_same_values_are_present(){
    char values[2] = {'p','p'};
    char key = 'p';
    char* result = search(values,&key, 2, sizeof(char), compareChar);
    ASSERT('p' == *result);
    ASSERT(&values[0] == result);
};

void test_searches_element_from_integer_array(){
    int values[5] = {1,2,3,4,5};
    int key = 3;
    int* result = search(values,&key, 5, sizeof(int), compareInt);
    ASSERT(3 == *result);
    ASSERT(&values[2] == result);
};
void test_give_null_if_the_element_is_not_present_in_array_for_integer(){
    int values[5] = {1,2,3,4,5};
    int key = 83;
    int* result = search(values,&key, 5, sizeof(int), compareInt);
    ASSERT((int*)result == NULL);
};
void test_search_element_from_the_float_array(){
    float values[5] = {1.0,2.0,3.0,4.0,5.0};
    float key = 4.0;
    float* result = search(values,&key, 5, sizeof(float), compareInt);
    ASSERT(4.0 == *result);
    ASSERT(&values[3] == result);
};
void test_give_null_if_the_element_is_not_present_in_array_for_float(){
    float values[5] = {1.0,2.0,3.0,4.0,5.0};
    float key = 9.0;
    float* result = search(values,&key, 5, sizeof(float), compareInt);
    ASSERT(NULL == (float*)result);
};
void test_search_element_from_array_of_doubles(){
    double values[5] = {1.0,2.0,3.0,4.0,5.0};
    double key = 3.0;
    double* result = search(values,&key, 5, sizeof(double), compareDouble);
    ASSERT(3.0 == *result);
    ASSERT(&values[2] == result);
};
void test_search_element_from_array_of_strings(){
    String values[3] = {"a","b","c"};
    String key;
    String* result;
    strcpy(key, "b");
    result = search(values,&key, 3, sizeof(String), compareString);
    ASSERT(!(strcmp("b",*result)));
    ASSERT(&values[1] == result);
};

void test_give_null_if_the_element_is_not_present_in_array_for_strings(){
    String values[3] = {"abc","def","ghi"};
    String key = "pqr";
    String* result = search(values,&key, 3, sizeof(String), compareString);
    ASSERT(NULL == (String*)result);
};
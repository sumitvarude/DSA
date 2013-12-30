#include <stdlib.h>

#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;
	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);
	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));
	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}

void test_add_element_at_end_of_arrayList() {
	int result = add(internsPtr,&prateek);
	ASSERT(result == SUCCESS);
}

void test_removes_element_from_given_index(){
	int result, index = 0;
	add(internsPtr,&prateek);
	result = remove(internsPtr,index);
	ASSERT(result == SUCCESS);
}
void test_should_not_remove_element_from_empty_array(){
	int result;
	result = remove(internsPtr,0);
	ASSERT(result == FAILURE);
}
int compareID(void* element1,void* element2){
	return (*(Intern*)element1).id - (*(Intern*)element2).id;
}
void test_gives_index_of_element_if_found(){
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(1 == search(internsPtr,&ji,compareID));
}
void test_gives_minus_1_if_arrayList_is_empty(){
	ASSERT(-1 == search(internsPtr,&ji,compareID));
}
void test_gives_minus_1_if_not_found(){
	insert(internsPtr, 0, &prateek);
	ASSERT(-1 == search(internsPtr,&ji,compareID));
}
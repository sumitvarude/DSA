#include "testUtils.h"
#include "DLinkList.h"
#include <stdlib.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_insert_a_node_of___INT___type_AT_START(){
	int result;
	List* list = createList();
	int element = 3;
	insertNode(list, 0,&element);
	ASSERT(removeElement(list, 0));
}

void test_2_insert_a_node_of___INT___type_AT_LAST(){
	int result;
	List* list = createList();
	int element = 3;
	insertNode(list, 0,&element);
	result = insertNode(list,1,&element);
	ASSERT(result == 1);
	ASSERT(removeElement(list, 0));
	ASSERT(removeElement(list, 1));
}

void test_3_insert_a_node_of___FLOAT___type_AT_START(){
	int result;
	List* list = createList();
	float element = 3.3;
	result = insertNode(list,0,&element);
	ASSERT(result == 1);
	ASSERT(removeElement(list, 0));
}

void test_4_insert_a_node_of___FLOAT___type_AT_LAST(){
	int result;
	List* list = createList();
	float element = 3.3;
	result = insertNode(list,0,&element);
	result = insertNode(list,1,&element);
	ASSERT(result == 1);
	ASSERT(removeElement(list, 0));
	ASSERT(removeElement(list, 1));
}

void test_5_insert_a_node_of___DOUBLE___type_AT_START(){
	int result;
	List* list = createList();
	double element = 3.6;
	result = insertNode(list, 0,&element);
	ASSERT(result == 1);
	ASSERT(removeElement(list, 0));
}

void test_6_insert_a_node_of___DOUBLE___type_AT_LAST(){
	int result;
	List* list = createList();
	double element = 3.6;
	result = insertNode(list, 0,&element);
	result = insertNode(list, 1,&element);
	ASSERT(result == 1);
	ASSERT(removeElement(list, 0));
	ASSERT(removeElement(list, 1));
}

void test_7_insert_a_node_of___CHAR___type_AT_START(){
	int result;
	List* list = createList();
	char *element = malloc(sizeof(char));
	*element = 'a';
	result = insertNode(list, 0,&element);
	ASSERT(result == 1);
	ASSERT(removeElement(list, 0));
	free(element);
}

void test_8_inserts_a_node_of___INT___type_at_THIRD_position(){
	int result;
	Node* thirdNode = calloc(1,sizeof(Node)); 
	List* list = createList();
	int first = 1, second = 2, third = 3, forth = 4;
	insertNode(list, 0,&first);
	insertNode(list, 1,&second);
	insertNode(list,2, &forth);
	result = insertNode(list,3, &third);
	thirdNode = traverseTill(list,4);
	ASSERT(result == 1);
	ASSERT(3==*(int*)thirdNode->data);
}

void test_9_inserts_a_node_of___FLOAT___type_at_THIRD_position(){
	int result;
	Node* thirdNode = calloc(1,sizeof(Node)); 
	List* list = createList();
	double first = 1.0, second = 2.0, third = 3.0, forth = 4.0;
	insertNode(list, 0,&first);
	insertNode(list, 1,&second);
	insertNode(list, 2,&forth);
	result = insertNode(list,3, &third);
	thirdNode = traverseTill(list,4);
	ASSERT(result == 1);
	ASSERT(3.0==*(double*)thirdNode->data);
}
void test_10_inserts_a_node_of___CHAR___type_at_THIRD_position(){
	int result;
	Node* thirdNode = calloc(1,sizeof(Node)); 
	List* list = createList();
	char array[]={'a','b','c','d'};
	insertNode(list, 0,&array[0]);
	insertNode(list, 1,&array[1]);
	insertNode(list, 2,&array[3]);
	result = insertNode(list,2, &array[2]);
	thirdNode = traverseTill(list,3);
	ASSERT(result == 1);
	ASSERT('c'==*(char*)thirdNode->data);
}

void test_11_gives_length_of_given_list(){
	List* list = createList();
	list->noOfElements = 10;
	ASSERT(10 == getLength(list));
}
 
void test_12_removes_a_node_of___CHAR___type_at_THIRD_position(){
	List* list = createList();
	Node* node = calloc(1,sizeof(Node));
	int one = 1,two = 2,three = 3;
	insertNode(list, 0,&one);
	insertNode(list, 1,&two);
	insertNode(list, 2,&three);
	node = traverseTill(list,3);
	ASSERT(node->next == NULL);
	ASSERT(removeElement(list,2));
}
int compareIntData(void* element1 , void* element2){
        return *(int*)element1 - *(int*)element2;
}
void test_13_search_data_in_given_list_return_index(){
        List* list = createList();
        int data[] = {100,200,300,400};

        insertNode(list,0,&data[0]);
        insertNode(list,1,&data[1]);
        insertNode(list,2,&data[2]);

        ASSERT(1 == search(list, &data[1], compareIntData));
}
void test_14_search_data_in_empty_list_return_minus_one(){
        List* list = createList();
        int data = 10;
        ASSERT(-1 == search(list, &data, compareIntData));
}
void test_15_search_gives_minus_one_if_data_not_found(){
        List* list = createList();
        int data[] = {100,200,300,400};
        int element = 10;
        insertNode(list,0,&data[0]);
        insertNode(list,1,&data[1]);
        insertNode(list,2,&data[2]);
        ASSERT(-1 == search(list, &element, compareIntData));
}
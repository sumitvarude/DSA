#include "testUtils.h"
#include "DLinkList.h"
#include <stdlib.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_create_a_linked_list(){
	List* list = malloc(sizeof(Node));
	list = createList();
	ASSERT(list->head == NULL);
	ASSERT(0 == list->noOfElements);
}

void test_2_insert_a_node_of___INT___type_AT_START(){
	int result;
	List* list = createList();
	int element = 3;
	result = insertAtStart(list,&element);
	ASSERT(result == 1);
	ASSERT(*(int*)list->head->data == 3);
	ASSERT(list->noOfElements == 1);
}

void test_3_insert_a_node_of___INT___type_AT_LAST(){
	int result;
	List* list = createList();
	int element = 3;
	insertAtStart(list, &element);
	result = insertAtLast(list, &element);
	ASSERT(result == 1);
	ASSERT(list->noOfElements == 2);
}

void test_4_insert_a_node_of___FLOAT___type_AT_START(){
	int result;
	List* list = createList();
	float element = 3.3;
	result = insertAtStart(list, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->noOfElements == 1);
}

void test_5_insert_a_node_of___FLOAT___type_AT_LAST(){
	int result;
	List* list = createList();
	float element = 3.3;
	result = insertAtStart(list, &element);
	result = insertAtLast(list, &element);
	ASSERT(result == 1);
	ASSERT(list->noOfElements == 2);
}

void test_6_insert_a_node_of___DOUBLE___type_AT_START(){
	int result;
	List* list = createList();
	double element = 3.6;
	result = insertAtStart(list, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->noOfElements == 1);
}

void test_7_insert_a_node_of___DOUBLE___type_AT_LAST(){
	int result;
	List* list = createList();
	double element = 3.6;
	result = insertAtStart(list, &element);
	result = insertAtLast(list, &element);
	ASSERT(result == 1);
	ASSERT(list->noOfElements == 2);
}

void test_8_insert_a_node_of___CHAR___type_AT_START(){
	int result;
	List* list = createList();
	char *element = malloc(sizeof(char));
	*element = 'a';
	result = insertAtStart(list, &element);
	ASSERT(result == 1);
	ASSERT(list->head->data == &element);
	ASSERT(list->noOfElements == 1);
	free(element);
}

void test_9_inserts_a_node_of___INT___type_at_THIRD_position(){
	int result;
	Node* thirdNode = calloc(1,sizeof(Node)); 
	List* list = createList();
	int first = 1, second = 2, third = 3, forth = 4;
	insertAtStart(list, &first);
	insertAtLast(list, &second);
	insertAtLast(list, &forth);
	result = insertAtMiddle(list,3, &third);
	thirdNode = traverseTill(list,4);
	ASSERT(result == 1);
	ASSERT(3==*(int*)thirdNode->data);
}

void test_10_inserts_a_node_of___FLOAT___type_at_THIRD_position(){
	int result;
	Node* thirdNode = calloc(1,sizeof(Node)); 
	List* list = createList();
	double first = 1.0, second = 2.0, third = 3.0, forth = 4.0;
	insertAtStart(list, &first);
	insertAtLast(list, &second);
	insertAtLast(list, &forth);
	result = insertAtMiddle(list,3, &third);
	thirdNode = traverseTill(list,4);
	ASSERT(result == 1);
	ASSERT(3.0==*(double*)thirdNode->data);
}
void test_11_inserts_a_node_of___CHAR___type_at_THIRD_position(){
	int result;
	Node* thirdNode = calloc(1,sizeof(Node)); 
	List* list = createList();
	char array[]={'a','b','c','d'};
	insertAtStart(list, &array[0]);
	insertAtLast(list, &array[1]);
	insertAtLast(list, &array[3]);
	result = insertAtMiddle(list,3, &array[2]);
	thirdNode = traverseTill(list,4);
	ASSERT(result == 1);
	ASSERT('c'==*(char*)thirdNode->data);
}

void test_12_gives_length_of_given_list(){
	List* list = createList();
	list->noOfElements = 10;
	ASSERT(10 == getLength(list));
}
 
void test_13_removes_a_node_of___CHAR___type_at_THIRD_position(){
	List* list = createList();
	Node* node = calloc(1,sizeof(Node));
	int one = 1,two = 2,three = 3;
	insertAtStart(list, &one);
	insertAtLast(list, &two);
	insertAtLast(list, &three);
	node = traverseTill(list,3);
	ASSERT(node->next == NULL);
	ASSERT(removeElement(list,2));
}
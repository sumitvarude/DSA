#include "testUtils.h"
#include "DLinkList.h"
#include <stdlib.h>
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_a_linked_list(){
	List* first = malloc(sizeof(Node));
	first = createList();
	ASSERT(0 == first->noOfElements);
}
void test_inserts_element_at_start(){
	int data = 2;
	List* first = calloc(1,sizeof(List));
	Node* node = calloc(1,sizeof(Node));
	first = createList();
	insertAtStart(first,node,&data);	
	ASSERT(2 == *(int*)(first->head->data));
	
}

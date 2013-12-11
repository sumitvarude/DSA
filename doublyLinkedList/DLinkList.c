#include "DLinkList.h"
#include <stdio.h>
#include <stdlib.h>

List* createList(){
	List* first = calloc(1,sizeof(List));
	first->noOfElements = 0;
	first->head = NULL;
	first->tail = NULL;
	return first; 
}

int insertAtStart(List* list,Node* node,void* data){
	node->data = data;
	node->next = list->head;
	list->head = node;
	list->noOfElements++;
	return 1;
}
 
int insertAtLast(List* list,Node* node,void* data){
	node->data = data;
	node->next = list->tail;
	list->tail = node;
	list->noOfElements++;
	return 1;
}

int insert(List* list, int index, void* data){
	Node* node;
	int validIndex = index >= 0 && index <= list->noOfElements;
	if(!validIndex)
		return 0;
	node = calloc(1, sizeof(Node));
	if(index == 0)
		insertAtStart(list,node, data);
	if(index == list->noOfElements)
		insertAtLast(list, node, data);
	if(index > 0 && index < list->noOfElements)
		return 0 ;
	return 1;
}
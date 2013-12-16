#include "DLinkList.h"
#include <stdio.h>
#include <stdlib.h>

Node* traverseTill(List* list,int index){
	int i=1;
	Node* currentNode = list->head;
	while(i!=index){
		currentNode=currentNode->next;
		i++;
	}
	return currentNode;
};

List* createList(){
	List* first = calloc(1,sizeof(List));
	first->noOfElements = 0;
	first->head = NULL;
	return first; 
}

int insertAtStart(List* list,void* data){
	Node* node;
	node = calloc(1,sizeof(Node));
	node->data = data;
	node->next = list->head;
	list->head = node;
	list->noOfElements++;
	return 1;
}
 
int insertAtLast(List* list,void* data){
	Node* tempNode;
	Node* node;
	node = calloc(1,sizeof(Node));
	tempNode = traverseTill(list,list->noOfElements);
	node->data = data;
	node->previous = tempNode;
	tempNode->next = node;
	list->noOfElements++;
	return 1;
}
int insertAtMiddle(List* list,int index,void* data){
	Node* node;
	int i,lengthOfList;
	Node* currentNode = list->head;
	Node* tempNode = calloc(1,sizeof(Node));
	lengthOfList = list->noOfElements;
	node = calloc(1,sizeof(Node));
	for(i=1;i<=index;i++){
		if(i==index){
			tempNode = currentNode->next;
			currentNode->next = node;
			node->data = data;
			node->previous = currentNode;
			node->next = tempNode;
			list->noOfElements++;
		}
		currentNode = currentNode->next;			
	}
	return 1;
};

int getLength(List* list){
	return list->noOfElements;
}

int removeElement(List* list, int index){
	Node* nodeToRemove;
	Node* previousNode;
	if(index == 0){
		list->head = list->head->next;
		list->noOfElements--;
		return 1;
	}
	nodeToRemove = traverseTill(list,index);
	previousNode = traverseTill(list,index);
	previousNode->next = NULL;
	list->noOfElements--;
	free(nodeToRemove);
	return 1;
}

// int insert(List* list, int index, void* data){
// 	Node* node;
// 	node = calloc(1,sizeof(Node));
// 	printf("index:%d",index);
// 	printf("list->noOfElements:%d",list->noOfElements);
// 	if(index == 0){
// 		printf("aa gaya1");
// 		return insertAtStart(list,node, data);
// 	}
// 	if(index == list->noOfElements){
// 		printf("aa gaya2");
// 		return insertAtLast(list,node, data);
// 	}
// 	if((index > 0 && index < list->noOfElements)|| ){
// 		printf("aa gaya3");
// 		return insertAtMiddle(list, node, index, data);
// 	}
// 	return 0;
// }
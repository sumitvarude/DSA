#include "DLinkList.h"
#include <stdio.h>
#include <stdlib.h>

Node* traverseTill(List* list,int index){
	int i=1;
	Node* currentNode = list->head;
	while(i!=index && currentNode!=NULL){
		currentNode = currentNode->next;
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
int insertNode(List* list , int index , void* data){
        if (index > list->noOfElements) return 0;
        if (index == 0)        insertAtStart(list, data);
        else if(index == list->noOfElements)        insertAtLast(list,data);
        else insertAtMiddle(list, index, data);
        return 1;
};
int getLength(List* list){
	return list->noOfElements;
}
int search(List* list , void* element , Compare compare){
        Node* node;
        int index= 0;
        if(0 == list->noOfElements) return -1;
        node = list->head;
        while(node->next != NULL){
                if (!compare(element , node->data)) return index;
                index++;
                node = node->next;
        }
        return -1;
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
int hasCurrent(Iterator* it){
	return ((Node*)(it->current)) != NULL;
};

void* current(Iterator* it){
	void* result = NULL;
	if(it->hasNext(it)){
		result = ((Node*)(it->current))->data;
		it->current = ((Node*)(it->current))->next;
	}
	return result;
};

Iterator getIterator(List* list){
	Iterator it;
	if(list==NULL) it.current = NULL;
	else it.current = list->head;
	it.list = list;
	it.hasNext = hasCurrent;
	it.next = current;
	return it;
};

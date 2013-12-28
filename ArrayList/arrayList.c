#include "arrayList.h"
#include <stdlib.h>

ArrayList create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
	}	
}

int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}
int isvalid(ArrayList *list,int index){
	return !(list->length == 0 || (index < 0 || index > list->length));
}
int insert(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;

	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);

	list->base[index] = data;
	list->length++;

	return 1;
}
int add(ArrayList *list,void* data){
	if(list == NULL) return 0;
	increaseCapacity(list);
	insert(list,list->length,data);
	return 1;
}

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;

	return list->base[index];
}

void dispose(ArrayList *list) {
	free(list->base);
}

int remove(ArrayList *list,int index){
	int i;
	if(isvalid(list, index)){
		for(i = index;i< list->length ; i++){
			list->base[i] = list->base[i+1];
		}
		list->length--;
		return 1;
	}
	return 0;
}
int search(ArrayList *list,void* data,Compare compare){
	int index;
	if(!list) return -1;
	for(index = 0; index < list->length; index++){
		if(0 == compare(list->base[index] , data)) return index;
	}
	return -1;
}

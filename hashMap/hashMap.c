#include "hashMap.h"
#include <stdlib.h>


HashMap* createHashMap(HashFunc hashFunc, CompareFunc compare){
        int i;
        HashMap* map = calloc(1, sizeof(HashMap));
        map->buckets = calloc(10, sizeof(List));
        for(i=0;i<10;i++)  map->buckets[i] = createList();
        map->noOfBuckets = 10;
        map->hashFunc = hashFunc;
        map->compare = compare;
        return map;
};
Node* createNode(void* data){
	Node* node = calloc(1, sizeof(Node));
	node->next = NULL;
	node->previous = NULL;
	node->data = data;
	return node;
}
HashElement* createElement(void *key, void *value){
	HashElement* element = calloc(1, sizeof(HashElement));
	element->key = key;
	element->value = value;
	return element;
}
int put(HashMap *map, void *key, void *value){
	int abc=0;
	HashElement* element = createElement(key, value);
	Node* node = createNode(element);
    int bucketNumber = map->hashFunc(key) % 10;
	List* list = (List*)(map->buckets[bucketNumber]);
	abc = insertNode(list, list->noOfElements,element);
	return abc;
}


int searchData(HashMap* map , void* key){
    int bucketNumber = map->hashFunc(key) % 10;
	List* list = (List*)(map->buckets[bucketNumber]);
	return search(list, key,map->compare);
}
void* get(HashMap *map, void *key){
	Node* node;
	HashElement* element;
	int index,bucketNumber = map->hashFunc(key) % 10;
	List* list = (List*)(map->buckets[bucketNumber]);
	if(0 == list->noOfElements) return NULL;
	node = list->head;
	for(index = 0;index < list->noOfElements; index++){
		element = node->data;
		if(!map->compare(key, element->key)) return element;
		node = node->next;
	}
	return NULL;
}
int getIndexInBucket(HashMap* map ,void* key ,List* list){
	HashElement* element;
	int index = 1 ;
	Node* node = list->head;
	do{
		element = node->data;
		if (!map->compare(key ,element->key)) return index;
		node = node->next;
		index++;
	}while(node->next != NULL);
	return index;
}
void* removeHashElement(HashMap *map, void *key){
	void* hashElement = get(map, key);
	int index ,bucketNumber = map->hashFunc(key) % 10;
	List* list = (List*)(map->buckets[bucketNumber]);
	index = getIndexInBucket( map ,key ,list);
	removeElement(list,index);
	return hashElement;
}
Iterator getKeys(HashMap *map){
	int i;
	HashElement* element;
	List *tempList = createList();
	List *list = createList();
	Iterator it;
	for(i = 0;i < map->noOfBuckets; i++){
		list = (List*)map->buckets[i];
		if(tempList->head != NULL){
			it = getIterator(list);
			while(it.hasNext(&it)){
				element = (HashElement*)it.next(&it);
				insertNode(tempList, tempList->noOfElements, element->key);				
			}			
		}
	}
	it = getIterator(tempList);
	return it;
}

// dispose(HashMap *map)
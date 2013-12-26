#include "hashmap.h"
#include <stdlib.h>

const int capasity = 10;
HashMap* create(HashFunc hashFunc, CompareFunc compare){
	HashMap* map = calloc(1, sizeof(HashMap));
	map->buckets = calloc(1, sizeof(List) * capasity);
	map->noOfBuckets = capasity;
	map->hashFunc = hashFunc;
	map->compare = compare;
	return map;
}
Node* createNode(void* data){
	Node* node = calloc(1, sizeof(Node));
	node->next = NULL;
	node->previous = NULL;
	node->data = data;
	return node;
}
Data* getData(void *key, void *value){
	Data* data = calloc(1, sizeof(Data));
	data->key =key;
	data->value = value;
	return data;
}
int put(HashMap *map, void *key, void *value){
	Data* data = getData(key, value);
	Node* node = createNode(data);
    int bucketNumber = map->hashFunc(key) % capasity;
	List* list = (List*)(map->buckets+(sizeof(List)*bucketNumber));
	return insertNode(list, list->noOfElements,data);
}
void dispose(HashMap *map){
	free(map->buckets);
	free(map);
}

int searchData(HashMap* map , void* key){
    int bucketNumber = map->hashFunc(key) % capasity;
	List* list = (List*)(map->buckets+(sizeof(List)*bucketNumber));
	return search(list, key,map->compare);
}
void* get(HashMap *map, void *key){
	Node* node;
	Data* data;
	int bucketNumber = map->hashFunc(key) % capasity;
	List* list = (List*)(map->buckets+(sizeof(List)*bucketNumber));
	if(0 == list->noOfElements) return NULL;
	node = list->head;
	do{
		data = node->data;
		if (!map->compare(key ,data->key)) return data;
		node = node->next;
	}while(node->next != NULL);
	return NULL;
}
int getIndexInBucket(HashMap* map ,void* key ,List* list){
	Data* data;
	int index = 1 ;
	Node* node = list->head;
	do{
		data = node->data;
		if (!map->compare(key ,data->key)) return index;
		node = node->next;
		index++;
	}while(node->next != NULL);
	return index;
}
void* remove(HashMap *map, void *key){
	void* data = get(map, key);
	int index ,bucketNumber = map->hashFunc(key) % capasity;
	List* list = (List*)(map->buckets+(sizeof(List)*bucketNumber));
	index = getIndexInBucket( map ,key ,list);
	removeElement(list,index);
	return data;
}
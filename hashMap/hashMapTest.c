#include "testUtils.h"
#include "hashmap.h"
#include "../customTypes.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeyEqual(void* key1 , void* key2 ){
	return *(int*)key1 - *(int*)key2;
}
int areKeyEqual1(void* key1 , void* key2 ){
	return *(String*)key1 - *(String*)key2;
}
int hashFun(void *key){
        return *(int*)key;
};

void test_add_an_element_to_hashmap(){
	int key = 10;
	char* value ="sumit";
	HashMap* map = create(hashFun, areKeyEqual);
	ASSERT(put(map, &key , &value));
	ASSERT(searchData(map,&key));
}
void test_add_an_element_to_hashmap1(){
	String key="intern" , value ="sumit";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	ASSERT(searchData(map,&key));
	// ldispose(map);
}
void test_add_an_element_to_hashmap2(){
	int key1 = 10,key = 20;
	char* value ="suraj";
	HashMap* map = create(hashFun, areKeyEqual);
	ASSERT(put(map, &key1 , &value));
	ASSERT(put(map, &key , &value));
	ASSERT(searchData(map,&key1));
	ASSERT(searchData(map,&key));
}
void test_gets_an_element_from_hashmap(){
	HashElement* element;
	String key = "intern" , value ="suraj";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	element = get(map, &key);
	ASSERT(&key == element->key);
	ASSERT(&value == element->value);
}

void test_gets_another_element_from_hashmap(){
	HashElement *element1,*element2;
	String key1 = "intern1" , value1 ="suraj";
	String key2 = "intern2" , value2 ="sumit";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key1 , &value1));
	ASSERT(put(map, &key2 , &value2));

	element1 = get(map, &key1);
	element2 = get(map, &key2);

	ASSERT(&key1 == element1->key);
	ASSERT(&value1 == element1->value);
	ASSERT(&key2 == element2->key);
	ASSERT(&value2 == element2->value);
}
void test_removes_an_element_from_hashmap(){
	HashElement* element;
	String key="intern" , value ="sumit";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	element =remove(map, &key);
	ASSERT(&key == element->key);
	ASSERT(&value == element->value);
	ASSERT(-1 == searchData(map,&key));
}

void test_removes_two_elements_from_hashmap(){
	HashElement *element1,*element2;
	String key1="intern1" , value1 ="sumit";
	String key2 = "pm" , value2 ="suraj";	
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key1 , &value1));
	ASSERT(put(map, &key2 , &value2));

	element1 = remove(map, &key1);
	element2 = remove(map, &key2);
	ASSERT(&key1 == element1->key);
	ASSERT(&value1 == element1->value);
	ASSERT(&key2 == element2->key);
	ASSERT(&value2 == element2->value); 
	ASSERT(-1 == searchData(map,&key1));
	ASSERT(-1 == searchData(map,&key2));
}
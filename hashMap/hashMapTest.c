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
	Data* data;
	String key = "intern" , value ="suraj";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	data = get(map, &key);
	ASSERT(&key == data->key);
	ASSERT(&value == data->value);
}

void test_gets_another_element_from_hashmap(){
	Data *data1,*data2;
	String key1 = "intern1" , value1 ="suraj";
	String key2 = "intern2" , value2 ="sumit";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key1 , &value1));
	ASSERT(put(map, &key2 , &value2));

	data1 = get(map, &key1);
	data2 = get(map, &key2);

	ASSERT(&key1 == data1->key);
	ASSERT(&value1 == data1->value);
	ASSERT(&key2 == data2->key);
	ASSERT(&value2 == data2->value);
}
void test_removes_an_element_from_hashmap(){
	Data* data;
	String key="intern" , value ="sumit";
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key , &value));
	data =remove(map, &key);
	ASSERT(&key == data->key);
	ASSERT(&value == data->value);
	ASSERT(-1 == searchData(map,&key));

}

void test_removes_two_elements_from_hashmap(){
	Data *data1,*data2;
	String key1="intern1" , value1 ="sumit";
	String key2 = "pm" , value2 ="suraj";	
	HashMap* map = create(hashFun, areKeyEqual1);
	ASSERT(put(map, &key1 , &value1));
	ASSERT(put(map, &key2 , &value2));

	data1 = remove(map, &key1);
	data2 = remove(map, &key2);
	ASSERT(&key1 == data1->key);
	ASSERT(&value1 == data1->value);
	ASSERT(&key2 == data2->key);
	ASSERT(&value2 == data2->value); 
	ASSERT(-1 == searchData(map,&key1));
	ASSERT(-1 == searchData(map,&key2));
}
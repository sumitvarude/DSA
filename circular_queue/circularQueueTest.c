#include "testUtils.h"
#include "circularQueue.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Queue* expected, Queue* actual){
	int result = expected->length == actual->length && expected->typeSize == actual->typeSize;
	if(!result) return result;
	return 0 == memcmp(expected->elements,actual->elements,actual->typeSize);
};

void test_Creates_queue_of_5_integer_elements_1(){
	int array[]={0,0,0,0,0};
	Queue* actual =create(sizeof(int),5);      
	Queue expected = {-1,-1,sizeof(int),5,array};      
	ASSERT(areEqual(&expected,actual));
};
void test_Creates_queue_of_5_char_elements_1(){
	char array[]={0,0,0,0,0};
	Queue* actual =create(sizeof(char),5);      
	Queue expected = {-1,-1,sizeof(char),5,array};      
	ASSERT(areEqual(&expected,actual));
};
void test_Creates_queue_of_5_float_elements_1(){
	char array[]={0,0,0,0,0};
	Queue* actual =create(sizeof(float),5);      
	Queue expected = {-1,-1,sizeof(float),5,array};      
	ASSERT(areEqual(&expected,actual));
};
void test_inserts_8_in_queue(){
	Queue *dequeued,*queue = create(sizeof(int), 5);
	int array[] = {8,0,0,0,0};
	int c = 8; 
	Queue expected = {-1,0,sizeof(int),5,array};     
	ASSERT(enqueue(queue,&c));
	ASSERT(areEqual(&expected,queue));
	ASSERT(dequeue(queue));
};
void test_enqueue_overwrites_after_queue_is_full(){
	int c = 4,e=5; 
	int* result;
   	Queue* queue=create(sizeof(int),5);
	queue->end=4;
	queue->start=3;
	ASSERT(enqueue(queue,&c));
	ASSERT(enqueue(queue,&c));
	ASSERT(enqueue(queue,&c));
};
void test_insert_element_to_first_position_in_queue_if_queue_is_full(){
	Queue* queue = create(sizeof(int),5);
	int c = 5; 
	queue->end=4;
	ASSERT(!enqueue(queue,&c));
};

void test_removes_element_from_the_rear_of_Queue(){
	Queue* queue=create(sizeof(int),5);
	int c = 4,e=5; 
	int* result;
   	ASSERT(enqueue(queue,&c));
   	ASSERT(enqueue(queue,&e));
	result = dequeue(queue);
	ASSERT(*result == 4);
	ASSERT(0 == queue->start);
};

void test_gives_null_if_queue_is_empty(){
	Queue* queue=create(sizeof(int),5);
	ASSERT(NULL==dequeue(queue));
}; 

void test_checks_whether_the_queue_is_empty(){
	Queue* queue = create(sizeof(int), 5);
	ASSERT(isEmpty(queue));
};

void test_checks_whether_the_queue_is_not_empty(){
	Queue* queue = create(sizeof(int),5);
	int a = 5; 
	ASSERT(enqueue(queue,&a));
	ASSERT(0==isEmpty(queue));
};

void test_checks_whether_the_queue_is_full(){
	Queue* queue = create(sizeof(int), 3);
	int a = 3,b = 4,c = 5;
	enqueue(queue,&a);	
	enqueue(queue,&b);	
	enqueue(queue,&c);	
	ASSERT(isFull(queue));
};


void test_checks_whether_the_queue_is_not_full(){
	Queue* queue = create(sizeof(int),5);
	ASSERT(!isFull(queue));
};

void test_gives_element_at_rear_of_queue(){
	Queue* queue = create(sizeof(int),5);
	int a = 5,b = 6,c = 7; 
	int* rearElemenet;
	ASSERT(enqueue(queue,&a));
	ASSERT(enqueue(queue,&b));
	ASSERT(enqueue(queue,&c));
	rearElemenet =givesRear(queue);
	ASSERT(7==*rearElemenet);
};

void test_gives_rear_as_null_if_queue_is_empty(){
	Queue* queue = create(sizeof(int),5);
	ASSERT(NULL ==givesRear(queue));
};
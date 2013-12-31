#include "testUtils.h"
#include "priorityQueue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_weather_the_quetue_is_empty(){
	Queue* queue = createQueue();
	ASSERT(1 == isEmpty(queue));
}

void test_inserts_element_in_queue(){
	Queue* queue = createQueue();
	int result,element = 1;
	result = enqueue(queue,6,&element);
	ASSERT(0 == isEmpty(queue));
	ASSERT(1 == result);
}
void test_inserts_2nd_element_in_queue(){
	Queue* queue = createQueue();
	int result,one = 1,two = 2;
	enqueue(queue,6,&one);
	result = enqueue(queue,3,&two);
	ASSERT(0 == isEmpty(queue));
	ASSERT(1 == result);
	ASSERT(2 == queue->noOfElements);
}
void test_removes_element_from_queue(){
	Queue* queue = createQueue();
	int result,one = 1,two = 2;
	enqueue(queue,6,&one);
	enqueue(queue,3,&two);
	result = *(int*)dequeue(queue);
	ASSERT(1 == result);
	ASSERT(1 == queue->noOfElements);
}

void test_removes_element_from_queue_and_checks_if_queue_is_empty(){
	Queue* queue = createQueue();
	int result,one = 1,two = 2;
	enqueue(queue,6,&one);
	ASSERT(&one == dequeue(queue));
	ASSERT(0 == queue->noOfElements);
}
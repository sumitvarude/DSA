#include "testUtils.h"
#include "queueLib.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

#include "testUtils.h"
#include "string.h"

typedef char string[256];
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areEqual(Queue* expected, Queue* actual){
	int result = (expected->length == actual->length) ;
	if(!result) return result;

	return 0 == memcmp(expected->elements,actual->elements,actual->length*actual->typeSize);
}

void debugQueue(string print,Queue *a) {
	printf ("%s\n",print);
	printf ("Size of element: %d\n", a->typeSize);
	printf ("Num of elements: %d\n", a->length);
	printf ("rare element: %d\n", a->rare);
	printf ("Address of elements: %p\n", a->elements);
	printf ("\n");	
}

void test_creates_Queue_of_two_integer_elements_1(){
	int a[] = {0,0};
	Queue* actual = create(sizeof(int),2);
	Queue expected = {-1,2,sizeof(int),a};
	ASSERT(areEqual(&expected,actual));
}


void test_creates_Queue_of_five_integer_elements_2(){
	int a[] = {0,0,0,0,0};
	Queue* actual = create(sizeof(int),5);
	Queue expected = {-1,5,sizeof(int),a};
	ASSERT(areEqual(&expected,actual));
}
void test_creates_Queue_of_five_char_elements_3(){
	char a[] = {0,0,0,0,0};
	Queue* actual = create(sizeof(char),5);
	Queue expected = {-1,5,sizeof(char),a};
	ASSERT(areEqual(&expected,actual));
}
void test_creates_Queue_of_five_float_elements_4(){
	float a[] = {0,0,0,0,0};
	Queue* actual = create(sizeof(float),5);
	Queue expected = {-1,5,sizeof(float),a};
	ASSERT(areEqual(&expected,actual));
}
void test_inserts_integer_elememt_in_Queue_5(){
	bool result;
	int element = 3;
	Queue* queue = create(sizeof(int),3);
	result = enQueue(queue,&element);
	ASSERT(result);
}
void test_inserts_float_elememt_in_queue_6(){
	float a[] = {1.1,0.0,0.0};
	float element = 1.1;
	Queue* actual = create(sizeof(float),3);
	Queue expected = {0,3,sizeof(float),a};
	enQueue(actual,&element);
	ASSERT(areEqual(&expected,actual));
}
void test_pushes_char_elememt_in_stack_7(){
	char a[1] = {'k'};
	char element = 'k';
	Queue* actual = create(sizeof(char),1);
	Queue expected = {0,1,sizeof(char),a};
	enQueue(actual,&element);
	ASSERT(areEqual(&expected,actual));
}

void test_not_inserts_elememt_in_Queue_if_queue_is_full_8(){
	bool result;
	int a = 3,b = 4,c = 5;
	Queue* queue = create(sizeof(int),3);
	enQueue(queue,&a);
	enQueue(queue,&b);
	enQueue(queue,&c);
	result=enQueue(queue,&a);
	ASSERT(0==result);
}

void test_deQueues_integer_elememt_from_queue_9(){
	int array[] = {8,0,0,0,0};
	void* poppedElement;
	int a = 7,b = 8;
	Queue* actual = create(sizeof(int),5);
	Queue expected = {0,5,sizeof(int),array};
	enQueue(actual,&a);
	enQueue(actual,&b);
	poppedElement = deQueue(actual);
	ASSERT(7 == *(int*)poppedElement);
	ASSERT(areEqual(&expected,actual));
}
void test_deQueues_float_elememt_from_queue_10(){
	float array[] = {7.0,0.0,0.0};
	void* poppedElement = 0;
	float a = 6.0,b = 7.0;

	Queue* actual = create(sizeof(float),3);
	Queue expected = {0,3,sizeof(float),array};
	enQueue(actual,&a);
	enQueue(actual,&b);
	poppedElement = deQueue(actual);
	ASSERT(6.0 == *(float*)poppedElement);
	ASSERT(areEqual(&expected,actual));
}
void test_deQueues_char_elememt_from_queue_11(){
	char a[3]={"d"};
	void* poppedElement = 0;
	char s = 's',d = 'd';
	Queue* actual = create(sizeof(char),3);
	Queue expected = {0,3,sizeof(char),a};
	enQueue(actual,&s);
	enQueue(actual,&d);
	poppedElement = deQueue(actual);
	ASSERT('s'== *(char*)poppedElement);
	ASSERT(areEqual(&expected,actual));
}
void test_deQueues_string_elememt_from_queue_12(){
	String a[3]={"sumit"};
	void* poppedElement;
	String s ="sumit";
	String d = "suraj";
	Queue* actual = create(sizeof(String),3);
	Queue expected = {0,3,sizeof(String),a};
	enQueue(actual,&s);
	enQueue(actual,&d);
	poppedElement = deQueue(actual);
	ASSERT(0 == strcmp(s,*(String*)poppedElement));
}
void test_checks_weather_queue_is_full_13(){
	Queue* queue;
	int a[]={1,2,3,4,5};
	queue = create(sizeof(int),5);
	queue->elements = a ;
	queue->rare=4;
	ASSERT(true == isFull(queue));
}
void test_checks_weather_queue_is_not_full_14(){
	Queue* queue;
	int a[]={1,2,3,0,0};
	queue = create(sizeof(int),5);
	queue->elements = a ;
	queue->rare=3; 
	ASSERT(false == isFull(queue));
}
void test_checks_weather_queue_is_empty_15(){
	Queue* queue;
	int a[]={0,0,0,0,0};
	queue = create(sizeof(int),5);
	queue->elements = a ;
	queue->rare=-1; 
	ASSERT(true == isEmpty(queue));
}
void test_checks_weather_queue_is_not_empty_16(){
	Queue* queue;
	int a[]={1,2,3,0,0};
	queue = create(sizeof(int),5);
	queue->elements = a ;
	queue->rare=2; 
	ASSERT(false == isEmpty(queue));
}

void test_gives_rare_element_of_queue_as_a_integer_17(){
	Queue* queue;
	int a[]={1,2,3,0,0};
	queue = create(sizeof(int),5);
	queue->elements = a ;
	queue->rare=2; 
	ASSERT(3 == *(int*)givesRare(queue));
}
void test_gives_rare_element_of_queue_as_a_integer_18(){
	char a[3]={"s"};
	void* rareElement;
	char s = 's';
	char d = 'd';
	Queue* actual = create(sizeof(char),3);
	Queue expected = {0,3,sizeof(char),a};
	enQueue(actual,&s);
	enQueue(actual,&d);
	rareElement = givesRare(actual);
	ASSERT(d == *(char*)rareElement);
}

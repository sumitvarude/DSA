#include "testUtils.h"
#include "stackLib.h"
#include "string.h"

typedef char string[256];
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areEqual(Stack* expected, Stack* actual){
	int result = (expected->length == actual->length) ;
	if(!result) return result;

	return 0 == memcmp(expected->elements,actual->elements,actual->length*actual->typeSize);
}

void debugStack(string print,Stack *a) {
	printf ("%s\n",print);
	printf ("Size of element: %d\n", a->typeSize);
	printf ("Num of elements: %d\n", a->length);
	printf ("Top element: %d\n", a->top);
	printf ("Address of elements: %p\n", a->elements);
	printf ("\n");	
}

void test_creates_stack_of_two_integer_elements_1(){
	int i=0;
	int a[] = {0,0};
	Stack* actual = create(sizeof(int),2);
	Stack expected = {-1,2,sizeof(int),a};
	ASSERT(areEqual(&expected,actual));
}


void test_creates_stack_of_five_integer_elements_2(){
	int i=0;
	int a[] = {0,0,0,0,0};

	Stack* actual = create(sizeof(int),5);
	Stack expected = {-1,5,sizeof(int),a};
	ASSERT(areEqual(&expected,actual));
}

void test_pushes_integer_elememt_in_stack_3(){
	int a[] = {6,0,0,0,0};
	int element = 6;
	Stack* actual = create(sizeof(int),5);
	Stack expected = {0,5,sizeof(int),a};
	actual = push(actual,&element);
	ASSERT(areEqual(&expected,actual));
}

void test_pushes_float_elememt_in_stack_4(){
	float a[] = {1.1,0.0,0.0};
	float element = 1.1;
	Stack* actual = create(sizeof(float),3);
	Stack expected = {0,3,sizeof(float),a};
	actual = push(actual,&element);
	ASSERT(areEqual(&expected,actual));
}
void test_pushes_char_elememt_in_stack_5(){
	char a[1] = {'k'};
	char element = 'k';
	Stack* actual = create(sizeof(char),1);
	Stack expected = {0,1,sizeof(char),a};
	actual = push(actual,&element);
	ASSERT(areEqual(&expected,actual));
}

void test_pops_integer_elememt_from_stack_6(){
	int a[] = {0,0,0,0,0};
	void* poppedElement = 0;
	int element = 6;
	Stack* actual = create(sizeof(int),5);
	Stack expected = {0,5,sizeof(int),a};
	actual = push(actual,&element);
	poppedElement = pop(actual);
	ASSERT(6 == *(int*)poppedElement);
	ASSERT(areEqual(&expected,actual));
}
void test_pops_float_elememt_from_stack_7(){
	float a[] = {0.0,0.0,0.0};
	void* poppedElement = 0;
	int element = 6.0;
	Stack* actual = create(sizeof(float),3);
	Stack expected = {0,3,sizeof(float),a};
	actual = push(actual,&element);
	poppedElement = pop(actual);
	ASSERT(areEqual(&expected,actual));
}
void test_pops_char_elememt_from_stack_8(){
	char a[3]={"s"};
	void* poppedElement = 0;
	char s = 's';
	char d = 'd';
	Stack* actual = create(sizeof(char),3);
	Stack expected = {0,3,sizeof(char),a};
	actual = push(actual,&s);
	actual = push(actual,&d);
	poppedElement = pop(actual);
	ASSERT(areEqual(&expected,actual));
}
void test_checks_weather_stack_is_full_9(){
	Stack* stack;
	int a[]={1,2,3,4,0};
	stack = create(sizeof(int),5);
	stack->elements = a ;
	stack->top=4;
	printf("%d",isFull(stack)); 
	ASSERT(true == isFull(stack));
}
void test_checks_weather_stack_is_not_full_10(){
	Stack* stack;
	int a[]={1,2,3,0,0};
	stack = create(sizeof(int),5);
	stack->elements = a ;
	stack->top=3; 
	ASSERT(false == isFull(stack));
}
void test_checks_weather_stack_is_empty_11(){
	Stack* stack;
	int a[]={0,0,0,0,0};
	stack = create(sizeof(int),5);
	stack->elements = a ;
	stack->top=-1; 
	ASSERT(true == isEmpty(stack));
}
void test_checks_weather_stack_is_not_empty_12(){
	Stack* stack;
	int a[]={1,2,3,0,0};
	stack = create(sizeof(int),5);
	stack->elements = a ;
	stack->top=2; 
	ASSERT(false == isEmpty(stack));
}

void test_gives_top_element_of_stack_as_a_integer_13(){
	Stack* stack;
	int a[]={1,2,3,0,0};
	stack = create(sizeof(int),5);
	stack->elements = a ;
	stack->top=2; 
	ASSERT(3 == *(int*)top(stack));
}
void test_gives_top_element_of_stack_as_a_integer_14(){
	char a[3]={"s"};
	void* topElement;
	char s = 's';
	char d = 'd';
	Stack* actual = create(sizeof(char),3);
	Stack expected = {0,3,sizeof(char),a};
	actual = push(actual,&s);
	actual = push(actual,&d);
	topElement = top(actual);
	ASSERT(d == *(char*)topElement);
}
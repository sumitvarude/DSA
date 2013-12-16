#include "testUtils.h"
#include "lLStack.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_creates_Stack(){
	Stack* stack = createStack();
	ASSERT(NULL == stack->head);
	ASSERT(0 == stack->noOfElements);
}

void test_2_inserts_INTEGER_element_in_stack(){
	int a = 6;
	Stack* stack = createStack();
	push(stack, &a);
	ASSERT(6 == *(int*)stack->head->data);
	ASSERT(1 == stack->noOfElements);
}
void test_3_inserts_two_CHAR_element_in_stack(){
	char a[] = {'a','b'};
	Stack* stack = createStack();
	push(stack,&a[0]);
	push(stack,&a[1]);
	ASSERT('b' == *(char*)stack->head->data);
	ASSERT(2 == stack->noOfElements);
}
void test_pops_CHAR_element_from_stack(){
	char a[] = {'a','b'};
	Stack* stack = createStack();
	push(stack,&a[0]);
	push(stack,&a[1]);
	pop(stack);
	ASSERT('a' == *(char*)stack->head->data);
	ASSERT(1 == stack->noOfElements);
}
void test_pops_INTEGER_element_from_stack(){
	int a[] = {1,2};
	Stack* stack = createStack();
	push(stack,&a[0]);
	push(stack,&a[1]);
	pop(stack);
	ASSERT(1 == *(int*)stack->head->data);
	ASSERT(1 == stack->noOfElements);
}
void test_pops_DOUBLE_element_from_stack(){
	double a[] = {1.0,2.0};
	Stack* stack = createStack();
	push(stack,&a[0]);
	push(stack,&a[1]);
	pop(stack);
	ASSERT(1.0 == *(double*)stack->head->data);
	ASSERT(1 == stack->noOfElements);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
	int top;
	int length;
	int typeSize;	 
	void* elements;
}Stack;


Stack*	create(int typesize,int length);						
Stack*	push(Stack *s1,void* element);				
void* 	pop(Stack *s1);							

bool   	isEmpty(Stack* s1);			
bool 	isFull(Stack* s1);
void* 	top(Stack* s1);

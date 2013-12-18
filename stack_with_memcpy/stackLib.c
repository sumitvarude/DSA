#include "stackLib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Stack* create (int typeSize, int length){
	Stack* stack;
	stack = (Stack*)calloc(1,sizeof(Stack)); 
	stack->elements =calloc(length,typeSize); 
	stack->typeSize=typeSize;
 	stack->top=-1;
 	stack->length=length;
	return stack;
}

Stack* push(Stack* stack,void* element){
	memcpy(stack->elements+(++stack->top*stack->typeSize), element,stack->typeSize);
	return stack;
}

void* pop(Stack* stack){
	void* element;
	memcpy( element,stack->elements+(stack->top*stack->typeSize),stack->typeSize);
	memset(stack->elements+(stack->top*stack->typeSize),0,stack->typeSize);
	stack->top--;
	return element;
}

bool isEmpty(Stack* stack){
	if(-1 == stack->top)
		return true;
	return false;
}				

bool isFull(Stack* stack){
	if(stack->length-1 == stack->top)
		return true;
	return false;
}
void* top(Stack* stack){
	void* element;
	memcpy( element,stack->elements+(stack->top*stack->typeSize),stack->typeSize);
	return element;
}
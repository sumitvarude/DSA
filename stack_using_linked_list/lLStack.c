#include "lLStack.h"
Stack*	createStack(){
	return createList();
}

int push(Stack* stack, void* element){
	return insertAtStart(stack, element);
}

void*  pop(Stack* stack){
	void* poppedElement = stack->head->data;
	removeElement(stack, 0);
	return poppedElement;
}

void* top(Stack* stack){
	return stack->head->data;
}
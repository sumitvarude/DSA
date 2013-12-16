#include "../doublyLinkedList/DLinkList.h"
#include <stdio.h>
typedef List Stack;

Stack*	createStack();						
int	push(Stack *s1,void* element);				
void* 	pop(Stack *s1);							
void* 	top(Stack* s1);

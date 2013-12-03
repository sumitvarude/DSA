# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "../stack/stackLib.h"
typedef char string[256];
bool performMatch(Stack *stack,string s){
	int i;
	for(i=0 ; i<strlen(s) ; i++){
		
		if(s[i]=='{' || s[i]=='[' || s[i]=='('){
			push(stack,&s[i]);
		}
		switch(s[i]) 
		{
		    case '}':
		    		if(*(char*)top(stack)=='{') pop(stack);
		    		push(stack,&s[i]);
		    		break;
			case ']':
					if(*(char*)top(stack)=='[') pop(stack);
		    		push(stack,&s[i]);	
		    		break;
		    case ')':
		    		if(*(char*)top(stack)=='(') pop(stack);
		    		push(stack,&s[i]);
		    		break;
		    default :
		    		break;
		}
	}
	if(stack->top==-1)
		return true;
	return false;
}
// int main(){
// 	Stack *stack = create(sizeof(char),256);
//  	if(performMatch(stack,"}asdkjkljdss9()(){}a[dsadas(af{}asdf)affa]}"))
//  		printf("matched");
//  	else
//  		printf("not matched");
//  	return 1;
//  }
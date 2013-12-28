#include <stdbool.h>
#include <string.h>
#include "bracketMatching.h"

int matchParenthesis(string s){
	int i;
	string openBrackets = {'{','[','('};
	Stack* stack = create(sizeof(char),256);
	for(i=0 ; i<strlen(s) ; i++){
		if(s[i]=='{' || s[i]=='[' || s[i]=='('){
			push(stack,&s[i]);
		}
		switch(s[i]) 
		{
		    case '}':
		    		if(*(char*)top(stack)=='{'){pop(stack); break;}
		    		return 0; 
			case ']':
					if(*(char*)top(stack)=='['){pop(stack);	break;}
		    			
		    		return 0; 
		    case ')':
		    		if(*(char*)top(stack)=='('){pop(stack);	break;}
		    		return 0; 
		}
	}
	return (stack->top==-1)?true:false;
}

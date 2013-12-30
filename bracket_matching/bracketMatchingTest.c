#include "testUtils.h"
#include "bracketMatching.h"
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_with_only_flower_brackets_for_parenthesis_matching(){
	String s= "{}";
	ASSERT(matchParenthesis(s));
}
void test_with_all_brackets_for_parenthesis_matching(){
	String s= "{([])}";
	ASSERT(matchParenthesis(s));
}
void test_with_only_square_brackets_for_parenthesis_matching(){
	String s= "[]";
	ASSERT(matchParenthesis(s));
}
void test_with_characters_in_between_for_parenthesis_matching(){
	String s= "(jkads(ha{aj}ja)[])";
	ASSERT(matchParenthesis(s));
}
void test_to_fail_parenthesis_matching(){
	String s= ")";
	ASSERT(0==matchParenthesis(s));
}

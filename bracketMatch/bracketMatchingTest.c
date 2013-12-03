#include "testUtils.h"
#include "bracketMatching.h"
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_for_parenthesis_matching(){
	string s= "{hi[he(ll)o]bye}.";
	Stack* stack;
	stack = create(sizeof(string),3);
	ASSERT(performMatch(stack,s));
}

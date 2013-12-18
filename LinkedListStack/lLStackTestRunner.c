#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1_creates_Stack");
	setup();
		test_1_creates_Stack();
	tearDown();
	testEnded();
	testStarted("test_2_inserts_INTEGER_element_in_stack");
	setup();
		test_2_inserts_INTEGER_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_3_inserts_two_CHAR_element_in_stack");
	setup();
		test_3_inserts_two_CHAR_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_pops_CHAR_element_from_stack");
	setup();
		test_pops_CHAR_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pops_INTEGER_element_from_stack");
	setup();
		test_pops_INTEGER_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pops_DOUBLE_element_from_stack");
	setup();
		test_pops_DOUBLE_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_element_as_INT_from_stack");
	setup();
		test_gives_top_element_as_INT_from_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_element_as_CHAR_from_stack");
	setup();
		test_gives_top_element_as_CHAR_from_stack();
	tearDown();
	testEnded();
	testStarted("test_gives_top_element_as_DOUBLE_from_stack");
	setup();
		test_gives_top_element_as_DOUBLE_from_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}

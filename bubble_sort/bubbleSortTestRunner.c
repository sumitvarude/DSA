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

	testStarted("test_gives_one_if_array_is_sorted");
	setup();
		test_gives_one_if_array_is_sorted();
	tearDown();
	testEnded();
	testStarted("test_gives_zero_if_array_is_not_sorted");
	setup();
		test_gives_zero_if_array_is_not_sorted();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_with_only_two_elements");
	setup();
		test_sorts_array_with_only_two_elements();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_with_multiple_elements");
	setup();
		test_sorts_array_with_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_of_double_elements");
	setup();
		test_sorts_array_of_double_elements();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_of_float_elements");
	setup();
		test_sorts_array_of_float_elements();
	tearDown();
	testEnded();
	testStarted("test_sorts_array_of_char_elements");
	setup();
		test_sorts_array_of_char_elements();
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

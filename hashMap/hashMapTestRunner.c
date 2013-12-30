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

	testStarted("test_add_an_element_to_hashmap");
	setup();
		test_add_an_element_to_hashmap();
	tearDown();
	testEnded();
	testStarted("test_add_an_element_to_hashmap1");
	setup();
		test_add_an_element_to_hashmap1();
	tearDown();
	testEnded();
	testStarted("test_add_an_element_to_hashmap2");
	setup();
		test_add_an_element_to_hashmap2();
	tearDown();
	testEnded();
	testStarted("test_get_an_element_from_hashmap");
	setup();
		test_get_an_element_from_hashmap();
	tearDown();
	testEnded();
	testStarted("test_get_another_element_from_hashmap");
	setup();
		test_get_another_element_from_hashmap();
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

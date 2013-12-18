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

	testStarted("test_weather_the_quetue_is_empty");
	setup();
		test_weather_the_quetue_is_empty();
	tearDown();
	testEnded();
	testStarted("test_inserts_element_in_queue");
	setup();
		test_inserts_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_inserts_2nd_element_in_queue");
	setup();
		test_inserts_2nd_element_in_queue();
	tearDown();
	testEnded();
	testStarted("test_removes_element_from_queue");
	setup();
		test_removes_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_removes_element_from_queue_and_checks_if_queue_is_empty");
	setup();
		test_removes_element_from_queue_and_checks_if_queue_is_empty();
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

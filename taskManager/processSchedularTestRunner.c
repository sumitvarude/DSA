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

	testStarted("test_creates_taskManager");
	setup();
		test_creates_taskManager();
	tearDown();
	testEnded();
	testStarted("test_inserts_task_in_given_empty_taskManager");
	setup();
		test_inserts_task_in_given_empty_taskManager();
	tearDown();
	testEnded();
	testStarted("test_inserts_task_in_given_taskManager1");
	setup();
		test_inserts_task_in_given_taskManager1();
	tearDown();
	testEnded();
	testStarted("test_inserts_task_in_given_taskManager2");
	setup();
		test_inserts_task_in_given_taskManager2();
	tearDown();
	testEnded();
	testStarted("test_manages_tasks_in_taskManager");
	setup();
		test_manages_tasks_in_taskManager();
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

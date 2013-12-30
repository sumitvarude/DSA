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

	testStarted("test_test_inserts_first_node_in_tree");
	setup();
		test_test_inserts_first_node_in_tree();
	tearDown();
	testEnded();
	testStarted("test_inserts_child_at_root");
	setup();
		test_inserts_child_at_root();
	tearDown();
	testEnded();
	testStarted("test_inserts_three_node_continously");
	setup();
		test_inserts_three_node_continously();
	tearDown();
	testEnded();
	testStarted("test_inserts_node_at_depth_two");
	setup();
		test_inserts_node_at_depth_two();
	tearDown();
	testEnded();
	testStarted("test_searches_root_node");
	setup();
		test_searches_root_node();
	tearDown();
	testEnded();
	testStarted("test_searches_at_depth_two");
	setup();
		test_searches_at_depth_two();
	tearDown();
	testEnded();
	testStarted("test_searches_at_different_depths");
	setup();
		test_searches_at_different_depths();
	tearDown();
	testEnded();
	testStarted("test_removing_leaf_node");
	setup();
		test_removing_leaf_node();
	tearDown();
	testEnded();
	testStarted("test_not_removes_element_which_is_not_found");
	setup();
		test_not_removes_element_which_is_not_found();
	tearDown();
	testEnded();
	testStarted("test_removing_node_from_different_depths");
	setup();
		test_removing_node_from_different_depths();
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

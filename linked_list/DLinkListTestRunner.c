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

	testStarted("test_1_insert_a_node_of___INT___type_AT_START");
	setup();
		test_1_insert_a_node_of___INT___type_AT_START();
	tearDown();
	testEnded();
	testStarted("test_2_insert_a_node_of___INT___type_AT_LAST");
	setup();
		test_2_insert_a_node_of___INT___type_AT_LAST();
	tearDown();
	testEnded();
	testStarted("test_3_insert_a_node_of___FLOAT___type_AT_START");
	setup();
		test_3_insert_a_node_of___FLOAT___type_AT_START();
	tearDown();
	testEnded();
	testStarted("test_4_insert_a_node_of___FLOAT___type_AT_LAST");
	setup();
		test_4_insert_a_node_of___FLOAT___type_AT_LAST();
	tearDown();
	testEnded();
	testStarted("test_5_insert_a_node_of___DOUBLE___type_AT_START");
	setup();
		test_5_insert_a_node_of___DOUBLE___type_AT_START();
	tearDown();
	testEnded();
	testStarted("test_6_insert_a_node_of___DOUBLE___type_AT_LAST");
	setup();
		test_6_insert_a_node_of___DOUBLE___type_AT_LAST();
	tearDown();
	testEnded();
	testStarted("test_7_insert_a_node_of___CHAR___type_AT_START");
	setup();
		test_7_insert_a_node_of___CHAR___type_AT_START();
	tearDown();
	testEnded();
	testStarted("test_8_inserts_a_node_of___INT___type_at_THIRD_position");
	setup();
		test_8_inserts_a_node_of___INT___type_at_THIRD_position();
	tearDown();
	testEnded();
	testStarted("test_9_inserts_a_node_of___FLOAT___type_at_THIRD_position");
	setup();
		test_9_inserts_a_node_of___FLOAT___type_at_THIRD_position();
	tearDown();
	testEnded();
	testStarted("test_10_inserts_a_node_of___CHAR___type_at_THIRD_position");
	setup();
		test_10_inserts_a_node_of___CHAR___type_at_THIRD_position();
	tearDown();
	testEnded();
	testStarted("test_11_gives_length_of_given_list");
	setup();
		test_11_gives_length_of_given_list();
	tearDown();
	testEnded();
	testStarted("test_12_removes_a_node_of___CHAR___type_at_THIRD_position");
	setup();
		test_12_removes_a_node_of___CHAR___type_at_THIRD_position();
	tearDown();
	testEnded();
	testStarted("test_13_search_data_in_given_list_return_index");
	setup();
		test_13_search_data_in_given_list_return_index();
	tearDown();
	testEnded();
	testStarted("test_14_search_data_in_empty_list_return_minus_one");
	setup();
		test_14_search_data_in_empty_list_return_minus_one();
	tearDown();
	testEnded();
	testStarted("test_15_search_gives_minus_one_if_data_not_found");
	setup();
		test_15_search_gives_minus_one_if_data_not_found();
	tearDown();
	testEnded();
	testStarted("test_whether_iterator_gives_next_node");
	setup();
		test_whether_iterator_gives_next_node();
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

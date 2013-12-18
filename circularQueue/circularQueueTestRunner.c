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

	testStarted("test_Creates_queue_of_5_integer_elements_1");
	setup();
		test_Creates_queue_of_5_integer_elements_1();
	tearDown();
	testEnded();
	testStarted("test_Creates_queue_of_5_char_elements_1");
	setup();
		test_Creates_queue_of_5_char_elements_1();
	tearDown();
	testEnded();
	testStarted("test_Creates_queue_of_5_float_elements_1");
	setup();
		test_Creates_queue_of_5_float_elements_1();
	tearDown();
	testEnded();
	testStarted("test_inserts_8_in_queue");
	setup();
		test_inserts_8_in_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_overwrites_after_queue_is_full");
	setup();
		test_enqueue_overwrites_after_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_insert_element_to_first_position_in_queue_if_queue_is_full");
	setup();
		test_insert_element_to_first_position_in_queue_if_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_removes_element_from_the_rear_of_Queue");
	setup();
		test_removes_element_from_the_rear_of_Queue();
	tearDown();
	testEnded();
	testStarted("test_gives_null_if_queue_is_empty");
	setup();
		test_gives_null_if_queue_is_empty();
	tearDown();
	testEnded();
	testStarted("test_checks_whether_the_queue_is_empty");
	setup();
		test_checks_whether_the_queue_is_empty();
	tearDown();
	testEnded();
	testStarted("test_checks_whether_the_queue_is_not_empty");
	setup();
		test_checks_whether_the_queue_is_not_empty();
	tearDown();
	testEnded();
	testStarted("test_checks_whether_the_queue_is_full");
	setup();
		test_checks_whether_the_queue_is_full();
	tearDown();
	testEnded();
	testStarted("test_checks_whether_the_queue_is_not_full");
	setup();
		test_checks_whether_the_queue_is_not_full();
	tearDown();
	testEnded();
	testStarted("test_gives_element_at_rear_of_queue");
	setup();
		test_gives_element_at_rear_of_queue();
	tearDown();
	testEnded();
	testStarted("test_gives_rear_as_null_if_queue_is_empty");
	setup();
		test_gives_rear_as_null_if_queue_is_empty();
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

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
	testStarted("test_Queue_enqueue_element_5_into_fullQueue_will_add_5_to_start_of_queue");
	setup();
		test_Queue_enqueue_element_5_into_fullQueue_will_add_5_to_start_of_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_Queue_will_remove_element_of_the_rear_of_Queue");
	setup();
		test_dequeue_Queue_will_remove_element_of_the_rear_of_Queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_Queue_on_empty_Queue_will_give_null");
	setup();
		test_dequeue_Queue_on_empty_Queue_will_give_null();
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
	testStarted("test_rear_Queue_will_give_rear_Element");
	setup();
		test_rear_Queue_will_give_rear_Element();
	tearDown();
	testEnded();
	testStarted("test_rear_Queue_on_empty_Queue_will_give_null");
	setup();
		test_rear_Queue_on_empty_Queue_will_give_null();
	tearDown();
	testEnded();
	testStarted("test_deposit_amount_in_account");
	setup();
		test_deposit_amount_in_account();
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

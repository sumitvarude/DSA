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

	testStarted("test_creates_Queue_of_two_integer_elements_1");
	setup();
		test_creates_Queue_of_two_integer_elements_1();
	tearDown();
	testEnded();
	testStarted("test_creates_Queue_of_five_integer_elements_2");
	setup();
		test_creates_Queue_of_five_integer_elements_2();
	tearDown();
	testEnded();
	testStarted("test_creates_Queue_of_five_char_elements_3");
	setup();
		test_creates_Queue_of_five_char_elements_3();
	tearDown();
	testEnded();
	testStarted("test_creates_Queue_of_five_float_elements_4");
	setup();
		test_creates_Queue_of_five_float_elements_4();
	tearDown();
	testEnded();
	testStarted("test_inserts_integer_elememt_in_Queue_5");
	setup();
		test_inserts_integer_elememt_in_Queue_5();
	tearDown();
	testEnded();
	testStarted("test_inserts_float_elememt_in_queue_6");
	setup();
		test_inserts_float_elememt_in_queue_6();
	tearDown();
	testEnded();
	testStarted("test_pushes_char_elememt_in_stack_7");
	setup();
		test_pushes_char_elememt_in_stack_7();
	tearDown();
	testEnded();
	testStarted("test_not_inserts_elememt_in_Queue_if_queue_is_full_8");
	setup();
		test_not_inserts_elememt_in_Queue_if_queue_is_full_8();
	tearDown();
	testEnded();
	testStarted("test_deQueues_integer_elememt_from_queue_9");
	setup();
		test_deQueues_integer_elememt_from_queue_9();
	tearDown();
	testEnded();
	testStarted("test_deQueues_float_elememt_from_queue_10");
	setup();
		test_deQueues_float_elememt_from_queue_10();
	tearDown();
	testEnded();
	testStarted("test_deQueues_char_elememt_from_queue_11");
	setup();
		test_deQueues_char_elememt_from_queue_11();
	tearDown();
	testEnded();
	testStarted("test_deQueues_string_elememt_from_queue_12");
	setup();
		test_deQueues_string_elememt_from_queue_12();
	tearDown();
	testEnded();
	testStarted("test_checks_weather_queue_is_full_13");
	setup();
		test_checks_weather_queue_is_full_13();
	tearDown();
	testEnded();
	testStarted("test_checks_weather_queue_is_not_full_14");
	setup();
		test_checks_weather_queue_is_not_full_14();
	tearDown();
	testEnded();
	testStarted("test_checks_weather_queue_is_empty_15");
	setup();
		test_checks_weather_queue_is_empty_15();
	tearDown();
	testEnded();
	testStarted("test_checks_weather_queue_is_not_empty_16");
	setup();
		test_checks_weather_queue_is_not_empty_16();
	tearDown();
	testEnded();
	testStarted("test_gives_rare_element_of_queue_as_a_integer_17");
	setup();
		test_gives_rare_element_of_queue_as_a_integer_17();
	tearDown();
	testEnded();
	testStarted("test_gives_rare_element_of_queue_as_a_integer_18");
	setup();
		test_gives_rare_element_of_queue_as_a_integer_18();
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

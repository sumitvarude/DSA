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

	testStarted("test_creates_stack_of_two_integer_elements_1");
	setup();
		test_creates_stack_of_two_integer_elements_1();
	tearDown();
	testEnded();
	testStarted("test_creates_stack_of_five_integer_elements_2");
	setup();
		test_creates_stack_of_five_integer_elements_2();
	tearDown();
	testEnded();
	testStarted("test_pushes_integer_elememt_in_stack_3");
	setup();
		test_pushes_integer_elememt_in_stack_3();
	tearDown();
	testEnded();
	testStarted("test_pushes_float_elememt_in_stack_4");
	setup();
		test_pushes_float_elememt_in_stack_4();
	tearDown();
	testEnded();
	testStarted("test_pushes_char_elememt_in_stack_5");
	setup();
		test_pushes_char_elememt_in_stack_5();
	tearDown();
	testEnded();
	testStarted("test_pops_integer_elememt_from_stack_6");
	setup();
		test_pops_integer_elememt_from_stack_6();
	tearDown();
	testEnded();
	testStarted("test_pops_float_elememt_from_stack_7");
	setup();
		test_pops_float_elememt_from_stack_7();
	tearDown();
	testEnded();
	testStarted("test_pops_char_elememt_from_stack_8");
	setup();
		test_pops_char_elememt_from_stack_8();
	tearDown();
	testEnded();
	testStarted("test_checks_weather_stack_is_full_9");
	setup();
		test_checks_weather_stack_is_full_9();
	tearDown();
	testEnded();
	testStarted("test_checks_weather_stack_is_not_full_10");
	setup();
		test_checks_weather_stack_is_not_full_10();
	tearDown();
	testEnded();
	testStarted("test_checks_weather_stack_is_empty_11");
	setup();
		test_checks_weather_stack_is_empty_11();
	tearDown();
	testEnded();
	testStarted("test_checks_weather_stack_is_not_empty_12");
	setup();
		test_checks_weather_stack_is_not_empty_12();
	tearDown();
	testEnded();
	testStarted("test_gives_top_element_of_stack_as_a_integer_13");
	setup();
		test_gives_top_element_of_stack_as_a_integer_13();
	tearDown();
	testEnded();
	testStarted("test_gives_top_element_of_stack_as_a_integer_14");
	setup();
		test_gives_top_element_of_stack_as_a_integer_14();
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

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

	testStarted("test_searches_element_from_char_array");
	setup();
		test_searches_element_from_char_array();
	tearDown();
	testEnded();
	testStarted("test_give_null_if_the_element_is_not_present_in_array_for_char");
	setup();
		test_give_null_if_the_element_is_not_present_in_array_for_char();
	tearDown();
	testEnded();
	testStarted("test_gives_first_occurance_if_same_values_are_present");
	setup();
		test_gives_first_occurance_if_same_values_are_present();
	tearDown();
	testEnded();
	testStarted("test_searches_element_from_integer_array");
	setup();
		test_searches_element_from_integer_array();
	tearDown();
	testEnded();
	testStarted("test_give_null_if_the_element_is_not_present_in_array_for_integer");
	setup();
		test_give_null_if_the_element_is_not_present_in_array_for_integer();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_float_array");
	setup();
		test_search_element_from_the_float_array();
	tearDown();
	testEnded();
	testStarted("test_give_null_if_the_element_is_not_present_in_array_for_float");
	setup();
		test_give_null_if_the_element_is_not_present_in_array_for_float();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_array_of_doubles");
	setup();
		test_search_element_from_array_of_doubles();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_array_of_strings");
	setup();
		test_search_element_from_array_of_strings();
	tearDown();
	testEnded();
	testStarted("test_search_element_from_the_String_array_which_is_not_found");
	setup();
		test_search_element_from_the_String_array_which_is_not_found();
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

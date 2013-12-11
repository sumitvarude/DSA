#include "testUtils.h"
#include "processSchedular.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_a_shedular(){
	Shedular* shedular;
	Shedular expected;
	shedular = create();
	expected.head = NULL;
	expected.noOfProcesses = 0;
	ASSERT(shedular->noOfProcesses==expected.noOfProcesses);
	ASSERT(shedular->head==expected.head);
}
void test_create_a_process(){
	Process* process;
	process = createProcess(10,4);
	ASSERT(10 == process->time);
	ASSERT(4 == process->priority);
}
void test_insert_a_process_in_empty_shedular(){
	Shedular* shedular;
	shedular = create();
	insertProcess(shedular ,2 ,4);
	ASSERT(2 == shedular->head->time);
	ASSERT(4 == shedular->head->priority);
}
void test_insert_2_process_in_shedular(){
	Shedular* shedular;
	shedular = create();
	insertProcess(shedular ,2 ,4);
	insertProcess(shedular ,10 ,3);
	ASSERT(10 == shedular->head->time);
	ASSERT(3 == shedular->head->priority);
}
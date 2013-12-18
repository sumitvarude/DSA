#include "testUtils.h"
#include "processSchedular.h"
#include <stdlib.h>
#include <stdio.h>

// void test_creates_task(){
// 	Task* task= createTask(5,10);
// 	ASSERT(5==task->priority);
// 	ASSERT(10==task->time);
// 	ASSERT(NULL==task->next);
// 	free(task);
// };
void test_creates_taskManager(){
	TaskManager* taskManager = createTaskManager(5);
	ASSERT(5==taskManager->sliceTime);
	ASSERT(0==taskManager->noOfTasks);
	ASSERT(NULL==taskManager->tasks);
	free(taskManager);
};
void test_inserts_task_in_given_empty_taskManager(){
	TaskManager* taskManager = createTaskManager(5);
	ASSERT(insertTask(taskManager,5,10));
	ASSERT(1==taskManager->noOfTasks);
	ASSERT(5==taskManager->sliceTime);
	free(taskManager);
};
void test_inserts_task_in_given_taskManager1(){
	TaskManager* taskManager = createTaskManager(5);
	ASSERT(insertTask(taskManager,5,10));
	ASSERT(insertTask(taskManager,7,10));
	ASSERT(2==taskManager->noOfTasks);
	ASSERT(5==taskManager->sliceTime);
	free(taskManager);	
};

void test_inserts_task_in_given_taskManager2(){
	TaskManager* taskManager = createTaskManager(5);
	ASSERT(insertTask(taskManager,5,10));
	ASSERT(insertTask(taskManager,9,10));
	ASSERT(insertTask(taskManager,7,10));
	ASSERT(3==taskManager->noOfTasks);
	ASSERT(5==taskManager->sliceTime);
	free(taskManager);
};
void test_manages_tasks_in_taskManager(){
	TaskManager* taskManager = createTaskManager(5);
	ASSERT(insertTask(taskManager,5,13));
	ASSERT(insertTask(taskManager,5,15));
	ASSERT(2==taskManager->noOfTasks);
	ASSERT(5==taskManager->sliceTime);
	ASSERT(startTaskManager(taskManager));
	// ASSERT(0==taskManager->noOfTasks);

};
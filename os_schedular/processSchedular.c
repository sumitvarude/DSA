#include "processSchedular.h"
#include <stdlib.h>
#include <stdio.h>
#include "../insertion_sort/sort.h"

Task* createTask(int priority, int time){
	Task* task  = malloc(sizeof(Task));
	task->priority = priority;	
	task->time = time;
	task->next = NULL;
	task->previous = NULL;
	return task;

};
TaskManager* createTaskManager(int sliceTime){
	TaskManager* taskManager = malloc(sizeof(TaskManager));
	taskManager->sliceTime = sliceTime;	
	taskManager->noOfTasks=0;
	taskManager->tasks = NULL;
	return taskManager;

};
int insertTask(TaskManager* taskManager,int priority,int time){
	Task* task = createTask(priority,time);
	Task* temp = malloc(sizeof(task));
	if(NULL == taskManager->tasks) taskManager->tasks = task; 
	else{	
		temp = taskManager->tasks;
		while(task->priority<temp->priority && temp->next!=NULL){
	 		temp = temp->next;
		}
		task->previous=temp;
		task->next = temp->next;
	}
	taskManager->noOfTasks++;
	return 1;
};

int startTaskManager(TaskManager* taskManager){
	int i;
	Task *task,*temp = taskManager->tasks;
	while(taskManager->noOfTasks!=0){
		printf("iuja:%d\n",taskManager->noOfTasks);
	for (i = 0; i < taskManager->noOfTasks; ++i){

		temp->time=temp->time-taskManager->sliceTime;
		printf("temp->time:%d\n",taskManager->sliceTime);
		 if(temp->time<=0) {
			task->next=temp->next;
		 	taskManager->noOfTasks--;
		 }
		task = temp;
		temp = temp->next;
	}
	temp = taskManager->tasks;
	}
	free(temp);
	return 1;
};


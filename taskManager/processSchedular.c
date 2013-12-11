#include "processSchedular.h"
#include <stdio.h>
#include <stdlib.h>

Shedular* create(){
	Shedular* shedular;
	shedular = calloc(1,sizeof(shedular));
	shedular->head = NULL;
	shedular->noOfProcesses = 0;
	return shedular;
}
Process* createProcess(int time,int priority){
	Process* process;
	process = calloc(1,sizeof(Process));
	process->next = NULL;
	process->previous = NULL;
	process->priority = priority;
	process->time = time;
	return process;
}
int insertProcess(Shedular* listOfPro ,int priority , int time){
	int i;
	Process* process;
	process = createProcess(priority, time);
	
	for(i = 0;i <= listOfPro->noOfProcesses; i++){
		if(listOfPro->head == NULL){
			listOfPro->noOfProcesses = 1;
			listOfPro->head = process;
			return 1;
		}
		if((listOfPro->head->priority) >= process->priority){
			listOfPro->head->previous = process;
			process->next = listOfPro->head->next;
			listOfPro->head = process;
			listOfPro->noOfProcesses++;
			return 1;		
		}
	return 0;	
	}
}
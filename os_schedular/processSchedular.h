typedef char string[50];

typedef struct process{
        struct process* next;
        struct process* previous;        
        int time;
        int priority;
}Process;

typedef struct{
        Process* head;
        int noOfProcesses;
}Shedular;

Shedular* create();
Process* createProcess(int time ,int priority);
int insertProcess(Shedular* listOfProcess , int time ,int priority);


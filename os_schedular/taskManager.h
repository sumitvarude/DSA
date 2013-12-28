typedef struct {
	int priority;
	int time;
	void* next;
	void* previous;
}Task;

typedef struct {
	int noOfTasks;
	int sliceTime;
	Task* tasks;
}TaskManager;

//Task* createTask(int priority,int time);
TaskManager* createTaskManager(int sliceTime);
int insertTask(TaskManager* taskManager,int priority,int time);
int startTaskManager(TaskManager* taskManager);

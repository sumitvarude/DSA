typedef int (*Compare)(void* element1,void* element2);
void performSort(void* array,int noOfElements,int typeSize, Compare compare);

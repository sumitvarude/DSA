typedef int (*CompareFunc)(void* element1,void* element2);
void performMergeSort(void* array,int noOfElements,int typesize,CompareFunc compare);
int merge(void* destination,void* leftArray ,void* rightArray ,int lALength ,int rALength ,int typesize , CompareFunc cmp);
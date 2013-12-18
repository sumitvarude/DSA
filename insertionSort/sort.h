typedef int (*compare)(void* first, void* second);
void sort(void* base, int length, int typeSize,compare comp); 
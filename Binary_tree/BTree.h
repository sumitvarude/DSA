typedef int (*Compare)(void* element1,void* element2); 
typedef struct Node{
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	void* data;
}Node;
typedef struct {
	void* root;
	int noOfNodes;
	int (*Compare)(void* element1,void* element2);
}Btree;

Btree* create(Compare cmp);
int Insert(Btree* btree,void* data);
int searchData(Btree* btree,void* data);
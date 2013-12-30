#include "testUtils.h"
#include "tree.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first,void* second){
	return *(int*)first - *(int*)second;
};

void test_test_inserts_first_node_in_tree(){
	Tree tree = createTree(cmpInt);
	void *element;
	int node1 =10;
	Iterator it;
	ASSERT(1 == insertTreeNode(&tree,NULL,&node1));
	it = getChildren(&tree,NULL);
	element = it.next(&it);
	ASSERT(*(int*)element == node1);
};

void test_inserts_child_at_root(){
	Tree tree = createTree(cmpInt);
	int node1 = 10,node2 = 20;
	Iterator it;
	insertTreeNode(&tree,NULL,&node1);
	insertTreeNode(&tree,&node1,&node2);
	it = getChildren(&tree,&node1);
	ASSERT(node2 == *(int*)it.next(&it));
	ASSERT(NULL == it.next(&it));
};

void test_inserts_three_node_continously(){
	Tree tree = createTree(cmpInt);
	int node1 = 10,node2 = 20,node3 = 30,node4 = 40;
	Iterator it;
	insertTreeNode(&tree,NULL,&node1);
	insertTreeNode(&tree,&node1,&node2);
	insertTreeNode(&tree,&node1,&node3);
	insertTreeNode(&tree,&node1,&node4);
	it = getChildren(&tree,&node1);
	ASSERT(node4 == *(int*)it.next(&it));
	ASSERT(node3 == *(int*)it.next(&it));
	ASSERT(node2 == *(int*)it.next(&it));
};

void test_inserts_node_at_depth_two(){
	Tree tree = createTree(cmpInt);
	void * element;
	int node1 = 10,node2 = 20,node3 = 30,node4 = 40;
	Iterator it;
	insertTreeNode(&tree,NULL,&node1);
	insertTreeNode(&tree,&node1,&node2);
	insertTreeNode(&tree,&node2,&node3);
	insertTreeNode(&tree,&node2,&node4);
	it = getChildren(&tree,&node2);
	ASSERT(node4 == *(int*)it.next(&it));
	ASSERT(node3 == *(int*)it.next(&it));
};

void test_searches_root_node(){
	Tree tree = createTree(cmpInt);
	int node1 =10;
	ASSERT(1 == insertTreeNode(&tree,NULL,&node1));
	ASSERT(1 == search(&tree,&node1));
};

void test_searches_at_depth_two(){
	Tree tree = createTree(cmpInt);
	int node1 = 10,node2 = 20,node3 = 30,node4 = 40;
	insertTreeNode(&tree,NULL,&node1);
	insertTreeNode(&tree,&node1,&node2);
	insertTreeNode(&tree,&node2,&node3);
	insertTreeNode(&tree,&node2,&node4);
	ASSERT(1 == search(&tree,&node3));
	ASSERT(1 == search(&tree,&node4));
};

void test_searches_at_different_depths(){
	Tree tree = createTree(cmpInt);
	int node1 = 10,node2 = 20,node3 = 30,node4 = 40,node5 = 50,node6 = 60;
	insertTreeNode(&tree,NULL,&node1);
	insertTreeNode(&tree,&node1,&node2);
	insertTreeNode(&tree,&node1,&node3);
	insertTreeNode(&tree,&node2,&node4);
	insertTreeNode(&tree,&node4,&node5);
	insertTreeNode(&tree,&node3,&node6);

	ASSERT(1 == search(&tree,&node6));

};
void test_removing_leaf_node(){
	Tree tree = createTree(cmpInt);
	int node1 = 10,node2 = 20;
	Iterator it;
	insertTreeNode(&tree,NULL,&node1);
	insertTreeNode(&tree,&node1,&node2);
	ASSERT(1 == removeTreeNode(&tree,&node2));
	it = getChildren(&tree,&node1);
	ASSERT(NULL == it.next(&it));
};

void test_not_removes_element_which_is_not_found(){
	Tree tree = createTree(cmpInt);
	int node1 = 10,node2 = 20,node3 = 30,node4 = 40;
	Iterator it;
	insertTreeNode(&tree,NULL,&node1);
	insertTreeNode(&tree,&node1,&node2);
	ASSERT(0 == removeTreeNode(&tree,&node3));
};

void test_removing_node_from_different_depths(){
	Tree tree = createTree(cmpInt);
	int node1 = 10,node2 = 20,node3 = 30,node4 = 40;
	Iterator it;
	insertTreeNode(&tree,NULL,&node1);
	insertTreeNode(&tree,&node1,&node2);
	insertTreeNode(&tree,&node1,&node3);
	insertTreeNode(&tree,&node3,&node4);
	ASSERT(1 == removeTreeNode(&tree,&node4));
};
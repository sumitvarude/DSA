#include "testUtils.h"
#include "BTree.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareInt(void* element1, void* element2){
	return *(int*)element1 - *(int*)element2; 
}
void test_inserts_element_at_root(){
	int data = 2014;
	Btree* tree = create(compareInt);
	ASSERT(Insert(tree,&data));
}
void test_inserts_element_at_roots_left(){
	int data[] = {10,6};
	Btree* tree = create(compareInt);
	ASSERT(Insert(tree,&data[0]));
	ASSERT(Insert(tree,&data[1]));
}
void test_inserts_element_at_roots_left_and_right(){
	int data[] = {10,6,7};
	Btree* tree = create(compareInt);
	ASSERT(Insert(tree,&data[0]));
	ASSERT(Insert(tree,&data[1]));
	ASSERT(Insert(tree,&data[2]));	
}
void test_searches_element_from_Binary_tree(){	
	int data[] = {10,6,7};
	Btree* tree = create(compareInt);
	ASSERT(Insert(tree,&data[0]));
	ASSERT(Insert(tree,&data[1]));
	ASSERT(Insert(tree,&data[2]));
	ASSERT(searchData(tree,&data[0]));
	ASSERT(searchData(tree,&data[1]));

}
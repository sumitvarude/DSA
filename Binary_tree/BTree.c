#include "BTree.h"
#include <stdlib.h>
#include <stdio.h>
Btree* create(Compare cmp){
	Btree* binTree = calloc(1,sizeof(Btree));
	binTree->noOfNodes = 0;
	binTree->root = NULL;
	binTree->Compare = cmp;
	return binTree;
}
Node* createBNode(){
	Node *node = calloc(1,sizeof(Node));
	node->data = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}
int insertAfterRoot(Btree* btree,Node* tempNode,Node* node,void* data){
	while(tempNode->left != NULL || tempNode->right!=NULL){
		if(0 == btree->Compare(data,tempNode->data))
			return 0;
		if(0 >= btree->Compare(data,tempNode->data)){
			if(tempNode->left == NULL){
				tempNode->left = node;
				return 1;
			}
			tempNode = tempNode->left;
		}
		if(0 <= btree->Compare(data,tempNode->data)){
			if(tempNode->right == NULL){
				tempNode->right = node;
				return 1;
			}
			tempNode =tempNode->right;
		}
	}
	return 0;
}
int searchData(Btree* btree,void* data){
	Node* tempNode = btree->root;
	if(0 == btree->Compare(data,tempNode->data)){
		return 1;
	}
	while(tempNode->left != NULL || tempNode->right!=NULL){
		printf("data:%d\n",*(int*)tempNode->data);
		printf("data1:%d\n",*(int*)data);
		if(0 == btree->Compare(data,tempNode->data)){
			printf("while if 1\n");
			return 1;
		}
		if(0 >= btree->Compare(data,tempNode->data)){
			printf("while if 2 \n");
			if(tempNode->left == NULL){
				printf("while if 2 if 1");
				return 0;
			}
			tempNode = tempNode->left;
		}
		if(0 <= btree->Compare(data,tempNode->data)){
			if(tempNode->right == NULL){
				printf("while if 3 if 1");
				return 0;
			}
			tempNode =tempNode->right;
		}
	}
	return 0;
}
int Insert(Btree* btree,void* data){
	Node *tempNode,*node = createBNode();
	node->data = data;
	if(btree->root == NULL){
		btree->root = node;
		btree->noOfNodes += 1; 	
		return 1;
	} 
	tempNode = btree->root;
	if(0 == btree->Compare(data,tempNode->data))
			return 0;
	if(0 >= btree->Compare(data,tempNode->data)){
		if(tempNode->left == NULL){
			tempNode->left = node;
			return 1;
		}
	}
	if(0 <= btree->Compare(data,tempNode->data)){
		if(tempNode->right == NULL){
			tempNode->right = node;
			return 1;
		}
	}
	return insertAfterRoot(btree, tempNode, node, data);
}

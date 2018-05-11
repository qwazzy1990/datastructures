#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinSearchTreeAPI.h"
#include "Rule.h"

TreeNode* createTreeNode(void* data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Tree* createBinTree(int (*compare)(const void* a, const void* b), void(*del)(void* d), void(*print)(void* p))
{
    Tree* T = (Tree*)malloc(sizeof(Tree));
    T->root = NULL;
    T->compareFunc = compare;
    T->deleteFunc = del;
    T->printFunc = print;
    return T;
}

void destroyBinTree(Tree* toDestroy){
    TreeNode* theRoot = toDestroy->root;
    while(theRoot != NULL){
        if(theRoot->leftChild == NULL){
	    free(theRoot);
   	 }
    }
}

void addToTree(Tree* theTree, void* data)
{
    if(theTree->root == NULL){
       theTree->root = insertInTree(theTree, theTree->root, data);
    }
    else {
	insertInTree(theTree, theTree->root, data);
    }
}

void* findInTree(Tree* theTree, TreeNode* theRoot, void* data)
{
    if(theRoot == NULL){

	return NULL;
    }
    else if(compareRule2(theRoot->data, data) ==0){

	return theRoot->data;
    }
    else if(compareRule2(theRoot->data, data)==1){
	return findInTree(theTree, theRoot->leftChild, data);
    }
    else {
	return findInTree(theTree, theRoot->rightChild, data);
    }
}

TreeNode* insertInTree(Tree* theTree, TreeNode* theRoot, void* data){
    
    if(theRoot == NULL){

	theRoot = createTreeNode(data);	
    }
    else if(compareRule(theRoot->data, data) == 1){
      
	theRoot->leftChild = insertInTree(theTree, theRoot->leftChild, data);

    }
    else if(compareRule(theRoot->data, data) == -1){

	theRoot->rightChild = insertInTree(theTree, theRoot->rightChild, data);
       
    }
    return theRoot;
}

void reconnect(Tree* theTree, TreeNode* data)
{
    TreeNode* temp = theTree->root;
    while(temp != NULL){
	temp = temp->leftChild;
    }   
    temp = data;
}
void printInOrder(Tree* theTree){

    inOrder(theTree->root);
}

void printPreOrder(Tree* theTree){
    
     preOrder(theTree->root);
}

void printPostOrder(Tree* theTree){
    
    postOrder(theTree->root);
}
void inOrder(TreeNode* theRoot)
{
   
    if(theRoot == NULL){
	return;
    } 
    inOrder(theRoot->leftChild);
    printRule(theRoot->data);
    inOrder(theRoot->rightChild);
}

void preOrder(TreeNode* theRoot)
{
    if(theRoot == NULL){
	return;
    }
    printRule(theRoot->data);
    preOrder(theRoot->leftChild);
    preOrder(theRoot->rightChild);
}

void postOrder(TreeNode* theRoot)
{
    if(theRoot == NULL){
	return;
    }
    postOrder(theRoot->leftChild);
    postOrder(theRoot->rightChild);
    printRule(theRoot->data);
}   

int hasOneChild(TreeNode* theParent)
{
    if(theParent->leftChild == NULL && theParent->rightChild==NULL){
	return -1;
    }

    else if(theParent->leftChild == NULL){
	return 0;
    }
    else if(theParent->rightChild == NULL){
	return 1;
    }
    else {
	return -1;
    }
}  

Rule* findMin(TreeNode* theRoot)
{
    TreeNode* i = theRoot;
    while(i->leftChild != NULL){
	i = i->leftChild;
    }
    return (Rule*)i->data;
}
void deleteFromTree(Tree* theTree, TreeNode* theRoot, void* data)
{
    if(theRoot == NULL){
	printf("Could not be found\n");
	return;
    }
    if(compareRule2(theRoot->data, data) == 1){
	deleteFromTree(theTree, theRoot->leftChild, data);
    }
    else if(compareRule2(theRoot->data, data) == -1){
	deleteFromTree(theTree, theRoot->rightChild, data);
    }
    else{
        if((theRoot->leftChild == NULL) && (theRoot->rightChild==NULL)){
	    free(theRoot->data);
	    free(theRoot);
	    printf("deleting leaf\n");

	}
	else if(theRoot->leftChild == NULL){
	    TreeNode* temp = theRoot;
	    temp->data = theRoot->data;
	    theRoot = theRoot->rightChild;
	    free(temp->data);

	    free(temp);
	    printf("deleting node with only right child\n");

	}
        else if(theRoot->rightChild == NULL){
	    TreeNode* temp = theRoot;
	    theRoot->data = theRoot->leftChild->data;
	    free(temp->data);
	    free(temp);
	    printf("deleting node with only left child\n");


	}
        else{
	    Rule* c = clone(findMin(theRoot->rightChild));
	    free(theRoot->data);
	    theRoot->data = c;
	    printRule(theRoot->data);
	    TreeNode* iterator = theRoot->rightChild;
	    while(iterator->leftChild != NULL){
		iterator = iterator->leftChild;
	    }
	    free(iterator->data);
	    free(iterator);
	    iterator = NULL;
	    iterator->data = NULL;	    
	    printf("Deleting node with two children\n");
	}


    }
}
















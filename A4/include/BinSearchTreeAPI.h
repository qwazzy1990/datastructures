
#ifndef _SEARCH_TREE_
#define _SEARCH_TREE_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Rule.h"

struct binTreeNode{
    struct binTreeNode* leftChild;
    struct binTreeNode* rightChild;
    void* data;
};typedef struct binTreeNode TreeNode;

struct binTree{
    TreeNode* root;
    int (*compareFunc)(const void* a, const void* b);
    void (*deleteFunc)(void* x);
    void (*printFunc)(void* x);
}; typedef struct binTree Tree;


/**
    creates a treeNode
*/
TreeNode* createTreeNode(void* data);

/**
    creates a tree
*/
Tree* createBinTree(int(*compare)(const void* a, const void* b), void(*del)(void* d), void(*print)(void* p));
/**
   Destroy the tree
*/
void destroyBinTree(Tree* toDestroy);
/**
   Wrapper for insertInTree
*/
void addToTree(Tree* theTree, void* data);
/**
    Used to insert in tree
*/

TreeNode* insertInTree(Tree* theTree, TreeNode* theRoot, void* data);
/**
   wrapper calls deleteFromTree
*/
void removeFromTree(Tree* theTree, void* data);
/**
    removes data from the tree
*/
void deleteFromTree(Tree* theTree, TreeNode* theRoot, void* data);
/**
   finds data in the tree
*/
void* findInTree(Tree* theTree, TreeNode* theRoot, void* data);
/**
    returns the data at the root of the tree
*/
void* getRootData(Tree* theTree);
/**
    checks if tree is empty
*/
int isTreeEmpty(Tree* theTree);
/**
    checks if treeNode is a leaf
*/
int isLeaf(TreeNode* leaf);
/**
    checks if node has two children
*/
int hasTwoChildren(TreeNode* parent);
/**
   checks if node has one child
*/
int hasOneChild(TreeNode* parent);
/**
   gets the height of the tree
*/
int getHeight(Tree* theTree);
/**
   wrapper calls inOrder  prints in the order of the tree
*/
void printInOrder(Tree* theTree);
/**
    wrapper calls preOrder prints from lowest to highest
*/
void printPreOrder(Tree* theTree);
/**
   wrapper calls postOrder  prints highest to lowest
*/
void printPostOrder(Tree* theTree);
/**
    prints in order
*/
void inOrder(TreeNode* theRoot);
/**
    prints pre order
*/
void preOrder(TreeNode* theRoot);
/**
    prints post order
*/
void postOrder(TreeNode* theRoot);
/**
    finds smallest value in tree
*/
Rule* findMin(TreeNode* theRoot);
/**
    reconnects treeNodes
*/
void reconnect(Tree* theTree, TreeNode* data);
#endif

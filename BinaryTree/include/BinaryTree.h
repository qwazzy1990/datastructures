#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "utilities.h"
#include "DynamicString.h"


struct n{
    AnyData data;
    struct n* leftChild;
    struct n* rightChild;
};
typedef struct n treenode;
typedef treenode* TreeNode;
typedef TreeNode* TreeNodes;


struct bitr{
    TreeNode current;
};
typedef struct bitr TreeIterator;

/***ENUMS****/

enum order{
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
};
typedef enum order TraversalOrder;

enum terr{
    OK_TREE, 
    DNF_TREE,
    DNE_TREE,    
    MEM_ERR_TREE,
    DUPLICATE_VALUE_TREE
};
typedef enum terr TreeErrorCode;

struct t{
    TreeNode root;
    int height;
    int size;
    PrintFunc printData;
    DeleteFunc deleteData;
    CompareFunc compareData;
    CloneFunc cloneData;

    /***FP TO ACCESSORS***/
    AnyData (*get_root)(struct t*);
    AnyData (*find)(struct t*, AnyData);
    int (*get_height)(struct t*);
    int (*get_size)(struct t*);

    /***FP TO DESTROYERS**/
    TreeErrorCode (*remove)(struct t*, AnyData);
    TreeErrorCode (*remove_root)(struct t*);
    TreeErrorCode (*remove_smallest)(struct t*);
    TreeErrorCode (*remove_largest)(struct t*);

    /***FP TO SETTERS**/
    TreeErrorCode (*add)(struct t*, AnyData);
    TreeErrorCode (*set_height)(struct t*);

    /***FP TO ITERATORS FIX ME!!***/

    /***MUTATORS***/
    String (*to_string)(struct t*, TraversalOrder);
    AnyData (*to_array)(struct t*, TraversalOrder);



};
typedef struct t binarytree;
typedef binarytree* BinaryTree;


/***PRE-PROCESSOR DIRECTIVES***/

/**
 * Pre-processor directive indicates function call for destroying the tree.
 * It is advised that the user calls the function destroy_tree(tree).
 * Not destroy_tree_real(&tree)
 * **/
#define destroy_tree(tree) destroy_tree_real(&tree)


/**CONSTRUCTORS**/

/**
 * Creates a TreeNode containing data d.
 * @pre: d must not be NULL
 * @ppost: a new TreeNode is created containing d.
 * @post: left child and right child of node are NULL.
 * @return: a new node if d is not NULL, else NULL
 * */
TreeNode new_tree_node(AnyData d);


/**
 * Creates a BinaryTree object with root set to NULL, size set to 0, height set to 0, and CloneFunc set to NULL:
 *@pre: all function pointers must exist and not be NULL.
 * @post: a BinaryTree object with printData = to p, deleteData= to d, and compareData = to c.
 * @return: NULL if failure, else a BinaryTree
 * */
BinaryTree new_tree(PrintFunc p, DeleteFunc d, CompareFunc c);

/**
 * Creates a BinaryTree object with root set to NULL, size set to 0, height set to 0:
 *@pre: all function pointers must exist and not be NULL.
 * @post: a BinaryTree object with printData = to p, deleteData= to d, and compareData = to c and cloneFunc = to cl.
 * @return: NULL if failure, else a BinaryTree with the ability to print data, delete data, compare data and clone data
 * NOTE: The clone function must return a void* and take in a void* as a parameter. Therefore, typecast the cloned object to
 * a void* before returning the object in the clone function
 * */

BinaryTree new_tree_two(PrintFunc p, DeleteFunc d, CompareFunc c, CloneFunc cl);

/**
 * Creates a tree iterator with its current node set to 
 * the tree's root.
 * @pre: tree must exist.
 * @pre: tree's root must exist
 * @post: TreeIterator with current = to tree->root.
 * 
 * */
TreeIterator new_tree_iterator(BinaryTree tree);

/***END CONSTRUCTORS***/





/**ACCESSORS**/

/**
 * Function to return the tree's root's data.
 * @pre: tree must exist
 * @pre: tree->root must exist
 * @pre: tree->root->data must exist
 * @post: The root's data
 * @return: The root's data if successful, else NULL
 * */
AnyData get_root_data(BinaryTree tree);


TreeNode get_root(BinaryTree tree);

AnyData get_tree_data(BinaryTree tree, AnyData d);

TreeNode get_tree_node(BinaryTree tree, AnyData d);

int get_tree_height(BinaryTree tree);
int get_size(BinaryTree tree);

/***END ACCESSORS***/



/**DESTROYERS**/

TreeErrorCode destroy_data_tree(BinaryTree tree, AnyData d);

TreeErrorCode remove_root_tree(BinaryTree tree);

TreeErrorCode remove_largest_tree(BinaryTree tree);

TreeErrorCode remove_smallest_tree(BinaryTree tree);

TreeErrorCode destroy_tree_real(BinaryTree* tree);

/***END DESTROYERS***/





/****SETTERS****/

TreeErrorCode add_tree(BinaryTree tree, AnyData d);

TreeErrorCode set_tree_height(BinaryTree tree);
/***END SETTERS***/



/***ITERATORS***/

AnyData next_tree_element(TreeIterator itr, TraversalOrder order);

/***MUTATORS***/

String tree_to_string(BinaryTree tree, TraversalOrder order);

AnyData tree_to_array(BinaryTree tree, TraversalOrder order);

TreeErrorCode balance_tree(BinaryTree tree);

/**END MUTATORS***/



/***VALIDATORS***/
bool is_empty(BinaryTree tree);

bool is_root(BinaryTree tree, TreeNode node);
bool is_leaf(TreeNode node);

bool is_root_data(AnyData d);
bool is_leaf_data(AnyData d);

bool has_two_children(TreeNode node);
bool has_one_child(TreeNode node);
bool has_no_children(TreeNode node);

bool contains_tree_data(BinaryTree theTree, AnyData d);
#endif

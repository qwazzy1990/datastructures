

#include "BinaryTree.h"



/***STATIC FUNCTIONS***/

static AnyData _____return_tree_data(TreeNode root, AnyData d, CompareFunc compareData){
    if(root == NULL){
        return NULL;
    }
    else if(compareData(root->data, d)==0){
        return root->data;
    }
    else if(compareData(root->data, d) < 0){
        return _____return_tree_data(root->rightChild, d, compareData);
    }
    else{
        return _____return_tree_data(root->leftChild, d, compareData);
    }

}

static int _____max(int a, int b)
{
    if(a > b)return a;
    else return b;
}

static int _____return_tree_height(TreeNode root)
{
    if(root == NULL)
    {
        return 0;
    }
    else{
        int leftCount = _____return_tree_height(root->leftChild);
        int rightCount = _____return_tree_height(root->rightChild);
        return _____max(leftCount, rightCount)+1;
    }
}

static bool _____contains_tree_data(TreeNode root, AnyData d, CompareFunc c)
{
    if(root == NULL)return false;
    else if(c(root->data, d)==0){
        return true;
    }
    else if(c(root->data, d)<0){
        return _____contains_tree_data(root->rightChild, d, c);
    }
    else{
        return _____contains_tree_data(root->leftChild, d, c);
    }
}

static void _____add_tree(BinaryTree tree, TreeNode root, TreeNode node) //struct TreeNode* root
{
    if(root == NULL){
        root = node;
        return;
    }
    else if(tree->compareData(root->data, node->data)<0){
        if(root->rightChild == NULL){
            root->rightChild = node;
            return;
        }
        else{
            _____add_tree(tree, root->rightChild, node);
        }
    }
    else{
        if(root->leftChild == NULL){
            root->leftChild = node;
            return;
        }
        else{
            _____add_tree(tree, root->leftChild, node);
        }
    }
}


static void _____tree_to_array(void*** array, TreeNode root, TraversalOrder order)
{
    //if
    if(order == IN_ORDER){
        if(root == NULL){
            return;
        }
        //else
        else{
            _____tree_to_array(array, root->leftChild, order);
            int i = 0;
            //while
            while((*array)[i] != NULL){
                i++;
            }//endwhile
            (*array)[i] = root->data;
            _____tree_to_array(array, root->rightChild, order);
        }//end else
    }//endif

    //end else if
    else if(order == PRE_ORDER){
        if(root == NULL){
            return;
        }
        //else
        else{
            int i = 0;
            //while
            while((*array)[i] != NULL){
                i++;
            }//endwhile
            (*array)[i] = root->data;
            _____tree_to_array(array, root->leftChild, order);
            _____tree_to_array(array, root->rightChild, order);
        }//end else
    }//ens else if

    //else
    else{
        if(root == NULL)return;
        //else
        else{
            _____tree_to_array(array, root->leftChild, order);
            _____tree_to_array(array, root->rightChild, order);
            int i = 0;
            //while
            while((*array)[i] != NULL){
                i++;
            }//endwhile
            (*array)[i] = root->data;

        }//end else
    }//end else
}


static void _____delete_tree(TreeNode root, DeleteFunc del)
{
    if(root == NULL){
        return;
    }
    else{
        _____delete_tree(root->leftChild, del);
        _____delete_tree(root->rightChild, del);
        del(root->data);
        clear(root);
    }

}

static void _____pseudo_delete_tree(TreeNode root)
{
    if(root == NULL){
        return;
    }else{
        _____pseudo_delete_tree(root->leftChild);
        _____pseudo_delete_tree(root->rightChild);
        free(root);
    }
}


static void balance_tree_real(BinaryTree* tree, void** array, int size)
{
    if(size == 1){
        add_tree(*tree, array[0]);
        return;
    }
    if(size == 2){
        add_tree(*tree, array[1]);
        add_tree(*tree, array[0]);
        return;
    }
    int partition = size/2;
    add_tree(*tree, array[partition]);

    int firstSize = partition;
    new_object(void**, subArrayOne, firstSize);
    forall(firstSize){
        subArrayOne[x] = array[x];
    }


    int secondSize = size - partition - 1;
    new_object(void**, subArrayTwo, secondSize);

    int count = partition+1;
    forall(secondSize){
        subArrayTwo[x] = array[count];
        count++;
    }

    balance_tree_real(tree, subArrayOne, firstSize);
    balance_tree_real(tree, subArrayTwo, secondSize);
    free(subArrayOne);
    free(subArrayTwo);

}
/***END STATIC FUNCTIONS***/



/***CONSTRUCTORS**/

TreeNode new_tree_node(AnyData d)
{
    if(d == NULL)return NULL;
    new_object(TreeNode, newNode, 1);
    newNode->data = d;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

BinaryTree new_tree(PrintFunc p, DeleteFunc d, CompareFunc c)
{
    if(p == NULL || d == NULL || c == NULL)return NULL;
    new_object(BinaryTree, newTree, 1);
    newTree->printData = p;
    newTree->deleteData = d;
    newTree->compareData = c;
    newTree->cloneData = NULL;
    newTree->height = 0;
    newTree->size = 0;
    newTree->root = NULL;
    return newTree;
}

BinaryTree new_tree_two(PrintFunc p, DeleteFunc d, CompareFunc c, CloneFunc cl)
{
    if(p == NULL || d == NULL || c == NULL || cl == NULL)return NULL;
    new_object(BinaryTree, newTree, 1);
    newTree->printData = p;
    newTree->deleteData = d;
    newTree->compareData = c;
    newTree->cloneData = cl;
    newTree->height = 0;
    newTree->size = 0;
    newTree->root = NULL;
    return newTree;


}

TreeIterator new_tree_iterator(BinaryTree tree)
{
    TreeIterator newIterator;
    newIterator.current = tree->root;
    return newIterator;
}
/***END CONSTRUCTORS***/


/***ACCESSORS***/

AnyData get_root_data(BinaryTree tree)
{
    if(tree == NULL)return NULL;
    if(tree->size == 0)return NULL;
    return tree->root->data;
}

TreeNode get_root(BinaryTree tree)
{
    if(tree == NULL)return NULL;
    if(tree->size == 0)return NULL;
    return tree->root;
}

AnyData get_tree_data(BinaryTree tree, AnyData d)
{
    if(tree == NULL)return NULL;
    if(d == NULL)return NULL;
    if(tree->size == 0)return NULL;
    if(contains_tree_data(tree, d)==false)return NULL;
    TreeNode root = tree->root;
    CompareFunc compareData = tree->compareData;
    AnyData data = _____return_tree_data(root, d, compareData);
    if(data == NULL)return NULL;
    return data;
}

int get_tree_height(BinaryTree tree)
{
    if(tree == NULL)return -1;
    if(tree->size == 0)return 0;
    int height = _____return_tree_height(tree->root);
    return height;
}

int get_tree_size(BinaryTree tree)
{
    if(tree == NULL)return -1;
    return tree->size;
}

/***END ACCESSORS***/




/***SETTERS***/

TreeErrorCode add_tree(BinaryTree tree, AnyData d)
{
    if(tree == NULL)return DNE_TREE;
    if(d == NULL)return DNE_TREE;
    if(tree->size == 0){
        TreeNode newNode = new_tree_node(d);
        tree->root = newNode;
        tree->size++;
        return OK_TREE;
    }
    if(contains_tree_data(tree, d))return DUPLICATE_VALUE_TREE;
    TreeNode newNode = new_tree_node(d);
    TreeNode root = tree->root;
    _____add_tree(tree, tree->root, newNode);
    tree->size++;
    return OK_TREE;
}

TreeErrorCode set_tree_height(BinaryTree tree)
{
    if(tree == NULL)return DNE_TREE;
    if(tree->root == NULL){
        printf("WHY!!\n");
    }
    if(tree->size == 0){
        tree->height = 0;
    }
    else if(tree->size == 1){
        tree->height = 1;
    }
    else{
        tree->height = get_tree_height(tree);
    }
    return OK_TREE;
}

/***END SETTERS***/


/***DESTROYERS****/

TreeErrorCode destroy_data_tree(BinaryTree tree, AnyData d)
{
    if(tree == NULL)return DNE_TREE;
    if(d == NULL)return DNF_TREE;
    if(tree->size == 0)return DNF_TREE;
    if(contains_tree_data(tree, d)==false)return DNF_TREE;

    AnyData* array = tree_to_array(tree, PRE_ORDER);
    _____pseudo_delete_tree(tree->root);
    int n = tree->size;
    tree->size = 0;
    int index = -1;
    forall(n){
        if(tree->compareData(array[x], d) != 0){
            add_tree(tree, array[x]);
        }
        else{
            index = x;
        }
    }
    tree->deleteData(array[index]);
    clear(array);
    return OK_TREE;

}

TreeErrorCode destroy_tree_real(BinaryTree* tree)
{
    if(tree == NULL)return DNE_TREE;
    if(*tree == NULL)return DNE_TREE;
    if((*tree)->size == 0){
        (*tree)->size = 0;
        (*tree)->height = 0;
        clear(*tree);
        *tree = NULL;
        return OK_TREE;
    }
    TreeNode root = (*tree)->root;
    DeleteFunc deleteData = (*tree)->deleteData;
    _____delete_tree(root, deleteData);
    (*tree)->size = 0;
    (*tree)->height = 0;
    clear(*tree);
    *tree = NULL;
    return OK_TREE;
}

/***END DESTROYERS**/




/****MUTATORS****/

AnyData tree_to_array(BinaryTree tree, TraversalOrder order)
{
    if(tree == NULL)return NULL;
    if(tree->root == NULL)return NULL;
    if(tree->size == 0)return NULL;
    void** array = calloc(tree->size+1, sizeof(void*));
    TreeNode root = tree->root;
    forall(tree->size+1){
        array[x] = NULL;
    }
    _____tree_to_array(&array, root, order);
    return (void*)array;

}

String tree_to_string(BinaryTree tree, TraversalOrder order)
{
    if(tree == NULL)return NULL;
    if(tree->size == 0)return NULL;
    if(tree->root == NULL)return NULL;
    AnyData* array = tree_to_array(tree, order);
    new_object(String, str, 999);
    strcpy(str, "");
    String temp = NULL;
    int memSize = 999;
    forall(tree->size){
      
           temp = tree->printData(array[x]);
           memSize += (stringlen(temp)+10);
           str = realloc(str, memSize);
           strcat(str, temp);
           strcat(str, "\n");
           destroystring(temp);
    }
    clear(array);

    return str;

}

TreeErrorCode balance_tree(BinaryTree tree)
{
    if(tree == NULL) return DNE_TREE;
    if(tree->size == 0)return DNF_TREE;
    if(tree->size == 1)return OK_TREE;
    if(tree->root == NULL)return DNF_TREE;


    AnyData* array = tree_to_array(tree, IN_ORDER);
    CompareFunc compareData = tree->compareData;
    int size = sizeof(array)/sizeof(array[0]);
    qsort(array, size, sizeof(array[0]), compareData);
    int treeSize = tree->size;
    TreeNode root = tree->root;
    _____pseudo_delete_tree(root);


    tree->size = 0;
    tree->height = 0;
    balance_tree_real(&tree, array, treeSize);
    tree->size = treeSize;
    set_tree_height(tree);
    clear(array);
    return OK_TREE;

}

/****END MUTATORS***/





/***VALIDATORS***/

bool contains_tree_data(BinaryTree tree, AnyData d)
{
    if(tree == NULL)return false;
    if(d == NULL)return false;
    if(tree->size == 0)return false;
    if(tree->root == NULL)return false;
    CompareFunc c = tree->compareData;
    TreeNode root = tree->root;
    return _____contains_tree_data(root, d, c);
}

bool is_empty(BinaryTree theTree)
{
    if(theTree == NULL)return false;
    if(theTree->size == 0)return true;
    return false;
}

bool is_root(BinaryTree tree, TreeNode node)
{
    if(tree == NULL)return false;
    if(node == NULL)return false;
    if(tree->size == 0)return false;
    if(tree->root == NULL)return false;
    if(sameobject(tree->root, node))return true;
    return false;
}

bool is_leaf(TreeNode node)
{
    if(node == NULL)return false;
    if(node->leftChild == NULL && node->rightChild == NULL)return true;
    return false;
}

bool has_one_child(TreeNode node)
{
    if(node == NULL)return false;
    if(node->leftChild == NULL && node->rightChild != NULL)return true;
    else if(node->rightChild == NULL && node->leftChild != NULL)return true;
    else return false;
}

bool has_two_children(TreeNode node){
    if(node == NULL)return false;
    if(node->leftChild != NULL && node->rightChild != NULL)return true;
    else return false;
}

/***END VALIDATORS***/
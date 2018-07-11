#include "BinaryTree.h"



bool debug1 = true;
bool debug2 = false;
bool debug3 = false;
int main(int argc, char* argv[])
{

    if(debug1){
        BinaryTree newTree = new_tree(dummy_print, dummy_delete, dummy_compare);
        new_object(Int, a, 1);
        new_object(Int, b, 1);
        new_object(Int, c, 1);
        *a = 3;
        *b = 7;
        *c = 12;
        add_tree(newTree, a);
        add_tree(newTree, b);
        add_tree(newTree, c);
        /*a = newTree->root->data;
        b = newTree->root->leftChild->data;
        c = newTree->root->rightChild->data;*/
        new_object(Int, d, 1);
        *d = 13;
        add_tree(newTree, d);
        new_object(Int, e, 1);
        *e = 17;
        add_tree(newTree, e);
        /*printf("%d\n", *a);
        printf("%d\n", *b);
        printf("%d\n", *c);
        printf("%d\n", *d);*/

        Int* array = tree_to_array(newTree, IN_ORDER);
       /* while(array[i] != NULL){
            Int temp = array[i];
            printf("Array %d\n", *temp);
            i++;
        }*/

        String printer = tree_to_string(newTree, PRE_ORDER);
        //printf("%s", printer);
        destroystring(printer);
        //destroy_data_tree(newTree, d);
        printf("%d\n", get_tree_height(newTree));
        balance_tree(newTree);
        printf("%d\n", newTree->height);
        //printer = tree_to_string(newTree, PRE_ORDER);
        //printf("%s\n", printer);
        destroy_tree(newTree);
        clear(array);


    }
    if(debug2){
        //do shit
    }
    if(debug3){
        //do shit
    }
    return 0;
}
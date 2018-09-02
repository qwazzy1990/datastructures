#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

String printInt(AnyData d)
{
    String p = "1010";
    return p;
}


static bool debug1 = true;
static bool debug2 = false;
static bool debug3 = false;
int main(int argc, char* argv[])
{
    if(debug1){
        ArrayList a = new_arraylist(dummy_print, dummy_delete, dummy_compare);
    
        a->add(a, "Zebra", dummy_print, dummy_delete, dummy_compare);
        add_list(a, "Individual", dummy_print, dummy_delete, dummy_compare);
        add_list(a, "Integer", dummy_print, dummy_delete, dummy_compare);
        new_object(Int, b, 1);
        *b = 7;
        a->insert_back(a, "Integer", b);
        new_object(Int, c, 1);
        *c = 12;
        a->insert_back(a, "Integer", c);
        P("Before %p\n", &b);
        //a->destroy_object_arraylist(a, b);
        P("After %p\n", b);
        a->sort(a);
        //a->remove_list(a, "Integer");
         String printer = print_arraylist(a);
         printf("%s\n", printer);
         clear(printer);
        destroy_arraylist(a);
    }
    if(debug2){
        ArrayList a = new_arraylist(dummy_print, dummy_delete, dummy_compare);
        a->add(a, "Numbers", dummy_print, dummy_delete, dummy_compare);
        new_object(Int, num1, 1);
        *num1 = 12;
        new_object(Int, num2, 1);
        *num2 = 11;
        a->insert_back(a, "Numbers", num1);
        a->insert_back(a, "Numbers", num2);
        destroy_object_arraylist(a, num1);
        //a->destroy_arraylist(a);
    }
    if(debug3){
        //do shit
    }
    return 0;
}
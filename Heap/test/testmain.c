

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Heap.h"

String PRINTER = NULL;
int main(int argc, char *argv[])
{

    #ifdef DEBUG1
        new_object(Int, a, 1);
        new_object(Int, b, 1);
        new_object(Int, c, 1);
        new_object(Int, d, 1);
        new_object(Int, e, 1);
        new_object(Int, f, 1);
        new_object(Int, g, 1);
        new_object(Int, h, 1);

        *a = 1;
        *b = 3;
        *c = 7;
        *d = 10;
        *e = 333;
        *f = 400;
        *g = 700;
        *h = 1000;

        Heap heap = new_heap(MAX, 7, dummy_print, dummy_delete, dummy_compare);
        insert_data_heap(heap, b);
        insert_data_heap(heap, c);
        insert_data_heap(heap, d);
        insert_data_heap(heap, a);
        insert_data_heap(heap, e);
        insert_data_heap(heap, f);
        insert_data_heap(heap, g);
        insert_data_heap(heap, h);

        forall(heap->size)
        {
            int *temp = heap->heapArray[x];
            printf("%d\n", (*temp));
        }

        int *temp = get_parent_data(heap, c);
        if (temp == NULL)
        {
            printf("Success\n");
        }
        else
        {
            printf("%d\n", *temp);
        }

        set_heap_height(heap);
        printf("height is %d\n", heap->height);
        destroy_root_data_heap(heap);

        destroy_heap(heap);
    #endif

    #ifdef DEBUG2
        new_object(Int, a, 1);
        new_object(Int, b, 1);
        new_object(Int, c, 1);
        new_object(Int, d, 1);
        new_object(Int, e, 1);
        new_object(Int, f, 1);
        new_object(Int, g, 1);
        new_object(Int, h, 1);

        *a = 1;
        *b = 3;
        *c = 7;
        *d = 10;
        *e = 333;
        *f = 400;
        *g = 700;
        *h = 1000;

        Heap heap = new_heap(MAX, 7, dummy_print, dummy_delete, dummy_compare);

        heap->add(heap, a);
        heap->add(heap, e);
        heap->add(heap, c);
        heap->add(heap, h);
        heap->add(heap, f);
        heap->add(heap, d);
        heap->add(heap, g);
        heap->add(heap, b);
        
        PRINTER = heap->print(heap);
        clear(PRINTER);
        heap->destroy_root(heap);
        heap->destroy(heap);
    #endif
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Heap.h"
#include "Merge.h"
#include "QuickSort.h"

int main()
{
   /**
	Testing HeapAPI
   */
    int i = 0;
    int arr[10] = {3, 1, 4, 5, 19, 33, 2, 90, 17, 22};
    int size = 10;
    quickSort(arr, 0, 9);
    for(i = 0; i < size; i++){
	printf("%d\n", arr[i]);
    }

 









    return 0;


}

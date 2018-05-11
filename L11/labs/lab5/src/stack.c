#include "StackAPI.h"

Stack *initializeStack(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
	Stack * s = malloc(sizeof(Stack));
	s->list = initializeList(printFunction,deleteFunction,compareFunction);
	s->count = 0;
	return s;
}

void push(Stack *stack, void *toBeAdded)
{
	insertBack(stack->list, toBeAdded);
	stack->count++;
}

void* top(Stack *stack)
{
	if(isEmpty(stack))
		return NULL;
	return getFromBack(stack->list);
}

void pop(Stack *stack)
{
	if( stack )
	{
		// Get the data at the top of the stack
		void* data = top(stack);	

		// Use the data to delete the node from the list
		int result = deleteNodeFromList(stack->list, data );
	
		// If successful, we can lower our count
		if(result == EXIT_SUCCESS)
			stack->count--;
	}
}

int isEmpty( Stack * s) 
{
	return count(s) == 0;
}
 
int count(const Stack * s)
{
	return s->count;
}

void deleteStack( Stack * s )
{
	deleteList(s->list);
	s->list = NULL;
	free(s);
}
	


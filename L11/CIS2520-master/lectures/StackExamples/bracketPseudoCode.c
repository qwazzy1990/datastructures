/**
 * This program receives () and [] statements in any order annd
 * determines if each '(' or '[' has a matching ')' or ']' pair.
 *
 * The logic is whenever  we see a ) or ] we check if the previous 
 * character was a [ or ( because we know those are closed matches.
 * By removing internal () and [] matching characters we should eventually 
 * be able to remove the outer () and [] unless the statement 
 * wasn't valid to begin with.
 *
 * Interface for this stack only
 * void* top(stack) -> retrieves top value from stack
 * void* pop(stack) -> retrieves top value from stack and removes it.
 * void push(stack,void data); ->  Push data onto the stack.
 * isEmpty(stack);  -> returns if the stack is currently empty
 */

int main( int argc, char ** argv )
{
	Stack * stack = malloc(sizeof(Stack));

	char ch;
	ch = getchar();
	while( ch != '\n' && ch != EOF )
	{
		char* stackTop = (char*)top(stack);
		if( stackTop == '[' && ch == ']')
		{
			// Pop off the '['
			pop(stack);
		}
		else if( stackTop == '(' && ch == ')')
		{
			// Pop off the '('
			pop(stack);
		}
		else
			push(stack,ch);

		ch = getchar();
	}

	if( isEmpty(stack) )
		printf("Valid statement!\n");
	else
		pritnf("Statement was not valid!\n");
}	

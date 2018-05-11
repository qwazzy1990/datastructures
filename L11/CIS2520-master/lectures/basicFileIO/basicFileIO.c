#include <stdlib.h>
#include <stdio.h>

int main( int argc, char ** argv )
{
	// Reading from command line
	int value;
	char ch;
	scanf("%d %c", &value, &ch);
	printf("%c %d\n", ch, value);


	// Same thing except from a file
	FILE * file = fopen("input.txt", "r");

	if(file)
	{
		fscanf(file, "%d %c", &value, &ch);
		printf("%c %d\n", ch, value);
	}

	fclose(file);

	FILE *outFile =fopen("output.txt", "w");
	printf( "WRITING TO FILE %d %d\n%c %c\n", value, value, ch, ch);
	fprintf(outFile, "%d %d\n%c %c\n", value, value, ch, ch);
	fclose(outFile);


	return 0;
}

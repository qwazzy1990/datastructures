#include "FileReader.h"

void loadFile( char * filename, LinkedList *players )
{
    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("ERROR");
        exit(1);
    }
    
    char ch;
    int value;
    char line[80];
    while( fgets(line,80,file) != NULL )
    {
        Card * c = malloc(sizeof(Card));
        sscanf(line,"%c %d", &ch, &value);
        c->suit = ch;
        c->value = value;
        printf("CARD SUIT %c\n", c->suit);
        printf("CARD VALUE %d\n", c->value);

        Player * p = createPlayer()
        players->insertBack(p)
    }
    fclose(file);
}

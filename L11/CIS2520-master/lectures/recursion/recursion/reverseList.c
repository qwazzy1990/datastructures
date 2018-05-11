#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node* next;
    int data;

} Node;

void printList( Node* list )
{
    Node * head = list;
    while(head != NULL)
    {
        printf("%d ", head->data );
        head = head->next;
    }
    printf("\n End of List\n");
    
}

Node* reverseList( Node* prev, Node * head )
{
    // Stop at the last item
    if( head == NULL )
    {
        return prev;
    }
    else
    {
        Node * next = head->next;
        //This is our flip.
        head->next = prev;
        return reverseList(head,next);
    }
}

int main( int argc, char ** argv )
{
    Node * a = malloc(sizeof(Node));
    a->next = NULL;
    a->data = 5;
    
    Node * b = malloc(sizeof(Node));
    b->next = a;
    b->data = 6;
    
    Node * c = malloc(sizeof(Node));
    c->next = b;
    c->data = 7;
    
    Node * d = malloc(sizeof(Node));
    d->next = c;
    d->data = 8;
    
    
    printList(d);
    
    Node * fhead = reverseList(NULL, d);
    printList(fhead);
    
    printf("\n End of Program ");
}
#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int number;
    struct node *next;
}node;

node* head;

void printLinkedList()
{
    for(node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }
}

/*
 * Inserts a node at the beginning of the linked list
 * */
void insertAtBeginning(int x)
{
    node *tmp = malloc(sizeof(node));
    tmp->number = x;
    tmp->next = NULL;

    //The beginning of the list will now point to the newly created node
    head = tmp;
}

/*
 * Inserts a node at n-th position
 * */
void insertAtPosition(int number, int position)
{
    node *tmp = malloc(sizeof(node));
    tmp->number = number;
    tmp->next = NULL;

    //If we wish to insert at position 1, then we need to set
    //the next value to the beginning of the list
    if(position == 1)
    {
        tmp->next = head;
        //Then we need set the beginning of the list to the created list
        head = tmp;
        return;
    }

    node *tmp1 = head;
    for(int i = 0; i < position -2; i++)
    {
        tmp1 = tmp1->next;
    }

    tmp1->next = tmp->next;
    tmp1-> next = tmp;
}


int main() {
    head = NULL;
    insertAtPosition(2,1);
    insertAtPosition(3,2);
    insertAtPosition(4,3);
    insertAtPosition(5,4);
    printLinkedList();
    return 0;
}

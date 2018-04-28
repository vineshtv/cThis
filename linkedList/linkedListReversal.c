/*
 *  Reverses a singly linked list using the iterative method.
 */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void reverse(struct Node** head)
{
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

void push(struct Node** head, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = (*head);
    *head = newNode;
}

void printlist(struct Node* head)
{
    struct Node *itr = head;
    while (itr != NULL)
    {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printlist(head);
    reverse(&head);
    printlist(head);
    
    return 0;
}

/*
 * Creates a circular linked list and has a function which deletes a node given just a pointer to the node
 */
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void insertCircular(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(!(*head))
    {
        newNode->data = data;
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while(curr->next != *head)
    {
        curr = curr->next;
    }

    newNode->data = data;
    newNode->next = curr->next;
    curr->next = newNode;

}

void deleteNodeWithJustAPointer(struct Node* node)
{
    struct Node* curr = node;
    while(curr->next != node)
    {
        curr = curr->next;
    }

    curr->next = node->next;
    free(node);
}

void printCircularLinkedList(struct Node* head)
{
    if(!head)
    {
        return;
    }

    struct Node* curr = head;

    do{
        printf("%d ", curr->data);
        curr = curr->next;
    }while(curr != head);

    printf("\n");
}

int main(int argc, char** argv)
{
    struct Node* head = NULL;
    insertCircular(&head, 10);
    insertCircular(&head, 20);
    insertCircular(&head, 30);
    insertCircular(&head, 40);
    insertCircular(&head, 50);
    insertCircular(&head, 60);
    printCircularLinkedList(head);

    int i;
    struct Node* node = head;
    for(i = 0; i < 3; i++)
    {
        node = node->next;
    }

    deleteNodeWithJustAPointer(node);
    printCircularLinkedList(head);
    return 0;
}

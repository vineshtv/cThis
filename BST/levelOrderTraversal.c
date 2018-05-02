/*
 *  A function which prints level order traversal of a tree
 */
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void inOrderPrint(struct Node* node)
{
    if(node)
    {
        inOrderPrint(node->left);
        printf("%d ", node->data);
        inOrderPrint(node->right);
    }
}

int getHeight(struct Node* node)
{
    if(!node)
    {
        return 0;
    }

    int lheight = getHeight(node->left);
    int rheight = getHeight(node->right);

    if(lheight > rheight)
    {
        return(lheight + 1);
    }
    else
    {
        return(rheight + 1);
    }
}

void printLevel(struct Node* node, int level)
{
    if(!node)
    {
        return;
    }

    if(level == 0)
    {
        printf("%d ", node->data);
    }
    else
    {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }

}

void levelOrderTraversal(struct Node* node)
{
    int height = getHeight(node);

    int i;
    for(i = 0; i < height; i++)
    {
        printLevel(node, i);
    }
}

int main()
{
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->left->left->left = createNode(7);

    printf("In order traversal : ");
    inOrderPrint(root);
    printf("\n");

    printf("Level order traversal : ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}

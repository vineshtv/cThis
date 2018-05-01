/*
 * Checks whether a Binary tree is a BST. 
 * Uses a simple inorder traversal and checks if the current number is greater than the previous number.
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

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

bool myCheckBSTUtil(struct Node* node)
{
    static int n = INT_MIN;
    if(node)
    {
        if(!myCheckBSTUtil(node->left))
        {
            return false;
        }
        
        if(node->data < n)
        {
            return false;
        }
        else
        {
            n = node->data;
        }

        if(!myCheckBSTUtil(node->right))
        {
            return false;
        }
    }
    return true;
}

bool checkBST(struct Node* root)
{
    if(!root)
    {
        return false;
    }
    
    bool result = myCheckBSTUtil(root);
    return result;
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

int main(int argc, char** argv)
{
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    
    struct Node* temp;

    temp = root->left;
    temp->left = createNode(3);
    temp->right = createNode(7);

    temp = temp->right;
    temp->left = createNode(6);
    temp->right = createNode(8);

    temp = root->right;
    temp->left = createNode(14);
    temp->left->left = createNode(13);

    temp->right = createNode(17);
    temp->right->left = createNode(1);
    inOrderPrint(root);
    printf("\n");
    
    bool isBST = checkBST(root);
    if(isBST)
    {
        printf("Binary tree is BST.\n");
    }
    else
    {
        printf("Binary tree is not BST.\n");
    }
    return 0;
}

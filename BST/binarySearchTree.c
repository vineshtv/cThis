#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* node, int data)
{
    if(!node)
    {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    //Traverse and insert the new node in the correct position
    if(data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }

    //This return is uneccessary
    return node;
}

//Inorder traversal always prints the number is the sorted order in a BST
void inOrderTraverse(struct Node* root)
{
    if(root)
    {
        inOrderTraverse(root->left);
        printf("%d ", root->data);
        inOrderTraverse(root->right);
    }
}

int main(int argc, char** argv)
{
    // Create the root node with the first 
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 10;
    root->left = NULL;
    root->right = NULL;

    //Insert some nodes 
    insert(root, 9);
    insert(root, 11);
    insert(root, 21);
    insert(root, 30);
    insert(root, 1);
    insert(root, 3);

    printf("In Order Traversal = ");
    inOrderTraverse(root);
    printf("\n");
    return 0;
}

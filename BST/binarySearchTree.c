#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

//Insert into the BST
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

struct Node* getMinNode(struct Node* node)
{
    struct Node* curr = node;
    
    while(curr->left)
    {
        curr = curr->left;
    }

    return(curr);
}

//delete a key from the BST
struct Node* deleteNode(struct Node* root, int data)
{
    if(!root)
    {
        return root;
    }

    //Traverse and find the Node with the key to be deleted
    if(data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        //Node with the key is found.
        /*
         * Steps to delete the node are as follows
         * 1. If the Node does not have any child, just delete the node and return NULL.
         * 2. If the Node has only one child, then copy the child to the node and delete the child.
         * 3. If the Node had two childs, then find the in-order successor to the node, copy that succesor to the node and delete the successor.
         */
        if(root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node has two childs.
        struct Node* temp = getMinNode(root->right);

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return(root);
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

    root = deleteNode(root, 9);
    inOrderTraverse(root);
    printf("\n");
    return 0;
}

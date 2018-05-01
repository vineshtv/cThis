/*
 *  Add two numbers which are represented by two linked lists.
 */
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createList(unsigned long long n)
{
    struct Node* num = NULL;
    while(n)
    {
        int digit = n % 10;
        n = n / 10;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = digit;
        newNode->next = num;
        num = newNode;
    }

    return num;
}

void printNum(struct Node* head)
{
    struct Node* curr = head;
    while(curr)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int findSize(struct Node* head)
{
    int size = 0;
    struct Node* curr = head;
    while(curr)
    {
        size++;
        curr = curr->next;
    }

    return size;
}

/*
 *  Takes two linked lists of the same size, adds them and stores the result in the results linked list.
 *  The carry will denote the final carry at the end of the addition operation.
 */
void addSameOrderNumbers(struct Node* num1, struct Node* num2, struct Node** result, int *carry)
{
    //End of recursion.
    if(num1 == NULL && num2 == NULL)
    {
        return;
    }

    //recurively traverse both the linked lists.
    addSameOrderNumbers(num1->next, num2->next, result, carry);
    int sum = num1->data + num2->data + *carry;
    if(sum >= 10)
    {
        *carry = sum / 10;
        sum = sum % 10;
    }
    else
    {
        *carry = 0;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = sum;
    newNode->next = *result;
    *result = newNode;
}

/*
 * Takes the longer linked list and propagates the carry from the current node(indicated by curr)
 * to the MSB and adds it to the results array recursively.
 * The variable carry will contain the final carry from the sum of the two linked lists.
 */
void propagateCarry(struct Node* num1, struct Node* curr, struct Node** result, int *carry)
{
    if(num1 != curr)
    {
        propagateCarry(num1->next, curr, result, carry);

        int sum = num1->data + *carry;
        *carry = sum / 10;
        sum = sum % 10;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum;
        newNode->next = *result;
        *result = newNode;
    }
}

struct Node* findSum(struct Node* num1, struct Node* num2)
{
    int size1 = 0, size2 = 0;
    size1 = findSize(num1);
    size2 = findSize(num2);

    struct Node* result = NULL;
    int carry = 0;
    int diff = 0;

    // For ease of use, let's keep the higher order number as num1.
    // Note: Somethings Can possibly be optimized here.
    if(size2 > size1)
    {
        struct Node* temp = num1;
        num1 = num2;
        num2 = temp;

        diff = size2 - size1;
    }
    else
    {   
        diff = size1 - size2;
    }

    // Again some variables which are not really necessary, but they help in readability.. I think.
    struct Node* head1 = num1;
    struct Node* head2 = num2;
    int i;

    if (diff != 0)
    {
        /*
         * In the case the numbers are of different orders, then first traverse the 
         * longer linked list until 'diff' number of nodes are over and then call 
         * the addSameOrderNumbers function as though the linked lists are of the same sizes.
         */
        for(i = 0; i < diff; i++)
        {
            head1 = head1->next;
        }
        
        addSameOrderNumbers(head1, head2, &result, &carry);

        //Now propagate the carry to the higher order digits of the longer list.
        propagateCarry(num1, head1, &result, &carry);
    }
    else
    {   
        // Numbers are of the same order, just add them.
        addSameOrderNumbers(head1, head2, &result, &carry);
    }

    // If any carry is remaining, then add that carry directly as the MSB of the result.
    if(carry != 0)
    {
        struct Node* finalCarry = (struct Node*)malloc(sizeof(struct Node));
        finalCarry->data = carry;
        finalCarry->next = result;
        result = finalCarry;
    }

    return result;
}

int main()
{
    unsigned long long int a, b;

    printf("Enter 2 numbers: ");
    scanf("%llu %llu", &a, &b);

    struct Node* num1 = createList(a);
    struct Node* num2 = createList(b);

    printf("\nNumbers are :\n");
    printNum(num1);
    printNum(num2);

    struct Node* sum = findSum(num1, num2);
    printf("Result = ");
    printNum(sum);

    return 0;
}

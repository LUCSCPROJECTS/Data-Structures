#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d -> ", n->data);
        n = n->next;
    }
}

// Insert Node an beginning
void push(struct Node **head, int newdata)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = newdata;
    new_node->next = *head;
    *head = new_node;
}

void insertAfter(struct Node *prev, int new_data)
{
    if (prev == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void insertBefore(struct Node *after, int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;

    node->next = after->next;
    after->next = node;
}

void append(struct Node **head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;

    new_node->data = data;
    new_node->next = NULL;

   

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

int search(struct Node *head, int x)
{
    struct Node *current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

int searchRec(struct Node *head, int x)
{
    if (head == NULL)
        return 0;
    if (head->data == x)
        return 1;
    searchRec(head->next, x);
}

int findLength(struct Node *head)
{
    int length = 0;
    struct Node *temp = head;

    while (temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void reverse(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void deleteNodeWithKey(struct Node **head_ref, int data)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == data)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with data %d not found in the list.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void deleteWithPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("The linked list is empty.\n");
        return;
    }
    struct Node *temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    // Now temp pointer points to the previous node of
    // the node to be deleted
    struct Node *del = temp->next; // del pointer points to the node
                                   // to be deleted
    temp->next = temp->next->next;
    printf("\nElement deleted is : %d\n", del->data);
    del->next = NULL;
    free(del); // Node is deleted

    // struct Node *next_node = temp->next->next;
    // free(temp->next);
    // temp->next = next_node;
}

void deleteList(struct Node **head_ref)
{
    struct Node *current = *head_ref;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}

int getNthNode(struct Node *head, int position)
{
    int i = 0;
    struct Node *current = head;
    while (current->next != NULL && i < position)
    {
        current = current->next;
        i++;
    }
    if (current != NULL && current->next != NULL)
        return current->data;

    return -1;
    // OR
    // while (current != NULL) {
    //     if (count == index)
    //         return (current->data);
    //     count++;
    //     current = current->next;
    // }
}

int getNthNodeFromLast(struct Node *head, int position)
{
    int length = 0;
    struct Node *current = head;
    while (current->next != NULL)
    {
        length++;
        current = current->next;
    }
    if (position > length)
        return -1;
    current = head;
    for (int i = 0; i < length - position; i++)
    {
        current = current->next;
    }
    return current->data;
}

// Find kth node from Middle towards Head of a Linked List
// eg :
// Input :  List is 1->2->3->4->5->6->7
//          K= 2
// Output : 2

int printKthfrommid(struct Node *head, int k)
{
    int n = findLength(head);
    int reqNode = ((n / 2 + 1) - k);
    if (reqNode <= 0)
        return 1;
    else
    {
        struct Node *current = head;
        int count = 1;
        while (current != NULL)
        {
            if (count == reqNode)
                return (current->data);
            count++;
            current = current->next;
        }
    }
}

// Find middle of singly linked list Recursively
void midpoint_util(struct Node *head, int *n, struct Node **mid)
{
    // If we reached end of linked list
    if (head == NULL)
    {
        *n = (*n) / 2;
        return;
    }
    *n = *n + 1;

    midpoint_util(head->next, n, mid);
    // Rolling back, decrement n by one
    *n = *n - 1;
    if (*n == 0)
    {
        // Final answer
        *mid = head;
    }
}

struct Node *midpoint(struct Node *head)
{
    struct Node *mid = NULL;
    int n = 1;
    midpoint_util(head, &n, &mid);
    return mid;
}

int numberOfOccurences(struct Node *head, int key)
{
    struct Node *current = head;
    int counter = 0;
    while (current != NULL)
    {
        if (current->data == key)
            counter++;
        current = current->next;
    }
    return counter;
}

int numberOfOccurencesRec(struct Node *head, int key)
{
    static int count = 0;
    if (head == NULL)
        return count;
    if (head->data == key)
        count++;
    return numberOfOccurences(head->next, key);
}

// OR

int numberOfOccurencesRecSecondMethod(struct Node *head, int key)
{
    if (head == NULL)
        return 0;
    if (head->data == key)
        return 1 + numberOfOccurencesRecSecondMethod(head->next, key);
    return numberOfOccurencesRecSecondMethod(head->next, key);
}

int getLengthListRec(struct Node *head)
{
    // static int counter = 0;
    if (head == NULL)
        return 0;
    return getLengthListRec(head->next) + 1;
}

struct Node *getNthNodeFromLastRec(struct Node *head, int n)
{
    if (head == NULL)
    {
        printf("\nERROR IN N");
        return NULL;
    }
    if (getLengthListRec(head) == n)
        return head;
    return getNthNodeFromLastRec(head->next, n);
}

void moveToFront(struct Node **head)
{
    struct Node *last = *head;
    struct Node *prev = *head;

    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }

    last->next = *head;
    prev->next = NULL;
    *head = last;
}

void mergeAndSort(struct Node **h1, struct Node **h2)
{
    struct Node *temp1 = *h1;
    struct Node *temp2 = *h2;
    int l = 0;

    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
        l ++;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
        l ++;
    }
    temp1->next = temp2;
    temp1 = h1;
    temp2 = h1;
    int aux = 0;
    
    for (int i = 0; i < l; i++)
    {
        for (int j = i; i < l; i++)
        {
            if (temp1->data < temp2->data)
            {
                aux = temp1->data;
                temp1->data = temp2->data;
                temp2->data = aux;
            }
        }
    }
}

int main()
{
    /* Start with the empty list */
    struct Node *head = NULL;
    struct Node *head2 = NULL;

    append(&head, 12);
    append(&head, 13);
    append(&head, 14);
    append(&head, 15);

    append(&head2, 1);
    append(&head2, 2);
    append(&head2, 3);
    append(&head2, 4);
    push(&head2, 0);
    // insertAfter(head, 10);

    printf("\nLinked list is: \n");
    // printList(head);

    printf("\nLinked list is: \n");
    // printList(head2);

    mergeAndSort(&head, &head2);
    printf("\nMerged Linked list is: \n");
    printList(head);
    // reverse(&head);
    // deleteNodeWithKey(&head, 25);
    // deleteWithPosition(&head, 3);
    // printf("%d is data\n", getNthNode(head, 22));
    // printf("%d is data\n", getNthNodeFromLast(head, 1));
    // printList(head);

    // // struct Node *middle = midpoint(head);
    // // printf("\n%d is middle of the list\n", middle->data);
    // // printf("\n2 occured %d times\n", numberOfOccurencesRec(head, 2));
    // printf("\nLength :%d\n", getLengthListRec(head));
    // // struct Node *secondFromLast = getNthNodeFromLastRec(head, 9);
    // // printf("\n%d---", secondFromLast->data);

    // moveToFront(&head);

    // searchRec(head, 25) ? printf("Yes") : printf("No");

    return 0;
}
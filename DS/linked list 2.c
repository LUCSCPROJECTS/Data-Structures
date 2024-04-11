#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(" -> ");

        current = current->next;
    }
    printf("\n");
}

void append(struct Node **head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void push(struct Node **head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int checkIfCircular(struct Node *head)
{
    // If linked list is empty it is circular
    if (head == NULL)
        return 1;
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
        if (current->next == head)
            return 1;
    }
    return 0;
}

int checkIfCircularRec(struct Node *head, struct Node *start)
{
    if (head == NULL)
        return 0;
    if (head->next == start)
        return 1;
    return checkIfCircularRec(head->next, start);
}

void printRec(struct Node *head)
{
    if (head == NULL)
        return;
    printRec(head->next);
    printf("%d -> ", head->data);
}

int countNodesInCircularLinkedList(struct Node *head)
{
    struct Node *temp = head;
    int result = 0;
    if (head != NULL)
    {
        do
        {
            temp = temp->next;
            result++;
        } while (temp != head);
    }

    return result;
}

int main()
{
    struct Node *head = NULL;

    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 0);

    // printf("Till Now it's not Circular\n");
    printList(head);
    printf("\n");
    printRec(head);

    checkIfCircularRec(head, head) ? printf("Circular\n") : printf("Singly\n");
    // checkIfCircular(head) ? printf("Circular\n") : printf("Singly\n");

    head->next->next->next->next = head;

    // checkIfCircular(head) ? printf("Circular\n") : printf("Singly\n");
    checkIfCircularRec(head, head) ? printf("Circular\n") : printf("Singly\n");

    // printf("%d", head->next->next->next->data);
    return 0;
}
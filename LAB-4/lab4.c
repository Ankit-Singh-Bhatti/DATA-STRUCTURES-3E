#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct node **head)
{
    struct node *ptr = *head;
    printf("LINKED LIST: ");
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insertatbeg(struct node **head, int data)
{
    struct node *insert = create(data);
    insert->next = *head;
    *head = insert;
}

void insertatend(struct node **head, int data)
{
    struct node *newNode = create(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void insertinbet(struct node **head, int data)
{
    int pos;
    struct node *ptr = *head;
    struct node *insert = create(data);
    printf("Enter the index after which the element is to be inserted:\n");
    scanf("%d", &pos);
    for (int i = 0; i < pos; i++)
    {
        if (ptr == NULL)
        {
            printf("Invalid index\n");
            return;
        }
        ptr = ptr->next;
    }
    insert->next = ptr->next;
    ptr->next = insert;
}

void deleteatbeg(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = *head;
    *head = ptr->next;
    free(ptr);
}

void deleteatend(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *ptr = *head;
    if (ptr->next == NULL)
    {
        free(ptr);
        *head = NULL;
        return;
    }
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

void deleteintbet(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    int ele;
    struct node *ptr = *head;
    printf("Enter the index at which the element is to be removed:\n");
    scanf("%d", &ele);
    if (ele == 0)
    {
        *head = ptr->next;
        free(ptr);
        return;
    }
    for (int i = 0; i < (ele - 1); i++)
    {
        if (ptr == NULL || ptr->next == NULL)
        {
            printf("Invalid index\n");
            return;
        }
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

int main()
{
    struct node *head = NULL;
    int choice, data, ele, insab, insae, insib;
    do
    {
        printf("\nENTER YOUR CHOICE:\n1)CREATION OF LINKED LIST\n2)INSERTION OF AN ELEMENT IN THE LINKED LIST\n3)DELETION OF AN ELEMENT IN THE LINKED LIST\n4)DISPLAY LINKED LIST\n0)EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE NUMBER OF NODES TO BE CREATED:(LESSER THAN OR EQUAL TO 5)\n");
            int n;
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    printf("ENTER THE VALUE OF NODE NUMBER %d \n", (i + 1));
                    scanf("%d", &data);
                    head = create(data);
                }
                else
                {
                    printf("ENTER THE VALUE OF NODE NUMBER %d \n", (i + 1));
                    scanf("%d", &data);
                    insertatend(&head, data);
                }
            }
            break;
        case 2:
            printf("ENTER THE CHOICE:\n1)INSERTION AT BEGINNING\n2)INSERTION AT END\n3)INSERTION IN BETWEEN\n");
            scanf("%d", &ele);
            switch (ele)
            {
            case 1:
                printf("ENTER THE ELEMENT TO BE INSERTED:\n");
                scanf("%d", &insab);
                insertatbeg(&head, insab);
                break;
            case 2:
                printf("ENTER THE ELEMENT TO BE INSERTED:\n");
                scanf("%d", &insae);
                insertatend(&head, insae);
                break;
            case 3:
                printf("ENTER THE ELEMENT TO BE INSERTED:\n");
                scanf("%d", &insib);
                insertinbet(&head, insib);
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 3:
            printf("ENTER THE CHOICE:\n1)DELETION AT BEGINNING\n2)DELETION AT END\n3)DELETION IN BETWEEN\n");
            scanf("%d", &ele);
            switch (ele)
            {
            case 1:
                deleteatbeg(&head);
                break;
            case 2:
                deleteatend(&head);
                break;
            case 3:
                deleteintbet(&head);
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 4:
            printf("LINKED LIST IS:\n");
            display(&head);
            break;
        case 0:
            printf("Exiting program\n");
            break;
        default:
            printf("ENTER A VALID CHOICE\n");
        }
    } while (choice != 0);

    // Free allocated memory before exiting
    struct node *current = head;
    struct node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

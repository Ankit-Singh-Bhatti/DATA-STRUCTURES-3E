#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
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
struct node* concatenate(struct node **head1,struct node** head2)
{
    struct node* head3=NULL;
    struct node* ptr1=*head1;
    struct node* ptr2=*head2;
    while(ptr1!=NULL)
    {
        insertatend(&head3,ptr1->data);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        insertatend(&head3,ptr2->data);
        ptr2=ptr2->next;
    }
    return head3;
};
struct node* reverse(struct node** head) {
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
};
void sort(struct node** head)
{
    int temp;
    struct node* ptr=*head;
    struct node* index=NULL;
    while(ptr!=NULL)
    {
        index=ptr->next;
        while(index!=NULL)
        {
            if(ptr->data > index->data)
            {
                temp=ptr->data;
                ptr->data=index->data;
                index->data=temp;
            }
            index=index->next;
        }
        ptr=ptr->next;
    }
}
int main()
{
    //------------------LL1----------------------------//
    struct node* head1=NULL;
    struct node* first=create(10);
    head1=first;
    insertatend(&head1,20);
    insertatend(&head1,30);
    insertatend(&head1,40);
    insertatend(&head1,50);
    printf("FIRST LINKED LIST:\n");
    display(&head1);
    //------------------LL2----------------------//
    struct node* head2=NULL;
    struct node* first1=create(60);
    head2=first1;
    insertatend(&head2,80);
    insertatend(&head2,70);
    insertatend(&head2,90);
    insertatend(&head2,100);
    printf("SECOND LINKED LIST:\n");
    display(&head2);
    //-------------------------CONCATENATE---------------//
    struct node* head3=concatenate(&head1,&head2);
    printf("CONCATENATED LINKED LIST:\n");
    display(&head3);
    //-------------------------REVERSAL------------------------------//
    struct node* head4=reverse(&head1);
    printf("REVERSED LINKED LIST:\n");
    display(&head4);
    //---------------SORT---------------------//
    sort(&head2);
    printf("SORTED LINKED LIST:\n");
    display(&head2);
    return 0;


}




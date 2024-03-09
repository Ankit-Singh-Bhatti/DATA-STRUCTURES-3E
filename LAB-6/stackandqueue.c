#include<stdio.h> #include<stdlib.h> struct node
{
int data;
struct node* next;
};
struct node* create(int data)
{
struct node* ptr=(struct node*)malloc(sizeof(struct node)); ptr->data=data;
ptr->next=NULL;
};
void push(struct node **head, int data)
{
struct node *insert = create(data); insert->next = *head;
*head = insert;
}
void pop(struct node **head)
{
if (*head == NULL)
{
printf("List is empty\n"); return;
}
struct node *ptr = *head;
*head = ptr->next; free(ptr);
printf("ELEMENT IS DELETED\n");
 
}
void Enqueue(struct node **head, int data)
{
struct node *newNode = create(data); if (*head == NULL)
{
*head = newNode;
}
else
{
struct node *ptr = *head; while (ptr->next != NULL)
{
ptr = ptr->next;
}
ptr->next = newNode;
}
}
void Dequeue(struct node **head)
{
if (*head == NULL)
{
printf("List is empty\n"); return;
}
struct node *ptr = *head;
*head = ptr->next; free(ptr);
printf("ELEMENT IS DELETED\n");
}
void display(struct node **head)
 
{
struct node *ptr = *head; printf("LINKED LIST: ");
while (ptr != NULL)
{
printf("%d ->", ptr->data); ptr = ptr->next;
}
printf("NULL\n");
}
int main()
{
int num,data,choice,insert; struct node*head=NULL; struct node*first=create(50); head=first;
display(&head); do
{
printf("ENTER YOUR CHOICE\n1)PUSH\n2)POP\n3)Enqueue\n4)Dequeue\n5)Display\n6)Exit\n");
scanf("%d",&choice); switch(choice)
{
case 1:
printf("ENTER THE VALUE OF THE NODE:\n");
scanf("%d",&insert); push(&head,insert); break;
case 2:
pop(&head);
 
break; case 3:
printf("ENTER THE VALUE OF THE NODE:\n");
scanf("%d",&insert); Enqueue(&head,insert); break;
case 4:
Dequeue(&head); break;
case 5:
display(&head); break;
case 6:
break; default:
printf("ENTER A VALID CHOICE");
}
}while(choice!=6); printf("END OF PGM"); return 0;
}

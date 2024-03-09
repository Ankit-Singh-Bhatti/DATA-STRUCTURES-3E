#include<stdio.h> #include<stdlib.h> struct node
{
int data;
struct node* prev; struct node* next;
};
void insertatend(struct node** head,int data)
{
struct node* ptr=(struct node*)malloc(sizeof(struct node)); struct node* temp=*head;
if(*head==NULL)
{
ptr->data=data; ptr->next=NULL; ptr->prev=NULL;
*head=ptr;
}
else
{
while(temp->next!=NULL)
{
 
temp=temp->next;
}
ptr->data=data; ptr->next=NULL; ptr->prev=temp; temp->next=ptr;
}
}
void display(struct node** head)
{
struct node* ptr=*head; printf("LINKED LIST:");
while(ptr!=NULL)
{
printf("%d->",ptr->data); ptr=ptr->next;
}
printf("NULL\n");
}
void insertinbet(struct node** head,int data)
{
int pos;
struct node* ptr=*head;
struct node* temp=(struct node*)malloc(sizeof(struct node));
printf("ENTER THE INDEX AT WHICH THE ELEMENT IS TO BE INSERTED TO THE LEFT:\n");
scanf("%d",&pos); for(int i=0;i<(pos-1);i++)
{
ptr=ptr->next;
}
 
temp->data=data; temp->next=ptr->next; ptr->next->prev=temp; ptr->next=temp;
temp->prev=ptr;
}
void deleteNode(struct Node** head, int value) { struct node* current = *head;

// Find the node with the given value
while (current != NULL && current->data != value) { current = current->next;
}


if (current == NULL) {
printf("Value not found in the list\n"); return;
}


// Update the pointers of neighboring nodes if (current->prev != NULL) {
current->prev->next = current->next;
} else {
*head = current->next; // If current is the head node
}
if (current->next != NULL) {
current->next->prev = current->prev;
}


free(current); // Free memory allocated for the deleted node
}
 
int main()
{
struct node* head=NULL; insertatend(&head,10); insertatend(&head,20); insertatend(&head,30); insertatend(&head,40); insertatend(&head,50); display(&head); insertinbet(&head,25); deleteNode(&head,20); printf("DELETING 20\n"); display(&head);
return 0;
}

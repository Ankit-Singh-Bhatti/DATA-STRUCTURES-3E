// Complete the compare_lists function below.
/*
*	For your reference:
*	SinglyLinkedListNode {
*	int data;
*	SinglyLinkedListNode* next;
* };
*	
*/
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) { int count1 = 0, count2 = 0;
SinglyLinkedListNode *ptr1 = head1, *ptr2 = head2; while (ptr1 != NULL) {
count1++;
ptr1 = ptr1->next;
}
while (ptr2 != NULL) { count2++;
ptr2 = ptr2->next;
}
if (count1 != count2) {
 
return false;
}
ptr1 = head1; ptr2 = head2;
while (ptr1 != NULL && ptr2 != NULL) { if (ptr1->data != ptr2->data) {
return false;
}
ptr1 = ptr1->next; ptr2 = ptr2->next;
}
return true;
}

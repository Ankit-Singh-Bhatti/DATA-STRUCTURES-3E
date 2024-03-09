#include <stdio.h> #include <stdlib.h>

// Structure for a node in the binary search tree struct Node {
int data;
struct Node *left; struct Node *right;
};


// Function to create a new node struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); if (newNode == NULL) {
printf("Memory allocation failed\n"); exit(1);
}
newNode->data = data; newNode->left = NULL; newNode->right = NULL;
 
return newNode;
}


// Function to insert a node into the binary search tree struct Node* insert(struct Node* root, int data) {
if (root == NULL) {
return createNode(data);
}
if (data < root->data) {
root->left = insert(root->left, data);
} else if (data > root->data) {
root->right = insert(root->right, data);
}
return root;
}


// Function for in-order traversal of the binary search tree void inOrder(struct Node* root) {
if (root != NULL) { inOrder(root->left); printf("%d ", root->data); inOrder(root->right);
}
}


// Function for pre-order traversal of the binary search tree void preOrder(struct Node* root) {
if (root != NULL) { printf("%d ", root->data); preOrder(root->left); preOrder(root->right);
 
}
}


// Function for post-order traversal of the binary search tree void postOrder(struct Node* root) {
if (root != NULL) { postOrder(root->left); postOrder(root->right); printf("%d ", root->data);
}
}


// Function to display the elements in the binary search tree void display(struct Node* root) {
printf("Elements in the binary search tree: "); inOrder(root);
printf("\n");
}


int main() {
struct Node* root = NULL;


// Construct the binary search tree root = insert(root, 50); insert(root, 30);
insert(root, 20);
insert(root, 40);
insert(root, 70);
insert(root, 60);
insert(root, 80);
 
// Traverse and display the tree using in-order traversal printf("In-order traversal: ");
inOrder(root); printf("\n");

// Traverse and display the tree using pre-order traversal printf("Pre-order traversal: ");
preOrder(root); printf("\n");

// Traverse and display the tree using post-order traversal printf("Post-order traversal: ");
postOrder(root); printf("\n");

// Display the elements in the tree display(root);

return 0;
}

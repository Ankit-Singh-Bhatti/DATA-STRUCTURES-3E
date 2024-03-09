/**
*	Definition for a binary tree node.
*	struct TreeNode {
*	int val;
*	struct TreeNode *left;
*	struct TreeNode *right;
* };
*/
int countNodes(struct TreeNode* root) { if (!root)
return 0;


struct TreeNode* left = root->left; struct TreeNode* right = root->right; int leftHeight = 0, rightHeight = 0; while (left) {
leftHeight++; left = left->left;
}
while (right) { rightHeight++; right = right->left;
}


if (leftHeight == rightHeight) {
return (1 << leftHeight) + countNodes(root->right);
} else {
return countNodes(root->left) + (1 << rightHeight);
}
}

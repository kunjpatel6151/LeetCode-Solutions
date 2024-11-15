/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void inTraverse(struct TreeNode* root, int* inorder, int* index) {
    if (!root) return;
    inTraverse(root->left, inorder, index);
    inorder[(*index)++] = root->val;
    inTraverse(root->right, inorder, index);
}

struct TreeNode* constructBalancedBST(int* inorder, int low, int high) {
    if (low > high) return NULL;
    int mid = low + (high - low) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = inorder[mid];
    node->left = constructBalancedBST(inorder, low, mid - 1);
    node->right = constructBalancedBST(inorder, mid + 1, high);
    return node;
}

int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    if (!root) return NULL;
    int size = countNodes(root);
    int* inorder = (int*)malloc(size * sizeof(int));
    int index = 0;
    inTraverse(root, inorder, &index);
    struct TreeNode* balancedRoot = constructBalancedBST(inorder, 0, size - 1);
    free(inorder);
    return balancedRoot;
}







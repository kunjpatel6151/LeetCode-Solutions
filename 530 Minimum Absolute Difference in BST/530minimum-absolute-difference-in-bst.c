/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct Solution {
    struct TreeNode* prev;
    int minDiff;
};

void inOrderTraversal(struct TreeNode* node, struct Solution* solution) {
    if (node == NULL) {
        return;
    }

    inOrderTraversal(node->left, solution);

    if (solution->prev != NULL) {
        int diff = node->val - solution->prev->val;
        if (diff < solution->minDiff) {
            solution->minDiff = diff;
        }
    }

    solution->prev = node;

    inOrderTraversal(node->right, solution);
}

int getMinimumDifference(struct TreeNode* root) {
    struct Solution solution;
    solution.prev = NULL;
    solution.minDiff = INT_MAX;

    inOrderTraversal(root, &solution);

    return solution.minDiff;
}
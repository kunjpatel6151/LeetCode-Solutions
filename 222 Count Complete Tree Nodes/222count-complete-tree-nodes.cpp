#include <cmath> // For std::pow

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int leftDepth = getLeftDepth(root);
        int rightDepth = getRightDepth(root);

        if (leftDepth == rightDepth)
            return pow(2, leftDepth) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int getLeftDepth(TreeNode* root) {
        int depth = 0;
        while (root != nullptr) {
            root = root->left;
            depth++;
        }
        return depth;
    }

    int getRightDepth(TreeNode* root) {
        int depth = 0;
        while (root != nullptr) {
            root = root->right;
            depth++;
        }
        return depth;
    }
};

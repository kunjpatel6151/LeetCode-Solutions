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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avgList;
        if (root == nullptr) return avgList;

        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        levelQueue.push(nullptr); 
        while (levelQueue.front() != nullptr) {
            double sum = 0;
            int nodes = 0;

            while (levelQueue.front() != nullptr) {
                TreeNode* node = levelQueue.front();
                levelQueue.pop();
                sum += node->val;
                nodes++;

                if (node->left != nullptr) levelQueue.push(node->left);
                if (node->right != nullptr) levelQueue.push(node->right);
            }

            levelQueue.pop();
            levelQueue.push(nullptr);  
            avgList.push_back(sum / nodes); 
        }

        return avgList;
    }
};
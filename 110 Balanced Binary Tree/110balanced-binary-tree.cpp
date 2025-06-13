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
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftdepth=maxdepth(root->left);
        int rightdepth=maxdepth(root->right);

        if(abs(leftdepth-rightdepth)>1){
            return false;
        }
        bool left=isBalanced(root->left);
        if(!left){
            return false;
        }
        bool right=isBalanced(root->right);
        if(!right){
            return false;
        }
        return true;
        
    }

    int maxdepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=1+maxdepth(root->left);
        int right=1+maxdepth(root->right);
        return max(left,right);
    }
};
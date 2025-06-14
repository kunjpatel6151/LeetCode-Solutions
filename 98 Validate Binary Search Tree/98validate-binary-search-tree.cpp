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
    vector<long long> ans;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        bool flag=true;
        for(int i=1;i<ans.size();i++){
            if(ans[i]-ans[i-1]<=0){
                flag=false;
                break;
            }
        }
        return flag;
    }

    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }


};
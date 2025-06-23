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
    vector<int> ans;
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,0);
        bool flag=false;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==targetSum){
                flag=true;
                break;
            }
        }
        return flag;
    }

    void dfs(TreeNode* root,int sum){
        if(root!=NULL){
            sum+=root->val;
            if(root->left==NULL && root->right==NULL){
                ans.push_back(sum);
                sum-=root->val;
            }
            dfs(root->left,sum);
            dfs(root->right,sum);
        }
    }
};
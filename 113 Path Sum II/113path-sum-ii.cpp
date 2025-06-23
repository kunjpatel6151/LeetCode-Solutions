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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root,0,path,targetSum);
        return ans;
    }

    void dfs(TreeNode* root,int sum,vector<int>& path,int target){
        if(root!=NULL){
            sum+=root->val;
            path.push_back(root->val);
            if(root->left==NULL && root->right==NULL){
                if(sum==target){
                    ans.push_back(path);
                }
                sum-=root->val;
                path.pop_back();
            }
            else{
                dfs(root->left,sum,path,target);
                dfs(root->right,sum,path,target);
                sum-=root->val;
                path.pop_back();
            }
            
        }
    }
};
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        dfs(root,path,ans);
        return ans;
    }

    void dfs(TreeNode* root,vector<int>& path,vector<string>& ans){
        if(root!=NULL){
            path.push_back(root->val);
            if(root->left==NULL && root->right==NULL){
                string s="";
                for(int i=0;i<path.size()-1;i++){
                    s+=to_string(path[i])+"->";
                }
                s+=to_string(path[path.size()-1]);
                ans.push_back(s);
            }
            else{
                dfs(root->left,path,ans);
                dfs(root->right,path,ans);
            }
            path.pop_back();
        }
    }
};
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
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        map<int,int> mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]]++;
        }
        int m=0;
        for(pair<int,int> p:mp){
            m=max(m,p.second);
        }
        vector<int> ans;
        for(pair<int,int> p:mp){
            if(m==p.second){
                ans.push_back(p.first);
            }
        }
        return ans;

    }

    void inorder(TreeNode* root,vector<int>& v){
        if(root!=NULL){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
};
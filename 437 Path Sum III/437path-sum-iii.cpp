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
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        stack<int> st;
        dfs(root,targetSum,st,ans);
        return ans;
    }

    void dfs(TreeNode* root,int target,stack<int>& st,int& ans){
        if(root!=NULL){
            st.push(root->val);
            long long sum=0;
            vector<int> temp;
            stack<int> copy=st;
            while(!copy.empty()){
                temp.push_back(copy.top());
                sum+=copy.top();
                copy.pop();
                if(sum==target){
                    ans++;
                }
            }
            dfs(root->left,target,st,ans);
            dfs(root->right,target,st,ans);
            st.pop();
        }
    }
};
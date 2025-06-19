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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool flag=true;
        if(root==NULL){
            return ans; 
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> res(n);
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                int index=(flag)?i:(n-i-1);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                res[index]=temp->val;
            }
            ans.push_back(res);
            flag=!flag;
        }
        return ans;
    }
};
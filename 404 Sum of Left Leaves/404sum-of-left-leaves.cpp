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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum=0;
        queue<pair<TreeNode*,bool>> q;
        q.push({root,false});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front().first;
                bool flag=q.front().second;
                q.pop();
                if(f->left==NULL && f->right==NULL && flag){
                    sum+=f->val;
                }
                if(f->left!=NULL){
                    q.push({f->left,true});
                }
                if(f->right!=NULL){
                    q.push({f->right,false});
                }
            }
        }
        return sum;
    }
};
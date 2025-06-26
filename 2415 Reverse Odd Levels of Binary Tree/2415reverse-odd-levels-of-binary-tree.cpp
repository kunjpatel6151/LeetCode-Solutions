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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> v(n);
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                v[i]=f;
                q.pop();
                if(f->left!=NULL){
                    q.push(f->left);
                }
                if(f->right!=NULL){
                    q.push(f->right);
                }
            }
            if(flag){
                int l=0;
                int r=n-1;
                while(l<r){
                    swap(v[l]->val,v[r]->val);
                    l++;
                    r--;
                }
            }
            flag=!flag;
        }
        return root;
    }
};
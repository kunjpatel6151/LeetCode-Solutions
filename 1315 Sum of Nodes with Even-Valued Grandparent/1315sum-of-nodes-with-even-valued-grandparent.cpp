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
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f->val%2==0){
                if(f->left!=NULL){
                    if(f->left->left!=NULL){
                        ans+=f->left->left->val;
                    }
                    if(f->left->right!=NULL){
                        ans+=f->left->right->val;
                    }
                }
                if(f->right!=NULL){
                    if(f->right->left!=NULL){
                        ans+=f->right->left->val;
                    }
                    if(f->right->right!=NULL){
                        ans+=f->right->right->val;
                    }
                }
            }
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
        }
        return ans;
    }
};
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
    int diameterOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                int leftdepth=maxdepth(f->left);
                int rightdepth=maxdepth(f->right);
                if(f->left!=NULL){
                    q.push(f->left);
                }
                if(f->right!=NULL){
                    q.push(f->right);
                }
                ans=max(ans,leftdepth+rightdepth);
            }
        }
        return ans;
    }

    int maxdepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftdepth=1+maxdepth(root->left);
        int rightdepth=1+maxdepth(root->right);
        return max(leftdepth,rightdepth);
    }
};
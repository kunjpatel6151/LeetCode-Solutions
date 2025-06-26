/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL || cloned==NULL){
            return cloned;
        }
        queue<TreeNode*> q;
        q.push(cloned);
        TreeNode* ans=NULL;
        while(!q.empty() && ans==NULL){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                if(f->val==target->val){
                    ans=f;
                    break;
                }
                if(f->left!=NULL){
                    q.push(f->left);
                }
                if(f->right!=NULL){
                    q.push(f->right);
                }
            }
        }
        return ans;
    }
};
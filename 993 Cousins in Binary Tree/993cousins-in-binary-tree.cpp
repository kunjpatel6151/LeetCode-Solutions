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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        while(!q.empty()){
            int n=q.size();
            TreeNode* xp=NULL;
            TreeNode* yp=NULL;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front().first;
                TreeNode* p=q.front().second;
                q.pop();
                if(f->val==x){
                    xp=p;
                }
                if(f->val==y){
                    yp=p;
                }
                if(f->left!=NULL){
                    q.push({f->left,f});
                }
                if(f->right!=NULL){
                    q.push({f->right,f});
                }
            }
            if(xp!=NULL && yp!=NULL){
                if(xp==yp){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
};
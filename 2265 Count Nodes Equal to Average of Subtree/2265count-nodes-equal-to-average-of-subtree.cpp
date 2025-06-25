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
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        vector<TreeNode*> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f=q.front();
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
            v.push_back(f);
            q.pop();
        }
        for(int i=0;i<v.size();i++){
            if(check(v[i])){
                ans++;
            }
        }
        return ans;
    }

    bool check(TreeNode* root){
        int sum=0;
        int count=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            count++;
            sum+=f->val;
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
        }
        int avg=sum/count;
        return avg==root->val;
    }

    
};
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
    int maxLevelSum(TreeNode* root) {
        int ans=1;
        int max_sum=root->val;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                sum+=f->val;
                if(f->left!=NULL){
                    q.push(f->left);
                }
                if(f->right!=NULL){
                    q.push(f->right);
                }
            }
            if(max_sum<sum){
                max_sum=sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        long long m=0;
        while(!q.empty()){
            long long n=q.size();
            long long index=q.front().second;
            long long l,r;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front().first;
                long long curr=q.front().second;
                q.pop();
                if(i==0){
                    l=curr;
                }
                if(i==n-1){
                    r=curr;
                }
                if(f->left!=NULL){
                    q.push({f->left,2*curr+1});
                }
                if(f->right!=NULL){
                    q.push({f->right,2*curr+2});
                }
            }
            m=max(m,r-l+1);
        }
        return m;
    }
};
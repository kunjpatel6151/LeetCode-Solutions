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
    unordered_map<TreeNode*,int> mp;
    int maxdepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = 1 + maxdepth(root->left);
        int right = 1 + maxdepth(root->right);
        mp[root]=max(left,right);
        return mp[root];
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxdepth(root);
        int level=0;
        TreeNode* ans=root;
        int depth = mp[root];
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            TreeNode* Possible = NULL;
            int count=0;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                if(mp[f]+level==depth){
                    Possible = f;
                    count++;
                }
                if(f->left!=NULL){
                    q.push(f->left);
                }
                if(f->right!=NULL){
                    q.push(f->right);
                }
            }
            if(count==1){
                ans=Possible;
            }
            level++;
        }
        return ans;
    }
};
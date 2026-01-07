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
    int MOD=1000000007;
    unordered_map<TreeNode*,pair<int,int>> mp;
    pair<int,int> dfs(TreeNode* root){
        if(mp.find(root)==mp.end()){
            int left_sum=0,right_sum=0;
            if(root->left==NULL && root->right==NULL){
                return mp[root] = {0,0};
            }
            if(root->left!=NULL && root->right!=NULL){
                if(mp.find(root->left)==mp.end()){
                    dfs(root->left);
                }
                if(mp.find(root->right)==mp.end()){
                    dfs(root->right);
                }
                left_sum = ((root->left->val + mp[root->left].first)%MOD + mp[root->left].second)%MOD;
                right_sum = ((root->right->val + mp[root->right].first)%MOD + mp[root->right].second)%MOD;
                return mp[root] = {left_sum,right_sum};
            }
            if(root->left!=NULL){
                if(mp.find(root->left)==mp.end()){
                    dfs(root->left);
                }
                left_sum = ((root->left->val + mp[root->left].first)%MOD + mp[root->left].second)%MOD;
                right_sum = 0;
                return mp[root] = {left_sum,right_sum};
            }
            if(root->right!=NULL){
                if(mp.find(root->right)==mp.end()){
                    dfs(root->right);
                }
                right_sum = ((root->right->val + mp[root->right].first)%MOD + mp[root->right].second)%MOD;
                left_sum = 0;
                return mp[root] = {left_sum,right_sum};
            }
        }
        return mp[root];
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        int total = ((root->val + mp[root].first)%MOD + mp[root].second)%MOD;
        long long ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            long long product=0;
            long long sum1 = mp[f].first;
            long long sum2 = total - mp[f].first;
            product = sum1 * sum2;
            ans=max(ans,product);
            sum1= mp[f].second;
            sum2= total - mp[f].second;
            product = sum1 * sum2;
            ans=max(ans,product);
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
        }
        ans%=MOD;
        return (int)ans;
    }
};
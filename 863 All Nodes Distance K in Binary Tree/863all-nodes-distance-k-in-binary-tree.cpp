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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,vector<TreeNode*>> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f->left!=NULL){
                mp[f].push_back(f->left);
                mp[f->left].push_back(f);
                q.push(f->left);
            }
            if(f->right!=NULL){
                mp[f].push_back(f->right);
                mp[f->right].push_back(f);
                q.push(f->right);
            }
        }
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        int dist=0;
        visited[target]=true;
        vector<int> ans;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                if(dist==k){
                    ans.push_back(f->val);
                    continue;
                }
                for(TreeNode* neigh:mp[f]){
                    if(!visited[neigh]){
                        visited[neigh]=true;
                        q.push(neigh);
                    }
                }
            }
            if(dist==k) break;
            dist++;
        }
        return ans;
    }
};
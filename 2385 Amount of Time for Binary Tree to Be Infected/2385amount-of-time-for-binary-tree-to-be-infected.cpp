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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,vector<TreeNode*>> mp;
        queue<TreeNode*> q;
        q.push(root);
        int N=0;
        TreeNode* node=NULL;
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f->val==start){
                node=f;
            }
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
            N++;
        }
        unordered_map<TreeNode*,bool> visited;
        int count=1;
        int time=0;
        visited[node]=true;
        q.push(node);
        while(count<N){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                for(TreeNode* neigh:mp[f]){
                    if(!visited[neigh]){
                        count++;
                        visited[neigh]=true;
                        q.push(neigh);
                    }
                }
            }
            
            time++;
        }
        return time;
    }
};
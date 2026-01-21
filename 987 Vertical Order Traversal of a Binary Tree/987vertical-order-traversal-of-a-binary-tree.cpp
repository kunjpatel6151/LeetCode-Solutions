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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        map<int,vector<int>> mp;
        q.push({root,0});
        int row=0;
        while(!q.empty()){
            vector<pair<int,int>> v;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front().first;
                int col=q.front().second;
                q.pop();
                v.push_back({f->val,col});
                if(f->left!=NULL){
                    q.push({f->left,col-1});
                }
                if(f->right!=NULL){
                    q.push({f->right,col+1});
                }
            }
            row++;
            sort(v.begin(),v.end());
            for(pair<int,int> p:v){
                mp[p.second].push_back(p.first);
            }
        }
        vector<vector<int>> ans;
        for(auto &p:mp){
            ans.push_back(p.second);
        }
        return ans;
                
    }
};
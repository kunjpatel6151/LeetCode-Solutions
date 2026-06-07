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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root=NULL;
        unordered_map<int,TreeNode*> mp;
        for(int i=0;i<descriptions.size();i++){
            TreeNode* parent=NULL;
            TreeNode* child=NULL;
            if(mp.find(descriptions[i][0])!=mp.end()){
                parent=mp[descriptions[i][0]];
            }
            else{
                parent= new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]]=parent;
            }
            if(mp.find(descriptions[i][1])!=mp.end()){
                child=mp[descriptions[i][1]];
            }
            else{
                child= new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]]=child;
            }
            if(descriptions[i][2]==0){
                parent->right=child;
            }
            else{
                parent->left=child;
            }
        }
        unordered_set<TreeNode*> children;
        for(pair<int,TreeNode*> p:mp){
            if(p.second->left!=NULL){
                children.insert(p.second->left);
            }
            if(p.second->right!=NULL){
                children.insert(p.second->right);
            }
        }
        for(pair<int,TreeNode*> p:mp){
            if(!children.count(p.second)){
                root=p.second;
                break;
            }
        }
        return root;
    }
};
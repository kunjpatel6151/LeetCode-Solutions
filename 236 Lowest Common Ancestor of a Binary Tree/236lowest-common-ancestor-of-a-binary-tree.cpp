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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root || q==root) return root;
        queue<TreeNode*> Q;
        Q.push(root);
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root]=NULL;
        while(!Q.empty()){
            TreeNode* f=Q.front();
            Q.pop();
            if(f->left!=NULL){
                Q.push(f->left);
                parent[f->left]=f;
            }
            if(f->right!=NULL){
                Q.push(f->right);
                parent[f->right]=f;
            }
        }
        unordered_map<TreeNode*,bool> visited1, visited2;
        TreeNode* temp1=p;
        TreeNode* temp2=q;
        while(temp1!=NULL && temp2!=NULL){
            visited1[temp1]=true;
            visited2[temp2]=true;
            if(visited2[temp1]) return temp1;
            if(visited1[temp2]) return temp2;
            temp1=parent[temp1];
            temp2=parent[temp2];
        }
        while(temp1!=NULL){
            visited1[temp1]=true;
            if(visited2[temp1]) return temp1;
            temp1=parent[temp1];
        }
        while(temp2!=NULL){
            visited2[temp2]=true;
            if(visited1[temp2]) return temp2;
            temp2=parent[temp2];
        }
        return root;
    }
};
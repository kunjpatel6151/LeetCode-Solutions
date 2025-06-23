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
    vector<TreeNode*> v;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int l=-1,r=-1;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]->val>v[i+1]->val){
                l=i;
                break;
            }
        }
        for(int i=v.size()-1;i>0;i--){
            if(v[i]->val<v[i-1]->val){
                r=i;
                break;
            }
        }
        int temp=v[l]->val;
        v[l]->val=v[r]->val;
        v[r]->val=temp;
    }

    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            v.push_back(root);
            inorder(root->right);
        }
    }

};
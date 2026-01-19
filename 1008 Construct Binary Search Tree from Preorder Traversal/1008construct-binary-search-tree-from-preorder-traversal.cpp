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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root= new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            int k=preorder[i];
            TreeNode* temp=root;
            construct(root,k);
        }
        return root;
    }

    void construct(TreeNode* root,int k){
        if(root->val<k){
            if(root->right==NULL){
                TreeNode* newnode= new TreeNode(k);
                root->right=newnode;
            }
            else{
                construct(root->right,k);
            }
        }
        else{
            if(root->left==NULL){
                TreeNode* newnode = new TreeNode(k);
                root->left=newnode;
            }
            else{
                construct(root->left,k);
            }
        }
    }
};
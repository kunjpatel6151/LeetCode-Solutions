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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        bool flag=false;
        int n=v.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sum=v[i]+v[j];
                if(sum==k){
                    flag=true;
                    break;
                }
                if(sum>k){
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        return flag;
    }

    void inorder(TreeNode* root, vector<int>& v){
        if(root!=NULL){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
};
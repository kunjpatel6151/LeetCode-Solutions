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
    vector<int> arr;
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode *head;
        TreeNode *tail;
        for(int i=0;i<arr.size();i++){
            TreeNode* NewNode = new TreeNode(arr[i]);
            if(i==0){
                head=NewNode;
                head->left=NULL;
                head->right=NULL;
                tail=head;
            }
            else{
                tail->right=NewNode;
                tail=NewNode;
                tail->left=NULL;
                tail->right=NULL;
            }
        }
        return head;

    }

    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            arr.push_back(root->val);
            inorder(root->right);
        }
    }
};
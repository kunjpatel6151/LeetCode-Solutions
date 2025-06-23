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
    bool evaluateTree(TreeNode* root) {
        stack<int> st;
        postorder(root,st);
        return st.top();
    }

    void postorder(TreeNode* root,stack<int>& st){
        if(root!=NULL){
            postorder(root->left,st);
            postorder(root->right,st);
            if(root->val==0 || root->val==1){
                st.push(root->val);
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(root->val==2){
                    st.push(a || b);
                }
                else{
                    st.push(a && b);
                }
            }
        }
    }
};
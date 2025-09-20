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
    bool isSymmetric(TreeNode* root) {
        queue<pair<pair<TreeNode*,int>,TreeNode*>> q;
        if(root->left==NULL && root->right==NULL) return true;
        if(root->left!=NULL){
            q.push({{root->left,-1},root});
        }
        if(root->right!=NULL){
            q.push({{root->right,1},root});
        }
        while(!q.empty()){
            int n=q.size();
            if(n%2!=0) return false;
            stack<pair<pair<TreeNode*,int>,TreeNode*>> st;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front().first.first;
                int d1=q.front().first.second;
                TreeNode* p1=q.front().second;
                q.pop();
                if(i<n/2){
                    st.push({{f,d1},p1});
                }
                else{
                    if(st.empty()) return false;
                    TreeNode* t=st.top().first.first;
                    int d2=st.top().first.second;
                    TreeNode* p2=st.top().second;
                    st.pop();
                    if(f->val!=t->val || d1==d2 || p1->val!=p2->val) return false;
                    if((f->left==NULL && t->right!=NULL) || (f->left!=NULL && t->right==NULL) || (f->left!=NULL && t->right!=NULL && f->left->val!=t->right->val)) return false;
                    if((t->left==NULL && f->right!=NULL) || (t->left!=NULL && f->right==NULL) || (t->left!=NULL && f->right!=NULL && t->left->val!=f->right->val)) return false;
                }
                if(f->left!=NULL){
                    q.push({{f->left,-1},f});
                }
                if(f->right!=NULL){
                    q.push({{f->right,1},f});
                }
            }

        }
        return true;
    }
};
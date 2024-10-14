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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string p1,p2,p3,q1,q2,q3;
        f1(p,p1);
        f2(p,p2);
        f3(p,p3);
        f1(q,q1);
        f2(q,q2);
        f3(q,q3);
        bool b=(p1==q1) && (p2==q2) && (p3==q3);
        return b;
    }
    void f1(TreeNode* root,string &s){
        if(root==NULL){
            s.append("n");
            return;
        }
        s.append(to_string(root->val));
        f1(root->left,s);
        f1(root->right,s);
    }
    void f2(TreeNode* root,string &s){
        if(root==NULL){
            s.append("n");
            return;
        }
        f2(root->left,s);
        s.append(to_string(root->val));
        f2(root->right,s);
    }
    void f3(TreeNode* root,string &s){
        if(root==NULL){
            s.append("n");
            return;
        }
        f3(root->left,s);
        f3(root->right,s);
        s.append(to_string(root->val));
    }
};
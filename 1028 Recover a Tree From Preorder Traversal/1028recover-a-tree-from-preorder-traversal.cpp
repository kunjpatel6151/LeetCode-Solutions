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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int,int>> v;
        int i=0;
        while(i<traversal.size()){
            int depth=0;
            while(i<traversal.size() && traversal[i]=='-'){
                depth++;
                i++;
            }
            int num=0;
            while(i<traversal.size() && traversal[i]!='-'){
                num=10*num + (traversal[i]-'0');
                i++;
            }
            v.push_back({num,depth});
        }

        stack<pair<TreeNode*,int>> st;
        TreeNode* root=NULL;
        for(int i=0;i<v.size();i++){
            int val=v[i].first;
            int depth=v[i].second;
            TreeNode* node= new TreeNode(val);
            while(!st.empty() && st.top().second>=depth){
                st.pop();
            }
            if(!st.empty()){
                TreeNode* par=st.top().first;
                if(par->left==NULL){
                    par->left=node;
                }
                else{
                    par->right=node;
                }
            }
            else{
                root=node;
            }
            st.push({node,depth});
        }
        return root;
    }
};
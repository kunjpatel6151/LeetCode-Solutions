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
    vector<string> v;
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        dfs(root,"");
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=btoi(v[i]);
        }
        return sum;
    }

    void dfs(TreeNode* root,string str){
        if(root!=NULL){
            str+=to_string(root->val);
            if(root->left==NULL && root->right==NULL){
                v.push_back(str);
                str.pop_back();
            }
            dfs(root->left,str);
            dfs(root->right,str);
        }
    }

    int btoi(string s){
        int n=s.size();
        long long val=0;
        long long i=0;
        while(n--){
            if(s[n]=='1'){
                val+=pow(2,i);
            }
            i++;
        }
        return (int)val;
    }
};
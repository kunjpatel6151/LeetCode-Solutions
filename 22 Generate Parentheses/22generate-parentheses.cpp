class Solution {
public:
    void solve(vector<string>& ans,string s, int open,int close,int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s+="(";
            solve(ans,s,open+1,close,n);
            s=s.substr(0,s.size()-1);
        }
        if(close<open){
            s+=")";
            solve(ans,s,open,close+1,n);
            s=s.substr(0,s.size()-1);
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(ans,s,0,0,n);
        return ans;
    }
};
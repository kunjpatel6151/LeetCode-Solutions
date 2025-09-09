class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(ans,v,0,s);
        return ans;
    }

    void solve(vector<vector<string>>& ans,vector<string>& v,int index,string s){
        if(index==s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=index;i<s.size();i++){
            string str=s.substr(index,i-index+1);
            if(isPalidrome(str)){
                v.push_back(str);
                solve(ans,v,i+1,s);
                v.pop_back();
            }
        }
    }

    bool isPalidrome(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

};
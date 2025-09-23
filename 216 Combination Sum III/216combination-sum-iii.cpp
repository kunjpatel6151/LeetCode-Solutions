class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> seq;
        solve(ans,seq,0,1,k,n);
        return ans;
    }

    void solve(vector<vector<int>>& ans, vector<int>& seq,int sum,int digit,int k,int n){
        if(seq.size()==k && sum==n){
            ans.push_back(seq);
            return;
        }
        if(digit>9) return;
        seq.push_back(digit);
        solve(ans,seq,sum+digit,digit+1,k,n);
        seq.pop_back();
        solve(ans,seq,sum,digit+1,k,n);
        
    }

};
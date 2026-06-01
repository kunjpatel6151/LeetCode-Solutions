class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return solve(0,1,dp,prices);
    }

    int solve(int i, int flag, vector<vector<int>>& dp, vector<int>& p){
        if(i>=p.size()){
            return 0;
        }
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        if(flag){
            dp[i][flag]=max(-p[i] + solve(i+1,0,dp,p), solve(i+1,1,dp,p));
        }
        else{
            dp[i][flag]=max(p[i] + solve(i+2,1,dp,p), solve(i+1,0,dp,p));
        }
        return dp[i][flag];
    }
};
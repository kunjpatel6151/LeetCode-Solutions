class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (k+1, vector<int> (2,-1)));
        return solve(0,k,1,dp,prices);
    }

    int solve(int i, int k, int flag, vector<vector<vector<int>>>& dp, vector<int>& p){
        if(i>=p.size() || k==0){
            return 0;
        }
        if(dp[i][k][flag]!=-1){
            return dp[i][k][flag];
        }
        if(flag){
            dp[i][k][flag]=max(-p[i] + solve(i+1,k,0,dp,p), solve(i+1,k,1,dp,p));
        }
        else{
            dp[i][k][flag]=max(p[i] + solve(i+1,k-1,1,dp,p), solve(i+1,k,0,dp,p));
        }
        return dp[i][k][flag];
    }
};
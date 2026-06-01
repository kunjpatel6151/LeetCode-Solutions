class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (3, vector<int> (2,-1)));
        return solve(0,2,1,dp,prices);
    }

    int solve(int i, int r, int flag, vector<vector<vector<int>>>& dp, vector<int>& p){
        if(i>=p.size() || r==0){
            return 0;
        }
        if(dp[i][r][flag]!=-1){
            return dp[i][r][flag];
        }
        if(flag){
            dp[i][r][flag]=max(-p[i] + solve(i+1,r,0,dp,p), solve(i+1,r,1,dp,p));
        }
        else{
            dp[i][r][flag]=max(p[i] + solve(i+1,r-1,1,dp,p), solve(i+1,r,0,dp,p));
        }
        return dp[i][r][flag];
    }
};
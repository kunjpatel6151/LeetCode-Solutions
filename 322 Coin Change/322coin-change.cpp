class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int INF = 1e9;
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,INF));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<=amount;j++){
            if(j%coins[0]==0){
                dp[0][j]=1+dp[0][j-coins[0]];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                dp[i][j]=dp[i-1][j];
                if(coins[i]<=j){
                    dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
                }
            }
        }
        return dp[n-1][amount] >= INF ? -1 : dp[n-1][amount];
    }
};
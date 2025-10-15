class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n);
        dp[0]=0;
        int minprice=prices[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],prices[i]-minprice);
            minprice=min(minprice,prices[i]);
        }
        return dp[n-1];
    }
};
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long M=1000000007;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n));
        dp[0][0]={grid[0][0],grid[0][0]};
        for(int i=1;i<m;i++){
            long long x=dp[i-1][0].first * grid[i][0];
            long long y=dp[i-1][0].second * grid[i][0];
            dp[i][0]={max(x,y),min(x,y)};
        }
        for(int j=1;j<n;j++){
            long long x=dp[0][j-1].first * grid[0][j];
            long long y=dp[0][j-1].second * grid[0][j];
            dp[0][j]={max(x,y),min(x,y)};
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                long long w=dp[i-1][j].first * grid[i][j];
                long long x=dp[i-1][j].second * grid[i][j];
                long long y=dp[i][j-1].first * grid[i][j];
                long long z=dp[i][j-1].second * grid[i][j];
                dp[i][j]={max({w,x,y,z}),min({w,x,y,z})};
            }
        }
        if(max(dp[m-1][n-1].first,dp[m-1][n-1].second)<0){
            return -1;
        }
        return max(dp[m-1][n-1].first,dp[m-1][n-1].second)%M;
    }
};
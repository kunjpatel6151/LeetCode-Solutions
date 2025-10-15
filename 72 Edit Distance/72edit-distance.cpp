class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));

        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int delete_cost=dp[i-1][j]+1;
                    int insert_cost=dp[i][j-1]+1;
                    int replace_cost=dp[i-1][j-1]+1;
                    dp[i][j]=min({delete_cost,insert_cost,replace_cost});
                }
            }
        }
        return dp[m][n];
    }
};
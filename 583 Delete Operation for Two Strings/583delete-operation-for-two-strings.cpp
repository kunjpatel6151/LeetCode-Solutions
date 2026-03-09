class Solution {
public:
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2*lcs(word1,word2);
    }

    int lcs(string &s1, string &s2) {
        // code here
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        if(s1[0]==s2[0]){
            dp[0][0]=1;
        }
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0];
            if(s1[i]==s2[0]){
                dp[i][0]=1;
            }
        }
        for(int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1];
            if(s1[0]==s2[j]){
                dp[0][j]=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
            }
        }
        return dp[m-1][n-1];
    }
};
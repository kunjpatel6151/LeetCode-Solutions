class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int total=0;
        int n=s1.size();
        int m=s2.size();
        for(char c:s1){
            total+=c;
        }
        for(char c:s2){
            total+=c;
        }
        vector<vector<int>> dp(n, vector<int> (m,0));
        if(s1[0]==s2[0]) dp[0][0]=s1[0];
        for(int i=1;i<n;i++){
            if(s1[i]==s2[0]) dp[i][0]=s1[i];
            dp[i][0]=max(dp[i][0],dp[i-1][0]);
        }
        for(int j=1;j<m;j++){
            if(s1[0]==s2[j]) dp[0][j]=s2[j];
            dp[0][j]=max(dp[0][j],dp[0][j-1]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(s1[i]==s2[j]){
                    dp[i][j]=s1[i]+dp[i-1][j-1];
                }
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
            }
        }
        return total - 2*dp[n-1][m-1];        
    }
};
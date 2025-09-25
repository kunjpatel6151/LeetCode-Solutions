class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m=rides.size();
        sort(rides.begin(),rides.end());
        vector<int> start(m);
        for(int i=0;i<m;i++){
            start[i]=rides[i][0];
        }
        vector<long long> dp(m,-1);
        return solve(0,m,start,rides,dp);
    }

    long long solve(int index, int m, vector<int>& start,vector<vector<int>>& rides, vector<long long>& dp){
        if(index>=m){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        int next_ride= lower_bound(start.begin(),start.end(),rides[index][1]) - start.begin();
        long long take=rides[index][1]-rides[index][0]+rides[index][2] + solve(next_ride,m,start,rides,dp);
        long long not_take=solve(index+1,m,start,rides,dp);
        dp[index]=max(take,not_take);
        return dp[index];
    }

};
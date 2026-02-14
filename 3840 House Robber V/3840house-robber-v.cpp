class Solution {
public:
    long long solve(int i,int taken, vector<vector<long long>>& dp, vector<int>& nums, vector<int>& colors){
        if(i>=nums.size()) return 0;
        if(dp[i][taken]!=-1) return dp[i][taken];
        long long not_take=solve(i+1,0,dp,nums,colors);
        long long take=0;
        if(i==0 || colors[i]!=colors[i-1] || taken==0){
            take=nums[i]+solve(i+1,1,dp,nums,colors);
        }
        dp[i][taken]=max(take,not_take);
        return dp[i][taken];
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<vector<long long>> dp(n, vector<long long> (2, -1)); // not take 0 take 1
        return solve(0, 0,dp,nums,colors);
    }
};
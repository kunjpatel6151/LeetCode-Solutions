class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int x:nums){
            total+=x;
        }
        if(total%2!=0) return false;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (total/2 + 1,-1));
        return solve(0,total/2,nums,dp);
    }

    bool solve(int i,int target,vector<int>& arr, vector<vector<int>>& dp){
        if(target==0) return true;
        if(i>=arr.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        if(target==arr[i]) return dp[i][target] = 1;
        bool take=false;
        if(target>arr[i]){
            take=solve(i+1,target-arr[i],arr,dp);
        }
        bool not_take=solve(i+1,target,arr,dp);
        return dp[i][target] = (take || not_take);
    }
};
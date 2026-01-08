class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        solve(0,0,target,ans,nums);
        return ans;
    }

    void solve(int i, int val, int target, int& ans, vector<int>& nums){
        if(i>=nums.size()){
            if(val==target){
                ans++;
            }
            return;
        }
        solve(i+1,val+nums[i],target,ans,nums);
        solve(i+1,val-nums[i],target,ans,nums);
    }
};
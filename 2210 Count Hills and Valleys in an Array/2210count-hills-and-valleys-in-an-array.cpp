class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int valley=0,hill=0;
        int curr=1;
        while(curr<n-1){
            int l=curr-1;
            int r=curr+1;
            while(l>=0 && nums[l]==nums[curr]){
                l--;
            }
            if(l<0){
                curr++;
                continue;
            }
            while(r<n && nums[r]==nums[curr]){
                r++;
            }
            if(r>=n){
                break;
            }
            if(nums[curr]>nums[l] && nums[curr]>nums[r]){
                hill++;
            }
            if(nums[curr]<nums[l] && nums[curr]<nums[r]){
                valley++;
            }
            curr=r;
        }
        return valley+hill;
    }
};
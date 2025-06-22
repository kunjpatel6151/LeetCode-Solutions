class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int l=0,r=1;
        while(l<n){
            while(r<n && nums[r]>nums[r-1]){
                r++;
            }
            ans=max(ans,r-l);
            l=r;
            r++;
        }
        return ans;
    }
};
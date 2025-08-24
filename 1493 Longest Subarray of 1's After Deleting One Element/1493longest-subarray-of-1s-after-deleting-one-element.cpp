class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int ans=0,ones=0,zeros=0;
        while(r<n){
            if(nums[r]==1) ones++;
            else zeros++;
            while(zeros>1){
                if(nums[l]==1) ones--;
                else zeros--;
                l++;
            }
            if(zeros==0){
                ans=max(ones-1,ans);
            }
            else{
                ans=max(ones,ans);
            }
            r++;
        }
        return ans;
    }
};
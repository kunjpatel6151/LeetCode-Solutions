class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }

    int f(vector<int>& nums, int k){
        int n=nums.size();
        int count=0,ans=0;
        int l=0,r=0;
        while(r<n){
            if(nums[r] & 1){
                count++;
            }
            while(count>k){
                if(nums[l] & 1){
                    count--;
                }
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};
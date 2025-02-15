class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i-k>=0 && i+k<n){
                if(nums[i-k]<nums[i] && nums[i+k]<nums[i]){
                    ans+=nums[i];
                }
            }
            else if(i-k>=0){
                if(nums[i-k]<nums[i]){
                    ans+=nums[i];
                }
            }
            else if(i+k<n){
                if(nums[i+k]<nums[i]){
                    ans+=nums[i];
                }
            }
            else{
                ans+nums[i];
            }
        }
        return ans;
    }
};
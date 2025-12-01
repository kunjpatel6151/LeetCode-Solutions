class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans= *max_element(nums.begin(),nums.end());
        int currMax=nums[0], currMin=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp1=currMax*nums[i];
            int temp2=currMin*nums[i];
            currMax=max({nums[i],temp1,temp2});
            currMin=min({nums[i],temp1,temp2});
            ans=max(currMax,ans);
        }
        return ans;
    }
};
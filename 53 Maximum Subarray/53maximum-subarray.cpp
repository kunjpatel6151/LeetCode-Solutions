class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int current_max=nums[0];
      int final_max=nums[0];
      for(int i=1;i<nums.size();i++){
        current_max=max(nums[i],nums[i]+current_max);
        final_max=max(current_max,final_max);
      }
      return final_max;
    }
};
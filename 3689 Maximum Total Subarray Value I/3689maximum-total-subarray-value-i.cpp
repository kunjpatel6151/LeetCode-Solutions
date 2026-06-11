class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long min_val=nums[0];
        long long max_val=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min_val){
                min_val=nums[i];
            }
            if(nums[i]>max_val){
                max_val=nums[i];
            }
        }
        return k*(max_val-min_val);
    }
};
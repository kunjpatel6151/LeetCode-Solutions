class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int low=INT_MAX;
        int high=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<low){
                low=nums[i];
            }
            high=max(high,nums[i]-low);
        }
        if(high){
            return high;
        }
        else{
            return -1;
        }
    }
};
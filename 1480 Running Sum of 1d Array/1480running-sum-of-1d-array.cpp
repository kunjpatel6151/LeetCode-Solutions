class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::vector<int> num(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            num[i]=sum+nums[i];
            sum=sum+nums[i];
        }
        return num;
    }
};
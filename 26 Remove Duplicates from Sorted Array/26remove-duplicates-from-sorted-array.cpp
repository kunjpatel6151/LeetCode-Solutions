class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        for(int r=0;r<nums.size();r++){
            if(nums[l]!=nums[r]){
                swap(nums[l+1],nums[r]);
                l++;
            }
        }
        return l+1;
    }
};
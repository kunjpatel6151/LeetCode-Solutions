class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1,maxlength=1;
        if(nums.size()==0){
            return 0;
        }
        else if(nums.size()==1){
            return 1;
        }
        else{
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]==nums[i+1]-1){
                    count++;
                    maxlength=max(maxlength,count);
                }
                else if(nums[i]==nums[i+1]){
                    continue;
                }
                else{
                    count=1;
                }
            }
        }
        return maxlength;
    }
};
class Solution {
public:
    bool isSorted(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(!isSorted(nums)){
            int minsum=INT_MAX;
            int index=-1;
            for(int i=1;i<nums.size();i++){
                int sum=nums[i-1]+nums[i];
                if(sum<minsum){
                    minsum=sum;
                    index=i-1;
                }
            }
            if(index==-1){
                break;
            }
            nums[index]=minsum;
            nums.erase(nums.begin()+index+1);
            count++;

        }
        return count;
    }
};
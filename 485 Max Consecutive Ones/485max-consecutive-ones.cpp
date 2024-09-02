class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int m=0,count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
                m=max(m,count);
            }
            else{
                count=0;
            }
           
        }
        return m;
    }
};
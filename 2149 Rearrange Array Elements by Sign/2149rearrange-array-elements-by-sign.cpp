class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int l=0,r=1;
        for(int num:nums){
            if(num>=0){
                ans[l]=num;
                l+=2;
            }
            else{
                ans[r]=num;
                r+=2;
            }
        }
        return ans;
    }
};
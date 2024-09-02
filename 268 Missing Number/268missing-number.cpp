class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),sum,ans=0;
        sum=(n*(n+1))/2;
        for(int i=0;i<n;i++){
            ans+=nums[i];
        }
        return sum-ans;
    }
};
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int m=abs(nums[0]-nums[n-1]);
        for(int i=1;i<n;i++){
            m=max(abs(nums[i-1]-nums[i]),m);
        }
        return m;
    }
};
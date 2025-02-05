class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        while(i<n){
            int j=i+1;
            int size=1;
            while(j<n && nums[j-1]<nums[j]){
                size++;
                j++;
            }
            ans=max(size,ans);
            i++;
        }
        i=0;
        while(i<n){
            int j=i+1;
            int size=1;
            while(j<n && nums[j-1]>nums[j]){
                size++;
                j++;
            }
            ans=max(size,ans);
            i++;
        }
        return ans;
    }
};
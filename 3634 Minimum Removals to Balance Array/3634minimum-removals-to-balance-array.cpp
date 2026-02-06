class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        int l=0,r=0;
        while(r<n){
            while(nums[r]>(long long)k*nums[l]){
                l++;
            }
            ans=max(r-l+1,ans);
            r++;
        }
        return n-ans;
    }
};
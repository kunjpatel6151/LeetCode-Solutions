class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k==1) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=k-1;
        int ans=nums[r]-nums[l];
        while(r<n){
            ans=min(ans,nums[r]-nums[l]);
            r++;
            l++;
        }
        return ans;
    }
};
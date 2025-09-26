class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=n-1;i>=2;i--){
            int l=0,r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    ans+=r-l;
                    r--;
                }
                else{
                    l++;
                }
            }

        }
        return ans;
    }
};
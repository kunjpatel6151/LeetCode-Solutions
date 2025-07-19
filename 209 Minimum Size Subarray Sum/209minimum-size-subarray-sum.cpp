class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        int ans=n+1,l=0,r=0;
        bool flag=false;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                flag=true;
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(flag){
            return ans;
        }
        else{
            return 0;
        }
    }
};
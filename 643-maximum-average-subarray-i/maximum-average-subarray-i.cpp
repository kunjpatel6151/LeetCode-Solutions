class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0, r=0;
        double sum=0;
        while(r<k){
            sum+=nums[r];
            r++;
        }
        double ans=sum;
        while(r<n){
            sum+=nums[r];
            sum-=nums[l];
            ans=max(ans,sum);
            r++;
            l++;
        }
        return ans/k;
    }
};
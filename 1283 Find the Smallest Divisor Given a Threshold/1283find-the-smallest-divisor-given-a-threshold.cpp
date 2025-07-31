class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int M=0;
        for(int i=0;i<n;i++){
            M=max(nums[i],M);
        }
        int l=1,r=M;
        int ans=M;
        while(l<=r){
            int m=l+(r-l)/2;
            int sum=f(nums,m);
            if(sum<=threshold){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }

    int f(vector<int>& nums,int m){
        int sum=0;
        for(int num:nums){
            sum+=(num+m-1)/m;
        }
        return sum;
    }
};
class Solution {
public:
    bool canAllocate(vector<int> &nums,long long m,int k){
        long long pages=0;
        int count=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+pages>m){
                count++;
                pages=nums[i];
                if(count>k) return false;
            }
            else{
                pages+=nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
        long long sum=0;
        int largest=0;
        for(int x:nums){
            sum+=x;
            largest=max(largest,x);
        }
        long long l=largest,r=sum;
        long long ans=0;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(canAllocate(nums,m,k)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return (int)ans;
    }
};
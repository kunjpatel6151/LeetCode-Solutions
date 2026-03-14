class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n);
        long long mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx,(long long)nums[i]);
            pre[i]=gcd((long long)nums[i],mx);
        }
        sort(pre.begin(),pre.end());
        long long ans=0;
        int l=0,r=n-1;
        while(l<r){
            ans+=gcd(pre[l],pre[r]);
            l++;
            r--;
        }
        return ans;
    }
};
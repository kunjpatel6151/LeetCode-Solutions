class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int n=nums.size();
        deque<int> minq, maxq;
        int l=0,r=0;
        while(r<n){
            while(!minq.empty() && minq.back()>nums[r]){
                minq.pop_back();
            }
            while(!maxq.empty() && maxq.back()<nums[r]){
                maxq.pop_back();
            }
            minq.push_back(nums[r]);
            maxq.push_back(nums[r]);
            while(!minq.empty() && !maxq.empty() && (long long)(maxq.front()-minq.front())*(r-l+1)>k){
                if(nums[l]==minq.front()){
                    minq.pop_front();
                }
                if(nums[l]==maxq.front()){
                    maxq.pop_front();
                }
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};
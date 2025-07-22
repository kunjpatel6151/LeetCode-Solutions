class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int l=0,r=0;
        long long sum=0,ans=0;
        while(r<n){
            mp[nums[r]]++;
            sum+=nums[r];
            while(mp[nums[r]]>1){
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans=max(ans,sum);
            r++;
        }
        return (int)ans;
    }
};
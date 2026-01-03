class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l=0,r=0;
        long long sum=0;
        int n=nums.size();
        sum=0;
        int ans=n+1;
        while(r<n){
            mp[nums[r]]++;
            if(mp[nums[r]]==1){
                sum+=nums[r];
            }
            while(sum>=k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    sum-=nums[l];
                    mp.erase(nums[l]);
                }
                ans=min(r-l+1,ans);
                l++;
            }
            r++;
        }
        if(ans==(n+1)){
            return -1;
        }
        else{
            return ans;
        }
    }
};
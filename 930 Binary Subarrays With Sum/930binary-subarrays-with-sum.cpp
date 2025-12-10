class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> prefix(n);
        unordered_map<int,int> mp;
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(prefix[i]==goal){
                ans++;
            }
            if(mp.find(prefix[i]-goal)!=mp.end()){
                ans+=mp[prefix[i]-goal];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long count=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int x=nums[i]-i;
            mp[x]++;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            long long x=itr->second;
            if(x>1){
                count+=(x*(x-1))/2;
            }
        }
        long long ans=n*(n-1)/2 - count;
        return ans;
    }
};
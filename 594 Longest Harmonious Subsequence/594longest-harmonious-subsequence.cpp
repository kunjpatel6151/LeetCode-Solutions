class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0;
        auto itr=mp.begin();
        int k1,k2,v1,v2;
        k1= itr->first;
        v1= itr->second;
        itr++;
        while(itr!=mp.end()){
            k2= itr->first;
            v2= itr->second;
            if(abs(k1-k2)==1){
                ans=max(ans,v1+v2);
            }
            k1=k2;
            v1=v2;
            itr++;
        }
        return ans;
    }
};
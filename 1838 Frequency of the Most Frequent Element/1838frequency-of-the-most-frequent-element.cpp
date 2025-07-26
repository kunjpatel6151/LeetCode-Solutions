class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int ans=0;
        for(auto itr1=mp.rbegin();itr1!=mp.rend();itr1++){
           int k1=itr1->first;
           int v1=itr1->second;
           int val=k;
           int count=v1;
           auto itr2=itr1;
           itr2++;
           while(itr2!=mp.rend() && val>0){
                int k2=itr2->first;
                int v2=itr2->second;
                int d=k1-k2;
                long long cost=1LL*d*v2;
                if(cost>val){
                    int canTake=val/d;
                    count+=canTake;
                    val=0;
                }
                else{
                    count+=v2;
                    val-=cost;
                }
                itr2++;
           }
           ans=max(ans,count);
        }
        return ans;
        
    }
};
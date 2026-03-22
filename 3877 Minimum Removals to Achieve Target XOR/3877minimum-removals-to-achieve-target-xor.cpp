class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        int mid=n/2;
        unordered_map<int,int> mp1, mp2;
        vector<int> l(nums.begin(),nums.begin()+mid);
        vector<int> r(nums.begin()+mid,nums.end());

        int L=l.size();
        for(int k=0;k<(1<<L);k++){
            int x=0;
            int count=0;
            for(int i=0;i<L;i++){
                if(k & (1<<i)){
                    x ^= l[i];
                    count++;
                }
            }
            mp1[x]=max(mp1[x],count);
        }

        int R=r.size();
        for(int k=0;k<(1<<R);k++){
            int x=0;
            int count=0;
            for(int i=0;i<R;i++){
                if(k & (1<<i)){
                    x ^= r[i];
                    count++;
                }
            }
            mp2[x]=max(mp2[x],count);
        }

        int ans=-1;
        for(pair<int,int> p:mp1){
            int need=target ^ p.first;
            if(mp2.count(need)){
                ans=max(ans,mp2[need]+p.second);
            }
        }
        if(ans==-1) return -1;
        return n-ans;
    }
    
};
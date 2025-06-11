class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0){
            return false;
        }
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        bool flag=true;
        while(!mp.empty()){
            if(mp.size()<k){
                flag=false;
                break;
            }
            auto itr=mp.begin();
            int i=k;
            while(--i){
                int curr=itr->first;
                itr++;
                int next=itr->first;
                int d=next-curr;
                if(d>1){
                    flag=false;
                    break;
                }
                else{
                    mp[curr]--;
                    if(mp[curr]==0){
                        mp.erase(curr);
                    }
                }
            }
            if(!flag){
                break;
            }
            mp[itr->first]--;
            if(mp[itr->first]==0){
                mp.erase(itr->first);
            }
        }
        return flag;
    }
};
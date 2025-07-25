class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int P,N,Z;
        P=N=Z=0;
        for(pair<int,int> p:mp){
            if(p.first>0){
                P++;
            }
            else if(p.first<0){
                N++;
            }
            else{
                Z++;
            }
        }
        if(P==0 && Z==0){
            auto itr=mp.end();
            --itr;
            return itr->first;
        }
        else if(P==0){
            return 0;
        }
        else{
            int sum=0;
            for(pair<int,int> p:mp){
                if(p.first>0){
                    sum+=p.first;
                }
            }
            return sum;
        }
    }
};
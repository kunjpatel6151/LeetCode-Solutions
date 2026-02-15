class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int x:nums){
            mp1[x]++;
        }
        for(auto &p:mp1){
            mp2[p.second]++;
        }
        for(int x:nums){
            int freq=mp1[x];
            if(mp2[freq]==1){
                return x;
            }
        }
        return -1;
    }
};
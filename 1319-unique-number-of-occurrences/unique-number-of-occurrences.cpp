class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int x:arr){
            mp1[x]++;
        }
        for(pair<int,int> p:mp1){
            if(mp2.find(p.second)!=mp2.end()){
                return false;
            }
            mp2[p.second]=p.first;
        }
        return true;

    }
};
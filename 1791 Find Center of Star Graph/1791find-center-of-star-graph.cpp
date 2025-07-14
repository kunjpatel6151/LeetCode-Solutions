class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        for(pair<int,int> p:mp){
            if(p.second==mp.size()-1){
                return p.first;
            }
        }
        return -1;
    }
};
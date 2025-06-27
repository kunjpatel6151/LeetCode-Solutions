class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(matches[i][0])==mp.end()){
                mp[matches[i][0]]=0;
            }
            mp[matches[i][1]]++;
        }
        vector<vector<int>> ans;
        vector<int> a,b;
        for(pair<int,int> p:mp){
            if(p.second==0){
                a.push_back(p.first);
            }
            if(p.second==1){
                b.push_back(p.first);
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        
    }
};
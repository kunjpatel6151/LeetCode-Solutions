class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> mp;
        for(int x:bulbs){
            if(mp.find(x)==mp.end()){
                mp[x]=1;
            }
            else{
                mp[x]=1-mp[x];
            }
        }
        vector<int> ans;
        for(auto &p:mp){
            if(p.second==1){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
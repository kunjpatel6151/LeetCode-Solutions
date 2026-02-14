class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            if(words[i].size()<k) continue;
            string s=words[i].substr(0,k);
            mp[s]++;
        }
        int ans=0;
        for(auto &p:mp){
            if(p.second>=2){
                ans++;
            }
        }
        return ans;
    }
};
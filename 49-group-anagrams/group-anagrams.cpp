class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            vector<int> v(26,0);
            for(char c:s){
                int key=c-'a';
                v[key]++;
            }
            string h_key;
            for(int j=0;j<26;j++){
                char c='a'+j;
                string s1(v[j],c);
                h_key+=s1;
            }
            mp[h_key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &p:mp){
            result.push_back(p.second);
        }
        return result;
    }
};
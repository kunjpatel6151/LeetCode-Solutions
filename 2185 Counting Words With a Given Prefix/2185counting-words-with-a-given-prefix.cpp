class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size(),m=pref.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int k=words[i].size();
            if(k>=m){
                string str=words[i].substr(0,m);
                if(str==pref){
                    ans++;
                }
            }
        }
        return ans;
    }
};
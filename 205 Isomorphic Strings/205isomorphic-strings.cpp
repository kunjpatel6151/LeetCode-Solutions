class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp1,mp2;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(mp1.find(s[i])==mp1.end()){
                mp1[s[i]]=t[i];
            }
            if(mp2.find(t[i])==mp2.end()){
                mp2[t[i]]=s[i];
            }
        }
        string ans1,ans2;
        for(int i=0;i<n;i++){
            ans1+=mp1[s[i]];
            ans2+=mp2[t[i]];
        }
        return ans1==t && ans2==s;
    }
};
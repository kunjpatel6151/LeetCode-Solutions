class Solution {
public:
    int countGoodSubstrings(string s) {
        map<char,int> mp;
        int count=0;
        int n=s.size();
        int l=0,r=0;
        while(r<n){
            mp[s[r]]++;
            if(r-l+1==3){
                if(mp.size()==3){
                    count++;
                }
                mp[s[l]]--;
                if(mp[s[l]]<=0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return count;
    }
};
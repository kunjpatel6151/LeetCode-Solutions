class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3,-1);
        int l=0,r=0,ans=0;
        int n=s.size();
        while(r<n){
            v[s[r]-'a']=r;
            if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1){
                l=min(v[0],min(v[1],v[2]));
                ans+=l+1;
            }
            r++;
        }
        return ans;
    }
};
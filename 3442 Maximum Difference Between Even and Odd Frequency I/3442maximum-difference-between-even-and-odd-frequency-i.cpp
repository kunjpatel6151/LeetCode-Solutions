class Solution {
public:
    int maxDifference(string s) {
        int n=s.size();
        map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        int M=0,m=0;
        for(pair<char,int> p:mp){
            if(p.second%2==0){
                if(m==0){
                    m=p.second;
                }
                else{
                    m=min(m,p.second);
                }
            }
            else{
                M=max(M,p.second);
            }
        }
        return M-m;
    }
};
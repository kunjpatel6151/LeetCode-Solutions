class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<long long>()(((long long)p.first)<<32 | (unsigned int)p.second);
        }
    };
    int distinctPoints(string s, int k) {
        unordered_set<pair<int,int>, pair_hash> st;
        int n=s.size();
        vector<int> px(n+1,0);
        vector<int> py(n+1,0);
        for(int i=0;i<n;i++){
            char c=s[i];
            px[i+1]=px[i];
            py[i+1]=py[i];
            if(c=='U') px[i+1]++;
            if(c=='D') px[i+1]--;
            if(c=='L') py[i+1]--;
            if(c=='R') py[i+1]++;
        }
        int ox=px[n], oy=py[n];
        int l=0,r=k;
        while(r<=n){
            int x=ox-px[r]+px[l];
            int y=oy-py[r]+py[l];
            st.insert({x,y});
            l++;
            r++;
        }
        return st.size();
    }
};
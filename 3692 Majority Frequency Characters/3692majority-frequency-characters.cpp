class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> h(26,0);
        for(char c:s){
            int key=c-'a';
            h[key]++;
        }
        int m=0;
        for(int x:h){
            m=max(x,m);
        }
        vector<vector<char>> v(m+1);
        for(int i=0;i<26;i++){
            char c='a'+i;
            if(h[i]>0){
                v[h[i]].push_back(c);
            }
        }
        int size=0;
        for(int i=0;i<=m;i++){
           int n=v[i].size();
           if(n>size){
               size=n;
           } 
        }
        string ans;
        for(int i=m;i>=0;i--){
            int n=v[i].size();
            if(n==size){
                for(char c:v[i]){
                    ans+=c;
                }
                break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            int m=words[i].size();
            for(int j=i+1;j<n;j++){
                int k=words[j].size();
                if(k>=m){
                    string s1=words[j].substr(0,m);
                    string s2=words[j].substr(k-m,m);
                    if(s1==words[i] && s2==words[i]){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
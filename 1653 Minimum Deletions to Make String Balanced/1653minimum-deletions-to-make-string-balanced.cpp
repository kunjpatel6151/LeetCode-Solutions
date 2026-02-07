class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> prefix(n,0), sufix(n,0);
        if(s[0]=='b') prefix[0]=1;
        if(s[n-1]=='a') sufix[n-1]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='b') prefix[i]=prefix[i-1]+1;
            else prefix[i]=prefix[i-1];
            if(s[n-i-1]=='a') sufix[n-i-1]=sufix[n-i]+1;
            else sufix[n-i-1]=sufix[n-i];
        }
        int ans=n;
        for(int i=0;i<n;i++){
            ans=min(ans,prefix[i]+sufix[i]);
        }
        return ans-1;
    }
};
class Solution {
public:
    int titleToNumber(string columnTitle) {
        map<char,int> mp;
        char c='A';
        for(int i=1;i<=26;i++){
            mp[c]=i;
            c++;
        }
        long long mul=1;
        long long ans=0;
        int n=columnTitle.size();
        for(int i=n-1;i>=0;i--){
            char ch=columnTitle[i];
            ans+=mul*mp[ch];
            mul*=26;
        }
        return (int)ans;
    }
};
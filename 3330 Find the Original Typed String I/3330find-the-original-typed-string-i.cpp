class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        int ans=1;
        int l=0,r=0;
        while(l<n){
            while(r<n && word[l]==word[r]){
                r++;
            }
            ans+=(r-l-1);
            l=r;
        }
        return ans;
    }
};
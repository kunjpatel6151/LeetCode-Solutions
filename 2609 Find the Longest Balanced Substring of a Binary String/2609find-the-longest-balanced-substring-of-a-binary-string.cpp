class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n=s.size();
        int ans=0;
        int i=0;
        while(i<n){
            int zeros=0;
            int ones=0;
            while(i<n && s[i]=='0'){
                zeros++;
                i++;
            }
            while(i<n && s[i]=='1'){
                ones++;
                i++;
            }
            int count=2*min(zeros,ones);
            ans=max(count,ans);
        }
        return ans;
        
    }
};
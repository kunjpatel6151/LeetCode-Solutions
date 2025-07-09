class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l=0,r=0,ans=0;
        int n=s.size();
        int ones=0,zeros=0;
        while(r<n){
            if(s[r]=='0'){
                zeros++;
            }
            else{
                ones++;
            }
            while(zeros>k && ones>k){
                if(s[l]=='0'){
                    zeros--;
                }
                else{
                    ones--;
                }
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};
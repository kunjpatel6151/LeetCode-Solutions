class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(), m=t.size(),j=0,i,k=0;
        if(m<n) return false;
        bool b;
        for(i=0;i<n;i++){
            b=false;
            while(j<m){
                if(s[i]==t[j]){
                    b=true;
                    k++;
                    j++;
                    break;
                }
                j++;
            }
            if(b!=true){
                break;
            }
        }
        if(k!=n) return false;
        return b;
    }
};
class Solution {
public:
    int maxScore(string s) {
        int ones=0,zeros=0,n=s.size();
       
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        int m=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                zeros++;
            }
            else{
                ones--;
            }
            m=max(m,zeros+ones);
        }
        return m;
    }
};
class Solution {
public:
    string thousandSeparator(int n) {
        string s=to_string(n);
        int N=s.size();
        string ans="";
        int i=N;
        while(i>3){
            i-=3;
            ans="."+s.substr(i,3)+ans;
        }
        ans=s.substr(0,i)+ans;
        return ans;
    }
};
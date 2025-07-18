class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(char c:s){
            if(c>='a' && c<='z'){
                ans+=c;
            }
            else if(c=='*'){
                int n=ans.size();
                if(n>0){
                    ans=ans.substr(0,n-1);
                }
            }
            else if(c=='#'){
                ans+=ans;
            }
            else{
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};
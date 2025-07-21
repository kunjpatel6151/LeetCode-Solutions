class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3){
            return s;
        }
        string ans;
        char a,b,c;
        ans+=s[0];
        ans+=s[1];
        a=s[0];
        b=s[1];
        for(int i=2;i<s.size();i++){
            c=s[i];
            if(a==b && b==c){
                continue;
            }
            else{
                ans+=c;
                a=b;
                b=c;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string res="";
        string ans=countAndSay(n-1);
        int count=1;
        for(int i=1;i<ans.size();i++){
            if(ans[i-1]==ans[i]){
                count++;
            }
            else{
                res+=to_string(count);
                res+=ans[i-1];
                count=1;
            }
        }
        res+=to_string(count);
        res+=ans[ans.size()-1];
        return res;
    }
};
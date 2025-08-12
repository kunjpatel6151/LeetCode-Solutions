class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int ans=0;
        for(char c:s){
            if(c=='('){
                open++;
            }
            if(c==')'){
                open--;
            }
            ans=max(open,ans);
        }
        return ans;
    }
};
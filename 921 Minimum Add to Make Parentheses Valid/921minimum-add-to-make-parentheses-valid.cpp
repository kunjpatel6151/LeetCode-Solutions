class Solution {
public:
    int minAddToMakeValid(string s) {
        int close=0,open=0;
        for(char c:s){
            if(c=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }
                else{
                    close++;
                }
            }
        }
        return close+open;
    }
};
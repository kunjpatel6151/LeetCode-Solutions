class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('){
                if(st.empty()){
                    s[i]='?';
                }
                st.push(c);
            }
            else{
                st.pop();
                if(st.empty()){
                    s[i]='?';
                }
            }
        }
        string ans;
        for(char ch:s){
            if(ch!='?'){
                ans+=ch;
            }
        }
        return ans;
    }
};
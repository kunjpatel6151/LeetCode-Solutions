class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                long long y=stoll(st.top());
                st.pop();
                long long x=stoll(st.top());
                st.pop();
                if(tokens[i]=="+"){
                    st.push(to_string(x+y));
                }
                else if(tokens[i]=="-"){
                    st.push(to_string(x-y));
                }
                else if(tokens[i]=="*"){
                    st.push(to_string(x*y));
                }
                else{
                    st.push(to_string(x/y));
                }
            }
            else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};
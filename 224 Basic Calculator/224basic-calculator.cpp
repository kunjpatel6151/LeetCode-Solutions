class Solution {
public:
    int calculate(string s) {
        long long ans=0;
        int sign=1;
        int n=s.size();
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                int num=0;
                while(i<n && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                i--;
                ans+=num*sign;
                sign=1;
            }
            else if(s[i]=='('){
                st.push({ans,sign});
                ans=0;
                sign=1;
            }
            else if(s[i]==')'){
                ans=st.top().first+(st.top().second*ans);
                st.pop();
            }
            else if(s[i]=='-'){
                sign=-sign;
            }
        }
        return ans;
    }
};
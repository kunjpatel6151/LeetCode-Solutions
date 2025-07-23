class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        stack<pair<char,int>> st;
        vector<bool> visited(n,false);
        int ans=0;
        if(x>y){
            for(int i=0;i<n;i++){
                if(!st.empty() && st.top().first=='a' && s[i]=='b'){
                    visited[i]=true;
                    visited[st.top().second]=true;
                    ans+=x;
                    st.pop();
                }
                else{
                    st.push({s[i],i});
                }
            }
            while(!st.empty()){
                st.pop();
            }
            for(int i=0;i<n;i++){
                if(visited[i]){
                    continue;
                }
                if(!st.empty() && st.top().first=='b' && s[i]=='a'){
                    ans+=y;
                    st.pop();
                }
                else{
                    st.push({s[i],i});
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(!st.empty() && st.top().first=='b' && s[i]=='a'){
                    visited[i]=true;
                    visited[st.top().second]=true;
                    ans+=y;
                    st.pop();
                }
                else{
                    st.push({s[i],i});
                }
            }
            while(!st.empty()){
                st.pop();
            }
            for(int i=0;i<n;i++){
                if(visited[i]){
                    continue;
                }
                if(!st.empty() && st.top().first=='a' && s[i]=='b'){
                    ans+=x;
                    st.pop();
                }
                else{
                    st.push({s[i],i});
                }
            }
        }
        return ans;
    }
};
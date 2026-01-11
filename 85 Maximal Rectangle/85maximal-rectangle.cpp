class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> prefix(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            stack<pair<int,int>> st;
            for(int j=0;j<m;j++){
                int idx=j;
                if(matrix[i][j]=='1'){
                    prefix[j]+=1;
                }
                else{
                    prefix[j]=0;
                }
                if(st.empty() || st.top().second<=prefix[j]){
                    st.push({j,prefix[j]});
                }
                else{
                    while(!st.empty() && st.top().second>prefix[j]){
                        int index=st.top().first;
                        int height=st.top().second;
                        st.pop();
                        ans=max(ans,height*(j-index));
                        idx=index;
                    }
                    st.push({idx,prefix[j]});
                }
            }
            while(!st.empty()){
                int index=st.top().first;
                int height=st.top().second;
                st.pop();
                ans=max(ans,height*(m-index));
            }
        }
        return ans;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<pair<int,int>> st;
        for(int i=0;i<heights.size();i++){
            int idx = i;
            if(st.empty() || st.top().second<=heights[i]){
                st.push({i,heights[i]});
            }
            else{
                while(!st.empty() && st.top().second>=heights[i]){
                    auto [id, h] = st.top();
                    st.pop();
                    ans = max(ans, h * (i - id));
                    idx = id;  
                }
                st.push({idx,heights[i]});
            }
        }

        int n = heights.size();
        while(!st.empty()) {
            auto [id, h] = st.top();
            st.pop();
            ans = max(ans, h * (n - id));
        }
        return ans;
    }
};
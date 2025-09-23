class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            int curr = asteroids[i];
            bool add = true;

            while(!st.empty() && st.top() > 0 && curr < 0) {
                if(abs(st.top()) == abs(curr)) {
                    st.pop();
                    add = false;
                    break;
                }
                else if(abs(st.top()) > abs(curr)) {
                    add = false;
                    break;
                }
                else {
                    st.pop();
                }
            }

            if(add) {
                st.push(curr);
            }
        }

        vector<int> ans(st.size());
        for(int i = st.size() - 1; !st.empty(); i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};

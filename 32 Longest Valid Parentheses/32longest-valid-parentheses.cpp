class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> a;
        int n = s.size();
        if(n == 0) {
            return 0;
        }
        int maxLen = 0;
        a.push(-1);

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                a.push(i);
            }
            else {
                a.pop();
                if(a.empty()) {
                    a.push(i);
                } else {
                    maxLen = max(maxLen, i - a.top()); 
                }
            }
        }
        return maxLen;
    }
};

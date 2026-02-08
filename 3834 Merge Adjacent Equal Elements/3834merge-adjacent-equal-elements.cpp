class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        stack<long long> st;
        int i=0;
        while(i<n){
            if(st.empty() || st.top()!=nums[i]){
                st.push(nums[i]);
                i++;
            }
            else{
                long long t=st.top();
                st.pop();
                long long p=nums[i]+t;
                while(!st.empty() && st.top()==p){
                    p+=st.top();
                    st.pop();
                }
                st.push(p);
                i++;
            }
            
        }
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
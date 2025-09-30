class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nse[i]=n;
            }
            else if(arr[st.top()]<arr[i]){
                nse[i]=st.top();
            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nse[i]=n;
                }
                else{
                    nse[i]=st.top();
                }
            }
            st.push(i);
        }
        st = stack<int>();
        for(int i=0;i<n;i++){
            if(st.empty()){
                pse[i]=-1;
            }
            else if(arr[st.top()]<=arr[i]){
                pse[i]=st.top();
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    pse[i]=-1;
                }
                else{
                    pse[i]=st.top();
                }
            }
            st.push(i);
        }
        long long ans=0;
        long long MOD=1000000007;
        for(int i=0;i<n;i++){
            long long l=i-pse[i];
            long long r=nse[i]-i;
            ans+=(l*r*arr[i])%MOD;
            ans%=MOD;
        }
        return ans;
    }
};
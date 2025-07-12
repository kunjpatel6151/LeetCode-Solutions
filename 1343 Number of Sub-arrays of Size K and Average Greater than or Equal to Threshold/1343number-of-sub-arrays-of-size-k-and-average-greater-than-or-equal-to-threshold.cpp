class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int l=0,r=0;
        long long sum=0;
        int ans=0;
        while(r<n){
            sum+=arr[r];
            if(r-l+1>=k){
                if(sum/k>=threshold){
                    ans++;
                }
                sum-=arr[l];
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return ans;
    }
};
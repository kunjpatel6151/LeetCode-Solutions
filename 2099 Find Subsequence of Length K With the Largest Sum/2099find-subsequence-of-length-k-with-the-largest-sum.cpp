class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        pair<int,int> p[n];
        for(int i=0;i<n;i++){
            p[i]={nums[i],i};
        }
        sort(p,p+n);
        pair<int,int> P[k];
        int i=0,j=n-1;
        while(i<k){
            P[i]={p[j].second,p[j].first};
            j--;
            i++;
        }
        sort(P,P+k);
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=P[i].second;
        }
        return ans;
    }
};
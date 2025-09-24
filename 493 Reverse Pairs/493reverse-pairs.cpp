class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans= 0;
        solve(nums,ans,0,nums.size()-1);
        return ans;
    }

    void solve(vector<int>& nums, int &ans, int l, int r){
        if(l>=r){
            return;
        }
        int m=l+(r-l)/2;
        solve(nums,ans,l,m);
        solve(nums,ans,m+1,r);
        count(nums,ans,l,m,r);
    }

    void count(vector<int>& nums, int &ans, int l, int m, int r){
        int j=m+1;
        for(int i=l;i<=m;i++){
            while(j<=r && (long long)nums[i]> 2LL * nums[j]){
                j++;
            }
            ans+=(j-(m+1));
        }

        vector<int> temp;
        int i=l;
        j=m+1;
        while(i<=m && j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            } 
        }
        while(i<=m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=l;k<=r;k++){
            nums[k]=temp[k-l];
        }
    }
};
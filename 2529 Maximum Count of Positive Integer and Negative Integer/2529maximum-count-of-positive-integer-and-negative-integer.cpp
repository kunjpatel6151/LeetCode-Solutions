class Solution {
public:
    int binarysearch(vector<int> a, int t){
        int l=0,r=a.size()-1,ans=a.size();
        int m;
        while(l<=r){
            m=(l+r)/2;
            if(a[m]<t){
                l=m+1;
            }
            else{
                ans=m;
                r=m-1;
            }
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) {
        int nn=binarysearch(nums,0);
        int pn=nums.size() - binarysearch(nums,1);
        return max(nn,pn);
    }
};
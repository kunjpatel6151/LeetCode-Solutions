class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1,r=m*n;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int count=c(mid,m,n);
            if(count>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }

    int c(int mid,int m,int n){
        int count=0;
        for(int i=1;i<=m;i++){
            int temp=min(mid/i,n);
            if(temp==0){
                break;
            }
            count+=temp;
        }
        return count;
    }
};
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m>n/k) return -1;
        int M=0;
        for(int x:bloomDay){
            M=max(x,M);
        }
        int l=1,r=M;
        int ans=M;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canTake(bloomDay,mid,m,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }

    bool canTake(vector<int>& bloomDay,int mid,int m,int k){
        int count=0;
        int c=0;
        for(int x:bloomDay){
            if(x<=mid){
                c++;
            }
            else{
                c=0;
            }
            if(c>=k){
                count++;
                c-=k;
            }
        }
        if(count>=m){
            return true;
        }
        else{
            return false;
        }
    }
};
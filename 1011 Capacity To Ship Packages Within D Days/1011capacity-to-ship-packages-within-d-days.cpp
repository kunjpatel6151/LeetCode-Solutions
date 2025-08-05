class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int weight:weights){
            sum+=weight;
        }
        int l=1,r=sum;
        int ans=weights.size();
        while(l<=r){
            int m=l+(r-l)/2;
            if(canShipped(weights,m,days)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }

    bool canShipped(vector<int>& weights,int m,int days){
        int count=1;
        int sum=0;
        for(int weight:weights){
            if(weight>m){
                return false;
            }
            if(sum+weight<=m){
                sum+=weight;
            }
            else{
                sum=weight;
                count++;
            }
        }
        return days>=count;
    }
};
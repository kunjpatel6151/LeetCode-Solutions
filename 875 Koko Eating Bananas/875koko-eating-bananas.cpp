class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int M=0;
        for(int pile:piles){
            M=max(pile,M);
        }
        int l=1,r=M;
        int ans=M;
        while(l<=r){
            int m=l+(r-l)/2;
            if(canEat(piles,m,h)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }

    bool canEat(vector<int>& piles,int m,int h){
        long long sum=0;
        for(int pile:piles){
            sum+=(pile+m-1)/m;
        }
        if(sum>h){
            return false;
        }
        else{
            return true;
        }
    }
};
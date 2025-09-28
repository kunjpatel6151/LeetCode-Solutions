class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        int a,b;
        if(start<goal){
            a=goal;
            b=start;
        }
        else{
            a=start;
            b=goal;
        }
        while(a!=0){
            int lsb1=a & 1;
            int lsb2=b & 1;
            if(lsb1 ^ lsb2) ans++;
            a=a >>= 1;
            b=b >>= 1;
        }
        return ans;
    }
};
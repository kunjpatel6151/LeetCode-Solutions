class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10,0);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<10;i++){
            fact[i]=i*fact[i-1];
        }
        int N=n;
        int sum=0;
        while(N>0){
            int digit=N%10;
            sum+=fact[digit];
            N/=10;
        }
        vector<int> mp1(10,0);
        vector<int> mp2(10,0);
        N=n;
        
        while(N>0){
            int digit=N%10;
            mp1[digit]++;
            N/=10;
            
        }
        N=sum;
        
        while(N>0){
            int digit=N%10;
            mp2[digit]++;
            N/=10;
            
        }
        return mp1 == mp2;
    }
};
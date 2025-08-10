class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> h1(10,0);
        digit(n,h1);
        for(int i=0;i<=30;i++){
            vector<int> h2(10,0);
            int num=(int)pow(2,i);
            digit(num,h2);
            if(h1==h2){
                return true;
            }
        }
        return false;
    }

    void digit(int n,vector<int>& h){
        int num=n;
        while(num!=0){
            int digit=num%10;
            h[digit]++;
            num/=10;
        }
    }
};
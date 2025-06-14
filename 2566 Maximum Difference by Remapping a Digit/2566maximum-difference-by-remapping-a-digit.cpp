class Solution {
public:
    int minMaxDifference(int num) {
        int M=num,m=num;
        for(int i=0;i<10;i++){
            int n=num;
            int a=0,b=0;
            int mul=1;
            while(n!=0){
                int digit=n%10;
                if(digit==i){
                    a+=9*mul;
                    b+=0*mul;
                }
                else{
                    a+=digit*mul;
                    b+=digit*mul;
                }
                mul*=10;
                n/=10;
            }
            M=max(M,a);
            m=min(m,b);
        }
        return M-m;
    }
};
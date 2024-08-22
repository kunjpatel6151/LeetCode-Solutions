class Solution {
public:
    int addDigits(int num) {
        int sum,i,x;
        while(num>=10){
            sum=0;
            x=num;
            while(x!=0){
                i=x%10;
                sum=sum+i;
                x=x/10;
            }
            num=sum;
        }
        return num;
    }
};
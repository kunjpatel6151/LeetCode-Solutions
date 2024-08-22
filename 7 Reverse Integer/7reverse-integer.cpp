class Solution {
public:
    int reverse(int x) {
        int i,num=x,sum=0;
        while(num!=0){
            i=num%10;
            if (sum > INT_MAX/10 || (sum == INT_MAX/10 && i > 7)) {
                return 0;
            }
            if (sum < INT_MIN/10 || (sum == INT_MIN/10 && i < -8)) {
                return 0; 
            }
            sum=sum*10+i;
            num=num/10;
        }
        return sum;
    }
};
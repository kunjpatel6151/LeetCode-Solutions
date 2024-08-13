class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int NUM=x;
        int i,sum=0;
        while(x!=0){
            i=x%10;
            if(sum>(INT_MAX-i)/10){
                return false;
            }
            sum=sum*10+i;
            x=x/10;
        }
        if(NUM==sum){
            return true;
        }
        else{
            return false;
        }
    }
};
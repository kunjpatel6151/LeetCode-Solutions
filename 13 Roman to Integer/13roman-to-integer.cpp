class Solution {
public:
    int romanvalue(char c){
        if(c=='I'){
            return 1;
        }
        if(c=='V'){
            return 5;
        }
        if(c=='X'){
            return 10;
        }
        if(c=='L'){
            return 50;
        }
        if(c=='C'){
            return 100;
        }
        if(c=='D'){
            return 500;
        }
        if(c=='M'){
            return 1000;
        }
        return 0;        
    }
    int romanToInt(string s) {
        int sum=0;
        int r1,r2;
        for(int i=0;i<s.size();i++){
            r1=romanvalue(s[i]);
            if(i+1<s.size()){
                r2=romanvalue(s[i+1]);
                if(r1>=r2){
                    sum=sum+r1;
                }
                else{
                    sum=sum+(r2-r1);
                    i++;
                }
            }
            else{
                sum=sum+r1;
            }
        }
        return sum;
    }
};
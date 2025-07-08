class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        long long num1=0;
        for(char c:firstWord){
            int digit=c-'a';
            num1=num1*10+digit;
        }
        long long num2=0;
        for(char c:secondWord){
            int digit=c-'a';
            num2=num2*10+digit;
        }
        long long num3=0;
        for(char c:targetWord){
            int digit=c-'a';
            num3=num3*10+digit;
        }
        long long ans=num1+num2;
        return ans==num3;
    }
};
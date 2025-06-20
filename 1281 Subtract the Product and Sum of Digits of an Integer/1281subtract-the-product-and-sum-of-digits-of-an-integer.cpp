class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digits;
        int num=n;
        while(num!=0){
            int digit=num%10;
            num/=10;
            digits.push_back(digit);
        }
        long long product=1;
        long long sum=0;
        for(int i=0;i<digits.size();i++){
            product*=digits[i];
            sum+=digits[i];
        }
        long long ans=product-sum;
        return (int)ans;
        
    }
};
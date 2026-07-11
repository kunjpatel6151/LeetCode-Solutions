class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1=INT_MAX;
        int num2=INT_MAX;
        for(int x:nums){
            if(num1>=x){
                num1=x;
            }
            else if(num2>=x){
                num2=x;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
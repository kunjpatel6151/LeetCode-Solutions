class Solution {
public:
    static bool cmp(int a, int b){
        string num1=to_string(a);
        string num2=to_string(b);
        if(num1+num2 > num2+num1){
            return true;
        }
        else{
            return false;
        }
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        if(nums[0]==0){
            return "0";
        }
        string ans;
        for(int x:nums){
            ans+=to_string(x);
        }
        return ans;
    }
};
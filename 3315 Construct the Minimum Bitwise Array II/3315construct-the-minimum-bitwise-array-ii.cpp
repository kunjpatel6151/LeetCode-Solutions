class Solution {
public:
    int countBits(int x){
        int count=0;
        while(x>0){
            count++;
            x >>= 1;
        }
        return count;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int x:nums){
            if(x==2){
                ans.push_back(-1);
                continue;
            }
            int n=countBits(x);
            for(int pos=n-1;pos>=0;pos--){
                int val = x & ~(1 << pos);
                if( (val | (val + 1)) == x ){
                    ans.push_back(val);
                    break;
                }
            }
        }
        return ans;
    }
};
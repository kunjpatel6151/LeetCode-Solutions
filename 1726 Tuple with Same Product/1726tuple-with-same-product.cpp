class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<4){
            return 0;
        }
        map<int,int> mp;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product=nums[i]*nums[j];
                mp[product]++;
            }
        }

        for(auto& p:mp){
            int f=p.second;
            if(f>1){
                count+=((f*(f-1))/2)*8;
            }
        }
        return count;

    }
};
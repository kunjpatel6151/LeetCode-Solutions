class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(s.size()<3){
                s.insert(nums[i]);
            }
            else{
                if(s.count(nums[i])==0){
                    auto itr=s.begin();
                    int x= *itr;
                    if(nums[i]>x){
                        s.insert(nums[i]);
                        s.erase(itr);
                    }
                }
            }
        }
        int ans;
        if(s.size()<3){
            auto itr=s.begin();
            while(itr!=s.end()){
                ans= *itr;
                itr++;
            }
        }
        else{
            auto itr=s.begin();
            ans= *itr;
        }
        return ans;
    }
};
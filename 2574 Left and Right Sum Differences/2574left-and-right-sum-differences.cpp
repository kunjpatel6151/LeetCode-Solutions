class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        vector<int> ans;
        int leftsum=0;
        int rightsum=sum;
        for(int x:nums){
            rightsum-=x;
            ans.push_back(abs(leftsum-rightsum));
            leftsum+=x;
        }
        return ans;
    }
};
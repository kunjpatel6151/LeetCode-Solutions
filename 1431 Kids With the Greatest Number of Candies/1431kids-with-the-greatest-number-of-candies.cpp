class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> ans;
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            m=max(m,candies[i]);
        }
        for(int i=0;i<n;i++){
            int a=candies[i]+extraCandies;
            if(a>=m){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
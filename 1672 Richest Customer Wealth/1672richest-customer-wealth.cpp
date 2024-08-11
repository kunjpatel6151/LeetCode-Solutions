class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=0,sum;
        for(int i=0;i<accounts.size();i++){
            sum=0;
            for(int j=0;j<accounts[0].size();j++){
                sum=sum+accounts[i][j];
            }
            m=max(m,sum);
        }
        return m;
    }
};
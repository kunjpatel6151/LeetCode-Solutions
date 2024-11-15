class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> a(201,0);
        for(int x:nums){
            a[x+100]=a[x+100]+1;
        }
        vector<int> ans;
        for(int i=1;i<=200;i++){
            for(int j=200;j>=0;j--){
                if(a[j]==i){
                    for(int k=0;k<i;k++){
                        ans.push_back(j-100);
                    }
                }
            }
        }
        return ans;
    }
};
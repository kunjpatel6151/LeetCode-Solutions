class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int m=INT_MAX;
        int M=INT_MIN;
        for(int i=0;i<n;i++){
            m=min(m,nums[i]);
            M=max(M,nums[i]);
        }
        vector<bool> visited(M+1,false);
        for(int i=0;i<n;i++){
            visited[nums[i]]=true;
        }
        vector<int> ans;
        for(int i=m;i<=M;i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
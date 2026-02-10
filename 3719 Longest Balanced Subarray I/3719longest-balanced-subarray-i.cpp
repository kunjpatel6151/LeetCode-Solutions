class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpe;
            unordered_map<int,int> mpo;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    mpe[nums[j]]++;
                }
                else{
                    mpo[nums[j]]++;
                }
                if(mpe.size()==mpo.size()){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
        
        
    }
};
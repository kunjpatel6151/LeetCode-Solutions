class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        if(k==0) return nums;
        queue<int> q;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                q.push(nums[i]);
            }
        }
        if(q.empty()){
            return nums;
        }
        while(k--){
            int f=q.front();
            q.pop();
            q.push(f);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                int f=q.front();
                q.pop();
                nums[i]=f;
            }
        }
        return nums;
    }
};
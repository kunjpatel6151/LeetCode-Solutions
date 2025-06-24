class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> pos;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                pos.push_back(i);
            }
        }
        set<int> s;
        for(int i=0;i<pos.size();i++){
            int l=pos[i]-k;
            int r=pos[i]+k;
            if(l<0){
                l=0;
            }
            if(r>n){
                r=n-1;
            }
            while(l<=r){
                s.insert(l);
                l++;
            }
        }
        s.erase(n);
        vector<int> ans;
        for(int x:s){
            ans.push_back(x);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        for(int x:nums1){
            s1.insert(x);
        }
        for(int x:nums2){
            s2.insert(x);
        }
        vector<vector<int>> ans;
        vector<int> v1,v2;
        for(int x:s1){
            if(!s2.count(x)){
                v1.push_back(x);
            }
        }
        for(int x:s2){
            if(!s1.count(x)){
                v2.push_back(x);
            }
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
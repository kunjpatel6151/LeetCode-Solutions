class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    map<int,int> mp1;
    map<int,int> mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)  : nums1(nums1), nums2(nums2) {
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp2[nums2[index]]--;
        nums2[index]+=val;
        mp2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(pair<int,int> p:mp1){
            ans+=p.second*mp2[tot-p.first];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
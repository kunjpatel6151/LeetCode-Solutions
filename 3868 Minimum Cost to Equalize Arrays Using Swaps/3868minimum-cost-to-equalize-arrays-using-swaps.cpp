class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        unordered_map<int,int> mp3;
        for(int i=0;i<n;i++){
            mp1[nums1[i]]++;
            mp2[nums2[i]]++;
            mp3[nums1[i]]++;
            mp3[nums2[i]]++;
        }
        int ans=0;
        for(pair<int,int> p:mp3){
            if(p.second%2!=0){
                return -1;
            }
            int val1=mp1[p.first];
            int val2=mp2[p.first];
            ans+=abs((val1-val2)/2);
        }
        return ans/2;
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0;
        map<int,int> mp;
        int ans=0,count=0;
        while(r<n){
            mp[fruits[r]]++;
            count++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                count--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            ans=max(ans,count);
            r++;
        }
        return ans;
    }
};
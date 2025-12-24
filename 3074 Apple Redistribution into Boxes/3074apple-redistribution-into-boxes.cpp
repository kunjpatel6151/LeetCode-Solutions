class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<>());
        int sum=0;
        for(int x:apple){
            sum+=x;
        }
        int ans=0;
        for(int x:capacity){
            sum-=x;
            ans++;
            if(sum<=0){
                break;
            }
        }
        return ans;
    }
};
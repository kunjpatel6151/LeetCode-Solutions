class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if(words[startIndex]==target) return 0;
        int n=words.size();
        int r=startIndex+1;
        int ans=INT_MAX;
        while(r!=startIndex){
            if(words[r]==target){
                int diff=abs(r-startIndex);
                ans=min(ans,min(diff,n-diff));
            }
            r=(r+1)%n;
        }

        if(ans==INT_MAX) return -1;
        return ans;


    }
};
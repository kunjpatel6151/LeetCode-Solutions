class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int ans=sum;
        int i=k-1;
        for(int j=n-1;i>=0;j--){
            sum=sum+cardPoints[j]-cardPoints[i];
            ans=max(ans,sum);
            i--;
        }
        return ans;
    }
};
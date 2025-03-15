class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        int n=candies.size();
        int low=1,high=1;
        for(int i=0;i<n;i++){
            sum+=candies[i];
            high=max(high,candies[i]);
        }
        if(sum<k){
            return 0;
        }
        if(sum==k){
            return 1;
        }
        int middle;
        while(low<=high){
            middle=(low+high)/2;
            long long count=0;
            for(int i=0;i<n;i++){
                count+=(candies[i]/middle);
            }
            if(count>=k){
                low=middle+1;
            }
            else{
                high=middle-1;
            }
        }
        return high;
        
    }
};
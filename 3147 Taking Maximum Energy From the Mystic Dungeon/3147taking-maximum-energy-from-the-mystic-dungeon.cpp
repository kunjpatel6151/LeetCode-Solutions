class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int m=INT_MIN;
        int n=energy.size();
        for(int i=0;i<k;i++){
            int sum=0;
            for(int j=n-i-1;j>=0;j-=k){
                sum+=energy[j];
                m=max(sum,m);
            }
        }
        return m;
        
    }
};
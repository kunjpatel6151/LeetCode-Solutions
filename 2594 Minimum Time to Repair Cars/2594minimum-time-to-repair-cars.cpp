class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long l=1,h=(long long)*max_element(ranks.begin(),ranks.end())*cars*cars;
        while(l<=h){
            long long m=(l+h)/2;
            long long count=0;
            for(int i=0;i<n;i++){
                count+=sqrt(m/ranks[i]);
            }
            if(count>=cars){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int count=0;
        vector<bool> allocated(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!allocated[j]){
                    if(baskets[j]>=fruits[i]){
                        allocated[j]=true;
                        count++;
                        break;
                    }
                }
            }
        }
        return n-count;
    }
};
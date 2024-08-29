class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size(),h=0;
        sort(citations.begin(),citations.end());
        while(n--){
            if(citations[n]>h){
                h++;
            }
            else{
                break;
            }
        }
        return h;
    }
};
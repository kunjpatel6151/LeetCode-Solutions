class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int l=0,r=0,count=0;
        while(l<n){
            if((r-l)==0){
                r++;
            }
            else{
                if(colors[(r-1)%n]!=colors[r%n]){
                    r++;
                    if((r-l)==k){
                        count++;
                        l++;
                    }
                }
                else{
                    l=r;
                    r++;
                }
            }
        }
        return count;

    }
};
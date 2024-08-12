class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count=0,i=0;
        int n=colors.size();
        while(i<n){
            if(i==0){
                if(colors[0]!=colors[1] && colors[0]!=colors[n-1]){
                    count++;
                }
            }
            else if(i==n-1){
                if(colors[n-1]!=colors[0] && colors[n-1]!=colors[n-2]){
                    count++;
                }
            }
            else if(colors[i]!=colors[i-1] && colors[i]!=colors[i+1]){
                count++;
            }
            i++;
            
        }
        return count;
    }
};
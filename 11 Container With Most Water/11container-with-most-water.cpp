class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),i=0,j=n-1;
        int m=0,M;
        while(i<=j){
            M=min(height[i],height[j])*(j-i);
            m=max(m,M);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return m;
    }
};
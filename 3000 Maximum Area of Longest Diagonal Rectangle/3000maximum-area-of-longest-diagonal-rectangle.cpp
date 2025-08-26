class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        vector<double> diagonal(n);
        double m=0;
        for(int i=0;i<n;i++){
            diagonal[i]=sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]));
            m=max(m,diagonal[i]);
        }
        int area=0;
        for(int i=0;i<n;i++){
            if(m==diagonal[i]){
                area=max(area,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return area;
    }
};
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double tarea=0;
        double ly=squares[0][1];
        double hy=squares[0][1]+squares[0][2];
        for(int i=0;i<squares.size();i++){
            ly=min(ly,(double)squares[i][1]);
            hy=max(hy,(double)squares[i][1]+squares[i][2]);
            tarea+=(double)squares[i][2]*squares[i][2];
        }
        double l=ly,r=hy;
        while(r-l>1e-5){
            double m=(l+r)/2;
            double area=0;
            for(int i=0;i<squares.size();i++){
                double bsq=squares[i][1];
                double asq=squares[i][1]+squares[i][2];
                if(asq>m){
                    double height=asq-max(bsq,m);
                    area+=height*squares[i][2];
                }
            }
            if(area>tarea/2){
                l=m;
            }
            else{
                r=m;
            }
        }
        return l;
    }
};
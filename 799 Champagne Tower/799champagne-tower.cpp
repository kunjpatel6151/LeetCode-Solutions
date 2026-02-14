class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured==0) return 0;
        vector<vector<pair<double,double>>> glass;
        for(int i=0;i<100;i++){
            vector<pair<double,double>> v(i+1);
            if(i==0){
                if(poured>=1){
                    double val=(double)(poured-1)/2;
                    v[0]={1,val};
                }
                else{
                    v[0]={poured,0};
                }
            }
            else{
                int N=glass[i-1].size();
                if(glass[i-1][0].second>=1){
                    double val=(glass[i-1][0].second-1)/2;
                    v[0]={1,val};
                }
                else{
                    v[0]={glass[i-1][0].second,0};
                }
                if(glass[i-1][N-1].second>=1){
                    double val=(glass[i-1][N-1].second-1)/2;
                    v[i]={1,val};
                }
                else{
                    v[i]={glass[i-1][N-1].second,0};
                }
                for(int j=1;j<i;j++){
                    double x=glass[i-1][j-1].second+glass[i-1][j].second;
                    if(x>=1){
                        double val=(x-1)/2;
                        v[j]={1,val};
                    }
                    else{
                        v[j]={x,0};
                    }

                }
            }
            glass.push_back(v);
        }
        return glass[query_row][query_glass].first;
    }
};
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> a;
        if(n==1){
            a.push_back(0);
        }
        else{
            if(n%2==0){
                int i=1;
                while(i!=((n+2)/2)){
                    a.push_back(i);
                    a.push_back(-i);
                    i++;
                }
            }
            else{
                int i=1;
                while(i!=((n+2)/2)){
                    a.push_back(i);
                    a.push_back(-i);
                    i++;
                }
                a.push_back(0);
            }
        }
        return a;
    }
};
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long sum=mass;
        bool flag=true;
        for(int i=0;i<asteroids.size();i++){
            if(sum<asteroids[i]){
                flag=false;
                break;
            }
            sum+=asteroids[i];
        }
        return flag;
    }
};